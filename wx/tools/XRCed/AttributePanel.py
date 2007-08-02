# Name:         AttributePanel.py
# Purpose:      View components for editing attributes
# Author:       Roman Rolinsky <rolinsky@mema.ucl.ac.be>
# Created:      17.06.2007
# RCS-ID:       $Id$

import string
import wx
import wx.lib.buttons as buttons
from globals import *
import params
import component
import undo
import images


labelSize = (80,-1)

# Panel class is the attribute panel containing class name, XRC ID and
# a notebook with particular pages.

class ScrolledPage(wx.ScrolledWindow):
    def __init__(self, parent):
        wx.ScrolledWindow.__init__(self, parent)
        self.topSizer = wx.BoxSizer(wx.VERTICAL)
        self.SetSizer(self.topSizer)
        self.panel = None
        self.SetScrollRate(1, 1)

    def Reset(self):
        if self.panel:
            self.panel.Destroy()
            self.panel = None

    def SetPanel(self, panel):
        self.Reset()
        self.panel = panel
        self.topSizer.Add(panel, 0, wx.ALL | wx.EXPAND, 2)
        self.Layout()

class Panel(wx.Panel):
    '''Attribute panel main class.'''
    def __init__(self, parent):
        wx.Panel.__init__(self, parent)

        # Set common sizes
        params.InitParams(self)

        topSizer = wx.BoxSizer(wx.VERTICAL)
        pinSizer = wx.BoxSizer(wx.HORIZONTAL)
        sizer = wx.FlexGridSizer(2, 2, 1, 5)
        self.labelClass = wx.StaticText(self, -1, 'class:')
        self.controlClass = params.ParamText(self, 'class', textWidth=200)
        sizer.AddMany([ (self.labelClass, 0, wx.ALIGN_CENTER_VERTICAL),
                        (self.controlClass, 0, wx.LEFT, 5) ])
        self.labelName = wx.StaticText(self, -1, 'name:')
        self.controlName = params.ParamText(self, 'name', textWidth=200)
        sizer.AddMany([ (self.labelName, 0, wx.ALIGN_CENTER_VERTICAL),
                        (self.controlName, 0, wx.LEFT, 5) ])
        pinSizer.Add(sizer, 0, wx.ALL, 5)
        pinSizer.Add((0, 0), 1)
        self.pinButton = buttons.GenBitmapToggleButton(
            self, bitmap=images.getToolPinBitmap(),
            style=wx.BORDER_NONE)
        self.pinButton.SetBitmapSelected(images.getToolPinDownBitmap())
        self.pinButton.SetToggle(g.conf.panelPinState)
        self.pinButton.SetToolTipString('Sticky page selection')
        # No highlighting please
        self.pinButton.GetBackgroundBrush = lambda dc: None
        pinSizer.Add(self.pinButton)
        topSizer.Add(pinSizer, 0, wx.EXPAND)
        self.sizer = sizer

        self.nb = wx.Notebook(self, -1)
        if wx.Platform == '__WXGTK__':
            # Redefine AddPage on GTK to fix when page added is not shown
            _oldAddPage = wx.Notebook.AddPage
            def _newAddPage(self, page, label):
                _oldAddPage(self, page, label)
                page.Show(True)
            wx.Notebook.AddPage = _newAddPage

        # Create scrolled windows for panels
        self.pageA = ScrolledPage(self.nb)
        self.nb.AddPage(self.pageA, 'Attributes')
        # Style page
        self.pageStyle = ScrolledPage(self.nb)
        self.pageStyle.Hide()
        # Extra style page
        self.pageExStyle = ScrolledPage(self.nb)
        self.pageExStyle.Hide()
        # Window attributes page
        self.pageWA = ScrolledPage(self.nb)
        self.pageWA.Hide()
        # Implicit attributes page
        self.pageIA = ScrolledPage(self.nb)
        self.pageIA.Hide()
        # Code page
        self.pageCode = ScrolledPage(self.nb)
        self.pageCode.Hide()

        topSizer.Add(self.nb, 1, wx.EXPAND)
        self.SetSizer(topSizer)

        self.undo = None        # pending undo object

    def SetData(self, container, comp, node):
        oldLabel = self.nb.GetPageText(self.nb.GetSelection())
        self.nb.SetSelection(0)
        map(self.nb.RemovePage, range(self.nb.GetPageCount()-1, 0, -1))
        
        self.comp = comp
        panels = []
        # Class and name
        if comp.klass != 'root':
            self.labelClass.Show()
            self.controlClass.Show()
            self.controlClass.SetValue(node.getAttribute('class'))
        else:
            self.labelClass.Hide()
            self.controlClass.Hide()
        self.labelName.Show(comp.hasName)
        self.controlName.Show(comp.hasName)
        if comp.hasName:
            self.controlName.SetValue(node.getAttribute('name'))

        self.Layout()           # update after hiding/showing

        attributes = comp.attributes
        panel = AttributePanel(self.pageA, attributes, comp.params, comp.renameDict)
        panels.append(panel)
        self.pageA.SetPanel(panel)
        self.SetValues(panel, node)

        if comp.windowAttributes:
            panel = AttributePanel(self.pageWA, comp.windowAttributes,
                                   rename_dict = params.WARenameDict)
            panels.append(panel)
            self.pageWA.SetPanel(panel)
            self.nb.AddPage(self.pageWA, "Look'n'Feel")
            self.SetValues(panel, node)

        if comp.styles or comp.genericStyles:
            # Create style page
            panel = params.StylePanel(self.pageStyle, comp.styles, comp.genericStyles)
            panels.append(panel)
            self.pageStyle.SetPanel(panel)
            self.nb.AddPage(self.pageStyle, 'Style')
            self.SetStyleValues(panel, comp.getAttribute(node, 'style'))

        if comp.exStyles or comp.genericExStyles:
            # Create extra style page
            panel = params.StylePanel(self.pageExStyle, comp.exStyles + comp.genericExStyles)
            panels.append(panel)
            self.pageExStyle.SetPanel(panel)
            self.nb.AddPage(self.pageExStyle, 'ExStyle')
            self.SetStyleValues(panel, comp.getAttribute(node, 'exstyle'))

        # Additional panel for hidden node
        if container and container.requireImplicit(node) and container.implicitAttributes:
            panel = AttributePanel(self.pageIA, 
                                   container.implicitAttributes, 
                                   container.implicitParams,
                                   container.implicitRenameDict)
            panels.append(panel)
            self.pageIA.SetPanel(panel)
            self.nb.AddPage(self.pageIA, container.implicitPageName)
            self.SetValues(panel, node.parentNode)

        if comp.events:
            # Create code page
            panel = CodePanel(self.pageCode, comp.events)
            panels.append(panel)
            self.pageCode.SetPanel(panel)
            self.nb.AddPage(self.pageCode, 'Code')
            self.SetCodeValues(panel, comp.getAttribute(node, 'XRCED'))

        # Select old page if possible and pin is down
        if g.conf.panelPinState:
            for i in range(1, self.nb.GetPageCount()):
                if oldLabel == self.nb.GetPageText(i):
                    self.nb.SetSelection(i)
                    break

        return panels
        
    def Clear(self):
        self.comp = None
        self.nb.SetSelection(0)
        map(self.nb.RemovePage, range(self.nb.GetPageCount()-1, 0, -1))
        self.pageA.Reset()
        self.undo = None

        self.controlClass.SetValue('')
        self.labelName.Show(False)
        self.controlName.Show(False)

        self.Layout()

    def GetActivePanel(self):
        if self.nb.GetSelection() >= 0:
            return self.nb.GetPage(self.nb.GetSelection()).panel
        else:
            return None

    # Set data for a panel
    def SetValues(self, panel, node):
        panel.node = node
        for a,w in panel.controls:
            value = self.comp.getAttribute(node, a)
            w.SetValue(value)

    # Set data for a style panel
    def SetStyleValues(self, panel, style):
        panel.style = style
        styles = map(string.strip, style.split('|')) # to list
        for s,w in panel.controls:
            w.SetValue(s in styles)

    # Set data for a style panel
    def SetCodeValues(self, panel, data):
        panel.SetValues([('XRCED', data)])


################################################################################

class AttributePanel(wx.Panel):
    '''Particular attribute panel, normally inside a notebook.'''
    def __init__(self, parent, attributes, param_dict={}, rename_dict={}):
        wx.Panel.__init__(self, parent, -1)
        self.bg = self.GetBackgroundColour()
        self.bg2 = wx.Colour(self.bg.Red()-15, self.bg.Green()-15, self.bg.Blue()-15)
        self.controls = []
        sizer = wx.FlexGridSizer(len(attributes), 2, 0, 0)
        sizer.AddGrowableCol(1, 0)
        for a in attributes:
            # Find good control class
            paramClass = param_dict.get(a, params.paramDict.get(a, params.ParamText))
            sParam = rename_dict.get(a, a)
            control = paramClass(self, sParam)
            labelPanel = wx.Panel(self, -1)
            labelSizer = wx.BoxSizer()
            labelPanel.SetSizer(labelSizer)
            if control.isCheck: # checkbox-like control
                label = wx.StaticText(labelPanel, -1, control.defaultString)
                sizer.AddMany([ (control, 1, wx.EXPAND),
                                (labelPanel, 1, wx.EXPAND) ])
                labelSizer.Add(label, 0, wx.ALIGN_CENTER_VERTICAL | wx.LEFT, 2)
            else:
                if sParam:
                    label = wx.StaticText(labelPanel, -1, sParam, size=labelSize)
                    sizer.AddMany([ (labelPanel, 1, wx.EXPAND),
                                    (control, 1, wx.EXPAND) ])
                else:           # for node-level params
                    label = wx.StaticText(labelPanel, -1, '')
                    sizer.Add(control, 1, wx.LEFT, 20)
                labelSizer.Add(label, 0, wx.ALIGN_CENTER_VERTICAL | wx.LEFT, 20)
            if len(self.controls) % 2:
                label.SetBackgroundColour(self.bg2)
                labelPanel.SetBackgroundColour(self.bg2)
                control.SetBackgroundColour(self.bg2)
            self.controls.append((a, control))
        self.SetSizerAndFit(sizer)

    def GetValues(self):
        '''Generic method used for creating XML and for other operations.'''
        return [(a,c.GetValue()) for a,c in self.controls]
        
    def SetValues(self, values):
        '''Generic method used for undo.'''
        for ac,a2v in zip(self.controls, values):
            a,c = ac
            v = a2v[1]
            c.SetValue(v)

################################################################################

class CodePanel(wx.Panel):
    ID_BUTTON_DEL = wx.NewId()
    ID_COMBO_EVENT = wx.NewId()
    ART_REMOVE = 'ART_REMOVE'
    
    '''Code generation panel.'''
    def __init__(self, parent, events):
        wx.Panel.__init__(self, parent, -1)
        self.SetFont(g.smallerFont())
        self.events = events
        self.checks = []
        self.node = None
        topSizer = wx.BoxSizer(wx.HORIZONTAL)
        # Events on the left
        leftSizer = wx.BoxSizer(wx.VERTICAL)
        sizer = wx.GridSizer(len(events), 1, 0, 5)
        label = wx.StaticText(self, label='Events')
        label.SetFont(g.labelFont())
        sizer.Add(label, 0, wx.LEFT, 20)
        for ev in events:
            check = wx.CheckBox(self, label=ev)
            sizer.Add(check)
            self.checks.append((ev, check))
        leftSizer.Add(sizer)
        # Additional comboboxes
        self.extra = []
        self.eventSizer = wx.FlexGridSizer(1, 2, 0, 0)
        leftSizer.Add(self.eventSizer)
        topSizer.Add(leftSizer)
        # Right sizer
        rightSizer = wx.BoxSizer(wx.VERTICAL)
        rightSizer.Add((0, 10))
        if g.Presenter.container is not component.Manager.rootComponent:
            self.checkVar = wx.CheckBox(self, label='assign variable')
            rightSizer.Add(self.checkVar, 0, wx.LEFT, 20)
        else:
            self.checkVar = None
        topSizer.Add(rightSizer)
        # Cach all checkbox events
        self.Bind(wx.EVT_CHECKBOX, self.OnCheck)
        self.SetSizerAndFit(topSizer)
        # Extra combos and buttons
        self.Bind(wx.EVT_BUTTON, self.OnButtonDel, id=self.ID_BUTTON_DEL)
        self.Bind(wx.EVT_COMBOBOX, self.OnComboEvent, id=self.ID_COMBO_EVENT)
        self.Bind(wx.EVT_TEXT, self.OnComboText, id=self.ID_COMBO_EVENT)

    def GetValues(self):
        events = []
        for s,check in self.checks:
            if check.IsChecked(): events.append(s)
        # Encode data to a dictionary and the cPicke it
        data = {}
        for btn,combo in self.extra[:-1]:
            events.append(combo.GetValue())
        if events: data['events'] = '|'.join(events)
        if self.checkVar and self.checkVar.GetValue(): data['assign_var'] = '1'
        if data:
            return [('XRCED', data)]
        else:
            return []

    def AddExtraEvent(self, event=''):
        btn = wx.BitmapButton(self, self.ID_BUTTON_DEL,
                              bitmap=wx.ArtProvider.GetBitmap(self.ART_REMOVE, wx.ART_BUTTON),
                              size=(24,24))
        if not event: btn.Disable()
        self.eventSizer.Add(btn, 0, wx.ALIGN_CENTRE_VERTICAL)
        combo = wx.ComboBox(self, self.ID_COMBO_EVENT, value=event, choices=component.Component.genericEvents)
        btn.combo = combo
        self.eventSizer.Add(combo)
        self.extra.append((btn, combo))

    def SetValues(self, values):
        data = values[0][1]
        events = data.get('events', '').split('|')
        if events == ['']: events = []
        for ev,check in self.checks:
            check.SetValue(ev in events)
        # Add comboboxes for other events
        for ev in events:
            if ev not in self.events:
                self.AddExtraEvent(ev)
        # Empty combo box for adding new events
        self.AddExtraEvent()
        self.Fit()
        self.SetMinSize(self.GetBestSize())
        if self.checkVar:
            self.checkVar.SetValue(int(data.get('assign_var', '0')))

    def OnCheck(self, evt):
        g.Presenter.setApplied(False)

    def OnButtonDel(self, evt):
        btn = evt.GetEventObject()
        self.extra.remove((btn, btn.combo))
        btn.combo.Destroy()
        btn.Destroy()
        self.Fit()
        self.SetMinSize(self.GetBestSize())
        g.Presenter.setApplied(False)

    def OnComboText(self, evt):
        if evt.GetEventObject() == self.extra[-1][1]:
            self.extra[-1][0].Enable()
            self.AddExtraEvent()
            self.Fit()
            self.SetMinSize(self.GetBestSize())
        g.Presenter.setApplied(False)

    def OnComboEvent(self, evt):
        if evt.GetEventObject() == self.extra[-1][1]:
            self.extra[-1][0].Enable()
            self.AddExtraEvent()
            self.Fit()
            self.SetMinSize(self.GetBestSize())
        g.Presenter.setApplied(False)
            
