/*
 * FILE : gtk/utils.cpp
 * 
 * This file was automatically generated by :
 * Simplified Wrapper and Interface Generator (SWIG)
 * Version 1.1 (Patch 5)
 * 
 * Portions Copyright (c) 1995-1998
 * The University of Utah and The Regents of the University of California.
 * Permission is granted to distribute this file in any manner provided
 * this notice remains intact.
 * 
 * Do not make changes to this file--changes will be lost!
 *
 */


#define SWIGCODE
/* Implementation : PYTHON */

#define SWIGPYTHON
#include <string.h>
#include <stdlib.h>
/* Definitions for Windows/Unix exporting */
#if defined(__WIN32__)
#   if defined(_MSC_VER)
#	define SWIGEXPORT(a,b) __declspec(dllexport) a b
#   else
#	if defined(__BORLANDC__)
#	    define SWIGEXPORT(a,b) a _export b
#	else
#	    define SWIGEXPORT(a,b) a b
#	endif
#   endif
#else
#   define SWIGEXPORT(a,b) a b
#endif

#ifdef __cplusplus
extern "C" {
#endif
#include "Python.h"
extern void SWIG_MakePtr(char *, void *, char *);
extern void SWIG_RegisterMapping(char *, char *, void *(*)(void *));
extern char *SWIG_GetPtr(char *, void **, char *);
extern void SWIG_addvarlink(PyObject *, char *, PyObject *(*)(void), int (*)(PyObject *));
extern PyObject *SWIG_newvarlink(void);
#ifdef __cplusplus
}
#endif

#define SWIG_init    initutilsc

#define SWIG_name    "utilsc"

#include "helpers.h"
#include <wx/config.h>

static PyObject* l_output_helper(PyObject* target, PyObject* o) {
    PyObject*   o2;
    PyObject*   o3;
    if (!target) {                   
        target = o;
    } else if (target == Py_None) {  
        Py_DECREF(Py_None);
        target = o;
    } else {                         
        if (!PyList_Check(target)) {
            o2 = target;
            target = PyList_New(0);
            PyList_Append(target, o2);
	    Py_XDECREF(o2);
        }
        PyList_Append(target,o);
	Py_XDECREF(o);
    }
    return target;
}

static PyObject* t_output_helper(PyObject* target, PyObject* o) {
    PyObject*   o2;
    PyObject*   o3;

    if (!target) {                   
        target = o;
    } else if (target == Py_None) {  
        Py_DECREF(Py_None);
        target = o;
    } else {                         
        if (!PyTuple_Check(target)) {
            o2 = target;
            target = PyTuple_New(1);
            PyTuple_SetItem(target, 0, o2);
        }
        o3 = PyTuple_New(1);            
        PyTuple_SetItem(o3, 0, o);      

        o2 = target;
        target = PySequence_Concat(o2, o3); 
        Py_DECREF(o2);                      
        Py_DECREF(o3);
    }
    return target;
}


extern byte* byte_LIST_helper(PyObject* source);
extern int* int_LIST_helper(PyObject* source);
extern long* long_LIST_helper(PyObject* source);
extern char** string_LIST_helper(PyObject* source);
extern wxPoint* wxPoint_LIST_helper(PyObject* source);
extern wxBitmap** wxBitmap_LIST_helper(PyObject* source);
extern wxString* wxString_LIST_helper(PyObject* source);
extern wxAcceleratorEntry* wxAcceleratorEntry_LIST_helper(PyObject* source);


static char* wxStringErrorMsg = "string type is required for parameter";

    static PyObject* __EnumerationHelper(bool flag, wxString& str, long index) {
        PyObject* ret = PyTuple_New(3);
        if (ret) {
            PyTuple_SET_ITEM(ret, 0, PyInt_FromLong(flag));
            PyTuple_SET_ITEM(ret, 1, PyString_FromString(str));
            PyTuple_SET_ITEM(ret, 2, PyInt_FromLong(index));
        }
        return ret;
    }
#define new_wxConfig(_swigarg0,_swigarg1,_swigarg2,_swigarg3,_swigarg4) (new wxConfig(_swigarg0,_swigarg1,_swigarg2,_swigarg3,_swigarg4))
static PyObject *_wrap_new_wxConfig(PyObject *self, PyObject *args) {
    PyObject * _resultobj;
    wxConfig * _result;
    wxString * _arg0 = &wxPyEmptyStr;
    wxString * _arg1 = &wxPyEmptyStr;
    wxString * _arg2 = &wxPyEmptyStr;
    wxString * _arg3 = &wxPyEmptyStr;
    long  _arg4 = 0;
    PyObject * _obj0 = 0;
    PyObject * _obj1 = 0;
    PyObject * _obj2 = 0;
    PyObject * _obj3 = 0;
    char _ptemp[128];

    self = self;
    if(!PyArg_ParseTuple(args,"|OOOOl:new_wxConfig",&_obj0,&_obj1,&_obj2,&_obj3,&_arg4)) 
        return NULL;
    if (_obj0)
{
    if (!PyString_Check(_obj0)) {
        PyErr_SetString(PyExc_TypeError, wxStringErrorMsg);
        return NULL;
    }
    _arg0 = new wxString(PyString_AsString(_obj0));
}
    if (_obj1)
{
    if (!PyString_Check(_obj1)) {
        PyErr_SetString(PyExc_TypeError, wxStringErrorMsg);
        return NULL;
    }
    _arg1 = new wxString(PyString_AsString(_obj1));
}
    if (_obj2)
{
    if (!PyString_Check(_obj2)) {
        PyErr_SetString(PyExc_TypeError, wxStringErrorMsg);
        return NULL;
    }
    _arg2 = new wxString(PyString_AsString(_obj2));
}
    if (_obj3)
{
    if (!PyString_Check(_obj3)) {
        PyErr_SetString(PyExc_TypeError, wxStringErrorMsg);
        return NULL;
    }
    _arg3 = new wxString(PyString_AsString(_obj3));
}
    _result = (wxConfig *)new_wxConfig(*_arg0,*_arg1,*_arg2,*_arg3,_arg4);
    SWIG_MakePtr(_ptemp, (char *) _result,"_wxConfig_p");
    _resultobj = Py_BuildValue("s",_ptemp);
{
    if (_obj0)
        delete _arg0;
}
{
    if (_obj1)
        delete _arg1;
}
{
    if (_obj2)
        delete _arg2;
}
{
    if (_obj3)
        delete _arg3;
}
    return _resultobj;
}

#define delete_wxConfig(_swigobj) (delete _swigobj)
static PyObject *_wrap_delete_wxConfig(PyObject *self, PyObject *args) {
    PyObject * _resultobj;
    wxConfig * _arg0;
    char * _argc0 = 0;

    self = self;
    if(!PyArg_ParseTuple(args,"s:delete_wxConfig",&_argc0)) 
        return NULL;
    if (_argc0) {
        if (SWIG_GetPtr(_argc0,(void **) &_arg0,"_wxConfig_p")) {
            PyErr_SetString(PyExc_TypeError,"Type error in argument 1 of delete_wxConfig. Expected _wxConfig_p.");
        return NULL;
        }
    }
    delete_wxConfig(_arg0);
    Py_INCREF(Py_None);
    _resultobj = Py_None;
    return _resultobj;
}

#define wxConfig_DontCreateOnDemand(_swigobj)  (_swigobj->DontCreateOnDemand())
static PyObject *_wrap_wxConfig_DontCreateOnDemand(PyObject *self, PyObject *args) {
    PyObject * _resultobj;
    wxConfig * _arg0;
    char * _argc0 = 0;

    self = self;
    if(!PyArg_ParseTuple(args,"s:wxConfig_DontCreateOnDemand",&_argc0)) 
        return NULL;
    if (_argc0) {
        if (SWIG_GetPtr(_argc0,(void **) &_arg0,"_wxConfig_p")) {
            PyErr_SetString(PyExc_TypeError,"Type error in argument 1 of wxConfig_DontCreateOnDemand. Expected _wxConfig_p.");
        return NULL;
        }
    }
    wxConfig_DontCreateOnDemand(_arg0);
    Py_INCREF(Py_None);
    _resultobj = Py_None;
    return _resultobj;
}

#define wxConfig_DeleteEntry(_swigobj,_swigarg0,_swigarg1)  (_swigobj->DeleteEntry(_swigarg0,_swigarg1))
static PyObject *_wrap_wxConfig_DeleteEntry(PyObject *self, PyObject *args) {
    PyObject * _resultobj;
    bool  _result;
    wxConfig * _arg0;
    wxString * _arg1;
    bool  _arg2 = TRUE;
    char * _argc0 = 0;
    PyObject * _obj1 = 0;
    int tempbool2;

    self = self;
    if(!PyArg_ParseTuple(args,"sO|i:wxConfig_DeleteEntry",&_argc0,&_obj1,&tempbool2)) 
        return NULL;
    if (_argc0) {
        if (SWIG_GetPtr(_argc0,(void **) &_arg0,"_wxConfig_p")) {
            PyErr_SetString(PyExc_TypeError,"Type error in argument 1 of wxConfig_DeleteEntry. Expected _wxConfig_p.");
        return NULL;
        }
    }
{
    if (!PyString_Check(_obj1)) {
        PyErr_SetString(PyExc_TypeError, wxStringErrorMsg);
        return NULL;
    }
    _arg1 = new wxString(PyString_AsString(_obj1));
}
    _arg2 = (bool ) tempbool2;
    _result = (bool )wxConfig_DeleteEntry(_arg0,*_arg1,_arg2);
    _resultobj = Py_BuildValue("i",_result);
{
    if (_obj1)
        delete _arg1;
}
    return _resultobj;
}

#define wxConfig_DeleteGroup(_swigobj,_swigarg0)  (_swigobj->DeleteGroup(_swigarg0))
static PyObject *_wrap_wxConfig_DeleteGroup(PyObject *self, PyObject *args) {
    PyObject * _resultobj;
    bool  _result;
    wxConfig * _arg0;
    wxString * _arg1;
    char * _argc0 = 0;
    PyObject * _obj1 = 0;

    self = self;
    if(!PyArg_ParseTuple(args,"sO:wxConfig_DeleteGroup",&_argc0,&_obj1)) 
        return NULL;
    if (_argc0) {
        if (SWIG_GetPtr(_argc0,(void **) &_arg0,"_wxConfig_p")) {
            PyErr_SetString(PyExc_TypeError,"Type error in argument 1 of wxConfig_DeleteGroup. Expected _wxConfig_p.");
        return NULL;
        }
    }
{
    if (!PyString_Check(_obj1)) {
        PyErr_SetString(PyExc_TypeError, wxStringErrorMsg);
        return NULL;
    }
    _arg1 = new wxString(PyString_AsString(_obj1));
}
    _result = (bool )wxConfig_DeleteGroup(_arg0,*_arg1);
    _resultobj = Py_BuildValue("i",_result);
{
    if (_obj1)
        delete _arg1;
}
    return _resultobj;
}

#define wxConfig_Exists(_swigobj,_swigarg0)  (_swigobj->Exists(_swigarg0))
static PyObject *_wrap_wxConfig_Exists(PyObject *self, PyObject *args) {
    PyObject * _resultobj;
    bool  _result;
    wxConfig * _arg0;
    wxString * _arg1;
    char * _argc0 = 0;
    PyObject * _obj1 = 0;

    self = self;
    if(!PyArg_ParseTuple(args,"sO:wxConfig_Exists",&_argc0,&_obj1)) 
        return NULL;
    if (_argc0) {
        if (SWIG_GetPtr(_argc0,(void **) &_arg0,"_wxConfig_p")) {
            PyErr_SetString(PyExc_TypeError,"Type error in argument 1 of wxConfig_Exists. Expected _wxConfig_p.");
        return NULL;
        }
    }
{
    if (!PyString_Check(_obj1)) {
        PyErr_SetString(PyExc_TypeError, wxStringErrorMsg);
        return NULL;
    }
    _arg1 = new wxString(PyString_AsString(_obj1));
}
    _result = (bool )wxConfig_Exists(_arg0,*_arg1);
    _resultobj = Py_BuildValue("i",_result);
{
    if (_obj1)
        delete _arg1;
}
    return _resultobj;
}

#define wxConfig_Flush(_swigobj,_swigarg0)  (_swigobj->Flush(_swigarg0))
static PyObject *_wrap_wxConfig_Flush(PyObject *self, PyObject *args) {
    PyObject * _resultobj;
    bool  _result;
    wxConfig * _arg0;
    bool  _arg1 = FALSE;
    char * _argc0 = 0;
    int tempbool1;

    self = self;
    if(!PyArg_ParseTuple(args,"s|i:wxConfig_Flush",&_argc0,&tempbool1)) 
        return NULL;
    if (_argc0) {
        if (SWIG_GetPtr(_argc0,(void **) &_arg0,"_wxConfig_p")) {
            PyErr_SetString(PyExc_TypeError,"Type error in argument 1 of wxConfig_Flush. Expected _wxConfig_p.");
        return NULL;
        }
    }
    _arg1 = (bool ) tempbool1;
    _result = (bool )wxConfig_Flush(_arg0,_arg1);
    _resultobj = Py_BuildValue("i",_result);
    return _resultobj;
}

#define wxConfig_GetAppName(_swigobj)  (_swigobj->GetAppName())
static PyObject *_wrap_wxConfig_GetAppName(PyObject *self, PyObject *args) {
    PyObject * _resultobj;
    wxString * _result;
    wxConfig * _arg0;
    char * _argc0 = 0;

    self = self;
    if(!PyArg_ParseTuple(args,"s:wxConfig_GetAppName",&_argc0)) 
        return NULL;
    if (_argc0) {
        if (SWIG_GetPtr(_argc0,(void **) &_arg0,"_wxConfig_p")) {
            PyErr_SetString(PyExc_TypeError,"Type error in argument 1 of wxConfig_GetAppName. Expected _wxConfig_p.");
        return NULL;
        }
    }
    _result = new wxString (wxConfig_GetAppName(_arg0));
{
    _resultobj = PyString_FromString(WXSTRINGCAST *(_result));
}
{
    delete _result;
}
    return _resultobj;
}

static PyObject * wxConfig_GetFirstGroup(wxConfig *self) {
            bool     cont;
            long     index = 0;
            wxString value;

            cont = self->GetFirstGroup(value, index);
            return __EnumerationHelper(cont, value, index);
        }
static PyObject *_wrap_wxConfig_GetFirstGroup(PyObject *self, PyObject *args) {
    PyObject * _resultobj;
    PyObject * _result;
    wxConfig * _arg0;
    char * _argc0 = 0;

    self = self;
    if(!PyArg_ParseTuple(args,"s:wxConfig_GetFirstGroup",&_argc0)) 
        return NULL;
    if (_argc0) {
        if (SWIG_GetPtr(_argc0,(void **) &_arg0,"_wxConfig_p")) {
            PyErr_SetString(PyExc_TypeError,"Type error in argument 1 of wxConfig_GetFirstGroup. Expected _wxConfig_p.");
        return NULL;
        }
    }
    _result = (PyObject *)wxConfig_GetFirstGroup(_arg0);
{
  _resultobj = _result;
}
    return _resultobj;
}

static PyObject * wxConfig_GetFirstEntry(wxConfig *self) {
            bool     cont;
            long     index = 0;
            wxString value;

            cont = self->GetFirstEntry(value, index);
            return __EnumerationHelper(cont, value, index);
        }
static PyObject *_wrap_wxConfig_GetFirstEntry(PyObject *self, PyObject *args) {
    PyObject * _resultobj;
    PyObject * _result;
    wxConfig * _arg0;
    char * _argc0 = 0;

    self = self;
    if(!PyArg_ParseTuple(args,"s:wxConfig_GetFirstEntry",&_argc0)) 
        return NULL;
    if (_argc0) {
        if (SWIG_GetPtr(_argc0,(void **) &_arg0,"_wxConfig_p")) {
            PyErr_SetString(PyExc_TypeError,"Type error in argument 1 of wxConfig_GetFirstEntry. Expected _wxConfig_p.");
        return NULL;
        }
    }
    _result = (PyObject *)wxConfig_GetFirstEntry(_arg0);
{
  _resultobj = _result;
}
    return _resultobj;
}

static PyObject * wxConfig_GetNextGroup(wxConfig *self,long  index) {
            bool     cont;
            wxString value;

            cont = self->GetNextGroup(value, index);
            return __EnumerationHelper(cont, value, index);
        }
static PyObject *_wrap_wxConfig_GetNextGroup(PyObject *self, PyObject *args) {
    PyObject * _resultobj;
    PyObject * _result;
    wxConfig * _arg0;
    long  _arg1;
    char * _argc0 = 0;

    self = self;
    if(!PyArg_ParseTuple(args,"sl:wxConfig_GetNextGroup",&_argc0,&_arg1)) 
        return NULL;
    if (_argc0) {
        if (SWIG_GetPtr(_argc0,(void **) &_arg0,"_wxConfig_p")) {
            PyErr_SetString(PyExc_TypeError,"Type error in argument 1 of wxConfig_GetNextGroup. Expected _wxConfig_p.");
        return NULL;
        }
    }
    _result = (PyObject *)wxConfig_GetNextGroup(_arg0,_arg1);
{
  _resultobj = _result;
}
    return _resultobj;
}

static PyObject * wxConfig_GetNextEntry(wxConfig *self,long  index) {
            bool     cont;
            wxString value;

            cont = self->GetNextEntry(value, index);
            return __EnumerationHelper(cont, value, index);
        }
static PyObject *_wrap_wxConfig_GetNextEntry(PyObject *self, PyObject *args) {
    PyObject * _resultobj;
    PyObject * _result;
    wxConfig * _arg0;
    long  _arg1;
    char * _argc0 = 0;

    self = self;
    if(!PyArg_ParseTuple(args,"sl:wxConfig_GetNextEntry",&_argc0,&_arg1)) 
        return NULL;
    if (_argc0) {
        if (SWIG_GetPtr(_argc0,(void **) &_arg0,"_wxConfig_p")) {
            PyErr_SetString(PyExc_TypeError,"Type error in argument 1 of wxConfig_GetNextEntry. Expected _wxConfig_p.");
        return NULL;
        }
    }
    _result = (PyObject *)wxConfig_GetNextEntry(_arg0,_arg1);
{
  _resultobj = _result;
}
    return _resultobj;
}

#define wxConfig_GetNumberOfEntries(_swigobj,_swigarg0)  (_swigobj->GetNumberOfEntries(_swigarg0))
static PyObject *_wrap_wxConfig_GetNumberOfEntries(PyObject *self, PyObject *args) {
    PyObject * _resultobj;
    int  _result;
    wxConfig * _arg0;
    bool  _arg1 = FALSE;
    char * _argc0 = 0;
    int tempbool1;

    self = self;
    if(!PyArg_ParseTuple(args,"s|i:wxConfig_GetNumberOfEntries",&_argc0,&tempbool1)) 
        return NULL;
    if (_argc0) {
        if (SWIG_GetPtr(_argc0,(void **) &_arg0,"_wxConfig_p")) {
            PyErr_SetString(PyExc_TypeError,"Type error in argument 1 of wxConfig_GetNumberOfEntries. Expected _wxConfig_p.");
        return NULL;
        }
    }
    _arg1 = (bool ) tempbool1;
    _result = (int )wxConfig_GetNumberOfEntries(_arg0,_arg1);
    _resultobj = Py_BuildValue("i",_result);
    return _resultobj;
}

#define wxConfig_GetNumberOfGroups(_swigobj,_swigarg0)  (_swigobj->GetNumberOfGroups(_swigarg0))
static PyObject *_wrap_wxConfig_GetNumberOfGroups(PyObject *self, PyObject *args) {
    PyObject * _resultobj;
    int  _result;
    wxConfig * _arg0;
    bool  _arg1 = FALSE;
    char * _argc0 = 0;
    int tempbool1;

    self = self;
    if(!PyArg_ParseTuple(args,"s|i:wxConfig_GetNumberOfGroups",&_argc0,&tempbool1)) 
        return NULL;
    if (_argc0) {
        if (SWIG_GetPtr(_argc0,(void **) &_arg0,"_wxConfig_p")) {
            PyErr_SetString(PyExc_TypeError,"Type error in argument 1 of wxConfig_GetNumberOfGroups. Expected _wxConfig_p.");
        return NULL;
        }
    }
    _arg1 = (bool ) tempbool1;
    _result = (int )wxConfig_GetNumberOfGroups(_arg0,_arg1);
    _resultobj = Py_BuildValue("i",_result);
    return _resultobj;
}

#define wxConfig_GetPath(_swigobj)  (_swigobj->GetPath())
static PyObject *_wrap_wxConfig_GetPath(PyObject *self, PyObject *args) {
    PyObject * _resultobj;
    wxString * _result;
    wxConfig * _arg0;
    char * _argc0 = 0;

    self = self;
    if(!PyArg_ParseTuple(args,"s:wxConfig_GetPath",&_argc0)) 
        return NULL;
    if (_argc0) {
        if (SWIG_GetPtr(_argc0,(void **) &_arg0,"_wxConfig_p")) {
            PyErr_SetString(PyExc_TypeError,"Type error in argument 1 of wxConfig_GetPath. Expected _wxConfig_p.");
        return NULL;
        }
    }
    _result = new wxString (wxConfig_GetPath(_arg0));
{
    _resultobj = PyString_FromString(WXSTRINGCAST *(_result));
}
{
    delete _result;
}
    return _resultobj;
}

#define wxConfig_GetVendorName(_swigobj)  (_swigobj->GetVendorName())
static PyObject *_wrap_wxConfig_GetVendorName(PyObject *self, PyObject *args) {
    PyObject * _resultobj;
    wxString * _result;
    wxConfig * _arg0;
    char * _argc0 = 0;

    self = self;
    if(!PyArg_ParseTuple(args,"s:wxConfig_GetVendorName",&_argc0)) 
        return NULL;
    if (_argc0) {
        if (SWIG_GetPtr(_argc0,(void **) &_arg0,"_wxConfig_p")) {
            PyErr_SetString(PyExc_TypeError,"Type error in argument 1 of wxConfig_GetVendorName. Expected _wxConfig_p.");
        return NULL;
        }
    }
    _result = new wxString (wxConfig_GetVendorName(_arg0));
{
    _resultobj = PyString_FromString(WXSTRINGCAST *(_result));
}
{
    delete _result;
}
    return _resultobj;
}

#define wxConfig_HasEntry(_swigobj,_swigarg0)  (_swigobj->HasEntry(_swigarg0))
static PyObject *_wrap_wxConfig_HasEntry(PyObject *self, PyObject *args) {
    PyObject * _resultobj;
    bool  _result;
    wxConfig * _arg0;
    wxString * _arg1;
    char * _argc0 = 0;
    PyObject * _obj1 = 0;

    self = self;
    if(!PyArg_ParseTuple(args,"sO:wxConfig_HasEntry",&_argc0,&_obj1)) 
        return NULL;
    if (_argc0) {
        if (SWIG_GetPtr(_argc0,(void **) &_arg0,"_wxConfig_p")) {
            PyErr_SetString(PyExc_TypeError,"Type error in argument 1 of wxConfig_HasEntry. Expected _wxConfig_p.");
        return NULL;
        }
    }
{
    if (!PyString_Check(_obj1)) {
        PyErr_SetString(PyExc_TypeError, wxStringErrorMsg);
        return NULL;
    }
    _arg1 = new wxString(PyString_AsString(_obj1));
}
    _result = (bool )wxConfig_HasEntry(_arg0,*_arg1);
    _resultobj = Py_BuildValue("i",_result);
{
    if (_obj1)
        delete _arg1;
}
    return _resultobj;
}

#define wxConfig_HasGroup(_swigobj,_swigarg0)  (_swigobj->HasGroup(_swigarg0))
static PyObject *_wrap_wxConfig_HasGroup(PyObject *self, PyObject *args) {
    PyObject * _resultobj;
    bool  _result;
    wxConfig * _arg0;
    wxString * _arg1;
    char * _argc0 = 0;
    PyObject * _obj1 = 0;

    self = self;
    if(!PyArg_ParseTuple(args,"sO:wxConfig_HasGroup",&_argc0,&_obj1)) 
        return NULL;
    if (_argc0) {
        if (SWIG_GetPtr(_argc0,(void **) &_arg0,"_wxConfig_p")) {
            PyErr_SetString(PyExc_TypeError,"Type error in argument 1 of wxConfig_HasGroup. Expected _wxConfig_p.");
        return NULL;
        }
    }
{
    if (!PyString_Check(_obj1)) {
        PyErr_SetString(PyExc_TypeError, wxStringErrorMsg);
        return NULL;
    }
    _arg1 = new wxString(PyString_AsString(_obj1));
}
    _result = (bool )wxConfig_HasGroup(_arg0,*_arg1);
    _resultobj = Py_BuildValue("i",_result);
{
    if (_obj1)
        delete _arg1;
}
    return _resultobj;
}

#define wxConfig_IsExpandingEnvVars(_swigobj)  (_swigobj->IsExpandingEnvVars())
static PyObject *_wrap_wxConfig_IsExpandingEnvVars(PyObject *self, PyObject *args) {
    PyObject * _resultobj;
    bool  _result;
    wxConfig * _arg0;
    char * _argc0 = 0;

    self = self;
    if(!PyArg_ParseTuple(args,"s:wxConfig_IsExpandingEnvVars",&_argc0)) 
        return NULL;
    if (_argc0) {
        if (SWIG_GetPtr(_argc0,(void **) &_arg0,"_wxConfig_p")) {
            PyErr_SetString(PyExc_TypeError,"Type error in argument 1 of wxConfig_IsExpandingEnvVars. Expected _wxConfig_p.");
        return NULL;
        }
    }
    _result = (bool )wxConfig_IsExpandingEnvVars(_arg0);
    _resultobj = Py_BuildValue("i",_result);
    return _resultobj;
}

#define wxConfig_IsRecordingDefaults(_swigobj)  (_swigobj->IsRecordingDefaults())
static PyObject *_wrap_wxConfig_IsRecordingDefaults(PyObject *self, PyObject *args) {
    PyObject * _resultobj;
    bool  _result;
    wxConfig * _arg0;
    char * _argc0 = 0;

    self = self;
    if(!PyArg_ParseTuple(args,"s:wxConfig_IsRecordingDefaults",&_argc0)) 
        return NULL;
    if (_argc0) {
        if (SWIG_GetPtr(_argc0,(void **) &_arg0,"_wxConfig_p")) {
            PyErr_SetString(PyExc_TypeError,"Type error in argument 1 of wxConfig_IsRecordingDefaults. Expected _wxConfig_p.");
        return NULL;
        }
    }
    _result = (bool )wxConfig_IsRecordingDefaults(_arg0);
    _resultobj = Py_BuildValue("i",_result);
    return _resultobj;
}

#define wxConfig_Read(_swigobj,_swigarg0,_swigarg1)  (_swigobj->Read(_swigarg0,_swigarg1))
static PyObject *_wrap_wxConfig_Read(PyObject *self, PyObject *args) {
    PyObject * _resultobj;
    wxString * _result;
    wxConfig * _arg0;
    wxString * _arg1;
    wxString * _arg2 = &wxPyEmptyStr;
    char * _argc0 = 0;
    PyObject * _obj1 = 0;
    PyObject * _obj2 = 0;

    self = self;
    if(!PyArg_ParseTuple(args,"sO|O:wxConfig_Read",&_argc0,&_obj1,&_obj2)) 
        return NULL;
    if (_argc0) {
        if (SWIG_GetPtr(_argc0,(void **) &_arg0,"_wxConfig_p")) {
            PyErr_SetString(PyExc_TypeError,"Type error in argument 1 of wxConfig_Read. Expected _wxConfig_p.");
        return NULL;
        }
    }
{
    if (!PyString_Check(_obj1)) {
        PyErr_SetString(PyExc_TypeError, wxStringErrorMsg);
        return NULL;
    }
    _arg1 = new wxString(PyString_AsString(_obj1));
}
    if (_obj2)
{
    if (!PyString_Check(_obj2)) {
        PyErr_SetString(PyExc_TypeError, wxStringErrorMsg);
        return NULL;
    }
    _arg2 = new wxString(PyString_AsString(_obj2));
}
    _result = new wxString (wxConfig_Read(_arg0,*_arg1,*_arg2));
{
    _resultobj = PyString_FromString(WXSTRINGCAST *(_result));
}
{
    if (_obj1)
        delete _arg1;
}
{
    if (_obj2)
        delete _arg2;
}
{
    delete _result;
}
    return _resultobj;
}

#define wxConfig_ReadInt(_swigobj,_swigarg0,_swigarg1)  (_swigobj->Read(_swigarg0,_swigarg1))
static PyObject *_wrap_wxConfig_ReadInt(PyObject *self, PyObject *args) {
    PyObject * _resultobj;
    long  _result;
    wxConfig * _arg0;
    wxString * _arg1;
    long  _arg2 = 0;
    char * _argc0 = 0;
    PyObject * _obj1 = 0;

    self = self;
    if(!PyArg_ParseTuple(args,"sO|l:wxConfig_ReadInt",&_argc0,&_obj1,&_arg2)) 
        return NULL;
    if (_argc0) {
        if (SWIG_GetPtr(_argc0,(void **) &_arg0,"_wxConfig_p")) {
            PyErr_SetString(PyExc_TypeError,"Type error in argument 1 of wxConfig_ReadInt. Expected _wxConfig_p.");
        return NULL;
        }
    }
{
    if (!PyString_Check(_obj1)) {
        PyErr_SetString(PyExc_TypeError, wxStringErrorMsg);
        return NULL;
    }
    _arg1 = new wxString(PyString_AsString(_obj1));
}
    _result = (long )wxConfig_ReadInt(_arg0,*_arg1,_arg2);
    _resultobj = Py_BuildValue("l",_result);
{
    if (_obj1)
        delete _arg1;
}
    return _resultobj;
}

#define wxConfig_ReadFloat(_swigobj,_swigarg0,_swigarg1)  (_swigobj->Read(_swigarg0,_swigarg1))
static PyObject *_wrap_wxConfig_ReadFloat(PyObject *self, PyObject *args) {
    PyObject * _resultobj;
    double  _result;
    wxConfig * _arg0;
    wxString * _arg1;
    double  _arg2 = 0.0;
    char * _argc0 = 0;
    PyObject * _obj1 = 0;

    self = self;
    if(!PyArg_ParseTuple(args,"sO|d:wxConfig_ReadFloat",&_argc0,&_obj1,&_arg2)) 
        return NULL;
    if (_argc0) {
        if (SWIG_GetPtr(_argc0,(void **) &_arg0,"_wxConfig_p")) {
            PyErr_SetString(PyExc_TypeError,"Type error in argument 1 of wxConfig_ReadFloat. Expected _wxConfig_p.");
        return NULL;
        }
    }
{
    if (!PyString_Check(_obj1)) {
        PyErr_SetString(PyExc_TypeError, wxStringErrorMsg);
        return NULL;
    }
    _arg1 = new wxString(PyString_AsString(_obj1));
}
    _result = (double )wxConfig_ReadFloat(_arg0,*_arg1,_arg2);
    _resultobj = Py_BuildValue("d",_result);
{
    if (_obj1)
        delete _arg1;
}
    return _resultobj;
}

#define wxConfig_SetAppName(_swigobj,_swigarg0)  (_swigobj->SetAppName(_swigarg0))
static PyObject *_wrap_wxConfig_SetAppName(PyObject *self, PyObject *args) {
    PyObject * _resultobj;
    wxConfig * _arg0;
    wxString * _arg1;
    char * _argc0 = 0;
    PyObject * _obj1 = 0;

    self = self;
    if(!PyArg_ParseTuple(args,"sO:wxConfig_SetAppName",&_argc0,&_obj1)) 
        return NULL;
    if (_argc0) {
        if (SWIG_GetPtr(_argc0,(void **) &_arg0,"_wxConfig_p")) {
            PyErr_SetString(PyExc_TypeError,"Type error in argument 1 of wxConfig_SetAppName. Expected _wxConfig_p.");
        return NULL;
        }
    }
{
    if (!PyString_Check(_obj1)) {
        PyErr_SetString(PyExc_TypeError, wxStringErrorMsg);
        return NULL;
    }
    _arg1 = new wxString(PyString_AsString(_obj1));
}
    wxConfig_SetAppName(_arg0,*_arg1);
    Py_INCREF(Py_None);
    _resultobj = Py_None;
{
    if (_obj1)
        delete _arg1;
}
    return _resultobj;
}

#define wxConfig_SetExpandEnvVars(_swigobj,_swigarg0)  (_swigobj->SetExpandEnvVars(_swigarg0))
static PyObject *_wrap_wxConfig_SetExpandEnvVars(PyObject *self, PyObject *args) {
    PyObject * _resultobj;
    wxConfig * _arg0;
    bool  _arg1 = TRUE;
    char * _argc0 = 0;
    int tempbool1;

    self = self;
    if(!PyArg_ParseTuple(args,"s|i:wxConfig_SetExpandEnvVars",&_argc0,&tempbool1)) 
        return NULL;
    if (_argc0) {
        if (SWIG_GetPtr(_argc0,(void **) &_arg0,"_wxConfig_p")) {
            PyErr_SetString(PyExc_TypeError,"Type error in argument 1 of wxConfig_SetExpandEnvVars. Expected _wxConfig_p.");
        return NULL;
        }
    }
    _arg1 = (bool ) tempbool1;
    wxConfig_SetExpandEnvVars(_arg0,_arg1);
    Py_INCREF(Py_None);
    _resultobj = Py_None;
    return _resultobj;
}

#define wxConfig_SetPath(_swigobj,_swigarg0)  (_swigobj->SetPath(_swigarg0))
static PyObject *_wrap_wxConfig_SetPath(PyObject *self, PyObject *args) {
    PyObject * _resultobj;
    wxConfig * _arg0;
    wxString * _arg1;
    char * _argc0 = 0;
    PyObject * _obj1 = 0;

    self = self;
    if(!PyArg_ParseTuple(args,"sO:wxConfig_SetPath",&_argc0,&_obj1)) 
        return NULL;
    if (_argc0) {
        if (SWIG_GetPtr(_argc0,(void **) &_arg0,"_wxConfig_p")) {
            PyErr_SetString(PyExc_TypeError,"Type error in argument 1 of wxConfig_SetPath. Expected _wxConfig_p.");
        return NULL;
        }
    }
{
    if (!PyString_Check(_obj1)) {
        PyErr_SetString(PyExc_TypeError, wxStringErrorMsg);
        return NULL;
    }
    _arg1 = new wxString(PyString_AsString(_obj1));
}
    wxConfig_SetPath(_arg0,*_arg1);
    Py_INCREF(Py_None);
    _resultobj = Py_None;
{
    if (_obj1)
        delete _arg1;
}
    return _resultobj;
}

#define wxConfig_SetRecordDefaults(_swigobj,_swigarg0)  (_swigobj->SetRecordDefaults(_swigarg0))
static PyObject *_wrap_wxConfig_SetRecordDefaults(PyObject *self, PyObject *args) {
    PyObject * _resultobj;
    wxConfig * _arg0;
    bool  _arg1 = TRUE;
    char * _argc0 = 0;
    int tempbool1;

    self = self;
    if(!PyArg_ParseTuple(args,"s|i:wxConfig_SetRecordDefaults",&_argc0,&tempbool1)) 
        return NULL;
    if (_argc0) {
        if (SWIG_GetPtr(_argc0,(void **) &_arg0,"_wxConfig_p")) {
            PyErr_SetString(PyExc_TypeError,"Type error in argument 1 of wxConfig_SetRecordDefaults. Expected _wxConfig_p.");
        return NULL;
        }
    }
    _arg1 = (bool ) tempbool1;
    wxConfig_SetRecordDefaults(_arg0,_arg1);
    Py_INCREF(Py_None);
    _resultobj = Py_None;
    return _resultobj;
}

#define wxConfig_SetVendorName(_swigobj,_swigarg0)  (_swigobj->SetVendorName(_swigarg0))
static PyObject *_wrap_wxConfig_SetVendorName(PyObject *self, PyObject *args) {
    PyObject * _resultobj;
    wxConfig * _arg0;
    wxString * _arg1;
    char * _argc0 = 0;
    PyObject * _obj1 = 0;

    self = self;
    if(!PyArg_ParseTuple(args,"sO:wxConfig_SetVendorName",&_argc0,&_obj1)) 
        return NULL;
    if (_argc0) {
        if (SWIG_GetPtr(_argc0,(void **) &_arg0,"_wxConfig_p")) {
            PyErr_SetString(PyExc_TypeError,"Type error in argument 1 of wxConfig_SetVendorName. Expected _wxConfig_p.");
        return NULL;
        }
    }
{
    if (!PyString_Check(_obj1)) {
        PyErr_SetString(PyExc_TypeError, wxStringErrorMsg);
        return NULL;
    }
    _arg1 = new wxString(PyString_AsString(_obj1));
}
    wxConfig_SetVendorName(_arg0,*_arg1);
    Py_INCREF(Py_None);
    _resultobj = Py_None;
{
    if (_obj1)
        delete _arg1;
}
    return _resultobj;
}

#define wxConfig_Write(_swigobj,_swigarg0,_swigarg1)  (_swigobj->Write(_swigarg0,_swigarg1))
static PyObject *_wrap_wxConfig_Write(PyObject *self, PyObject *args) {
    PyObject * _resultobj;
    bool  _result;
    wxConfig * _arg0;
    wxString * _arg1;
    wxString * _arg2;
    char * _argc0 = 0;
    PyObject * _obj1 = 0;
    PyObject * _obj2 = 0;

    self = self;
    if(!PyArg_ParseTuple(args,"sOO:wxConfig_Write",&_argc0,&_obj1,&_obj2)) 
        return NULL;
    if (_argc0) {
        if (SWIG_GetPtr(_argc0,(void **) &_arg0,"_wxConfig_p")) {
            PyErr_SetString(PyExc_TypeError,"Type error in argument 1 of wxConfig_Write. Expected _wxConfig_p.");
        return NULL;
        }
    }
{
    if (!PyString_Check(_obj1)) {
        PyErr_SetString(PyExc_TypeError, wxStringErrorMsg);
        return NULL;
    }
    _arg1 = new wxString(PyString_AsString(_obj1));
}
{
    if (!PyString_Check(_obj2)) {
        PyErr_SetString(PyExc_TypeError, wxStringErrorMsg);
        return NULL;
    }
    _arg2 = new wxString(PyString_AsString(_obj2));
}
    _result = (bool )wxConfig_Write(_arg0,*_arg1,*_arg2);
    _resultobj = Py_BuildValue("i",_result);
{
    if (_obj1)
        delete _arg1;
}
{
    if (_obj2)
        delete _arg2;
}
    return _resultobj;
}

#define wxConfig_WriteInt(_swigobj,_swigarg0,_swigarg1)  (_swigobj->Write(_swigarg0,_swigarg1))
static PyObject *_wrap_wxConfig_WriteInt(PyObject *self, PyObject *args) {
    PyObject * _resultobj;
    bool  _result;
    wxConfig * _arg0;
    wxString * _arg1;
    long  _arg2;
    char * _argc0 = 0;
    PyObject * _obj1 = 0;

    self = self;
    if(!PyArg_ParseTuple(args,"sOl:wxConfig_WriteInt",&_argc0,&_obj1,&_arg2)) 
        return NULL;
    if (_argc0) {
        if (SWIG_GetPtr(_argc0,(void **) &_arg0,"_wxConfig_p")) {
            PyErr_SetString(PyExc_TypeError,"Type error in argument 1 of wxConfig_WriteInt. Expected _wxConfig_p.");
        return NULL;
        }
    }
{
    if (!PyString_Check(_obj1)) {
        PyErr_SetString(PyExc_TypeError, wxStringErrorMsg);
        return NULL;
    }
    _arg1 = new wxString(PyString_AsString(_obj1));
}
    _result = (bool )wxConfig_WriteInt(_arg0,*_arg1,_arg2);
    _resultobj = Py_BuildValue("i",_result);
{
    if (_obj1)
        delete _arg1;
}
    return _resultobj;
}

#define wxConfig_WriteFloat(_swigobj,_swigarg0,_swigarg1)  (_swigobj->Write(_swigarg0,_swigarg1))
static PyObject *_wrap_wxConfig_WriteFloat(PyObject *self, PyObject *args) {
    PyObject * _resultobj;
    bool  _result;
    wxConfig * _arg0;
    wxString * _arg1;
    double  _arg2;
    char * _argc0 = 0;
    PyObject * _obj1 = 0;

    self = self;
    if(!PyArg_ParseTuple(args,"sOd:wxConfig_WriteFloat",&_argc0,&_obj1,&_arg2)) 
        return NULL;
    if (_argc0) {
        if (SWIG_GetPtr(_argc0,(void **) &_arg0,"_wxConfig_p")) {
            PyErr_SetString(PyExc_TypeError,"Type error in argument 1 of wxConfig_WriteFloat. Expected _wxConfig_p.");
        return NULL;
        }
    }
{
    if (!PyString_Check(_obj1)) {
        PyErr_SetString(PyExc_TypeError, wxStringErrorMsg);
        return NULL;
    }
    _arg1 = new wxString(PyString_AsString(_obj1));
}
    _result = (bool )wxConfig_WriteFloat(_arg0,*_arg1,_arg2);
    _resultobj = Py_BuildValue("i",_result);
{
    if (_obj1)
        delete _arg1;
}
    return _resultobj;
}

static PyMethodDef utilscMethods[] = {
	 { "wxConfig_WriteFloat", _wrap_wxConfig_WriteFloat, 1 },
	 { "wxConfig_WriteInt", _wrap_wxConfig_WriteInt, 1 },
	 { "wxConfig_Write", _wrap_wxConfig_Write, 1 },
	 { "wxConfig_SetVendorName", _wrap_wxConfig_SetVendorName, 1 },
	 { "wxConfig_SetRecordDefaults", _wrap_wxConfig_SetRecordDefaults, 1 },
	 { "wxConfig_SetPath", _wrap_wxConfig_SetPath, 1 },
	 { "wxConfig_SetExpandEnvVars", _wrap_wxConfig_SetExpandEnvVars, 1 },
	 { "wxConfig_SetAppName", _wrap_wxConfig_SetAppName, 1 },
	 { "wxConfig_ReadFloat", _wrap_wxConfig_ReadFloat, 1 },
	 { "wxConfig_ReadInt", _wrap_wxConfig_ReadInt, 1 },
	 { "wxConfig_Read", _wrap_wxConfig_Read, 1 },
	 { "wxConfig_IsRecordingDefaults", _wrap_wxConfig_IsRecordingDefaults, 1 },
	 { "wxConfig_IsExpandingEnvVars", _wrap_wxConfig_IsExpandingEnvVars, 1 },
	 { "wxConfig_HasGroup", _wrap_wxConfig_HasGroup, 1 },
	 { "wxConfig_HasEntry", _wrap_wxConfig_HasEntry, 1 },
	 { "wxConfig_GetVendorName", _wrap_wxConfig_GetVendorName, 1 },
	 { "wxConfig_GetPath", _wrap_wxConfig_GetPath, 1 },
	 { "wxConfig_GetNumberOfGroups", _wrap_wxConfig_GetNumberOfGroups, 1 },
	 { "wxConfig_GetNumberOfEntries", _wrap_wxConfig_GetNumberOfEntries, 1 },
	 { "wxConfig_GetNextEntry", _wrap_wxConfig_GetNextEntry, 1 },
	 { "wxConfig_GetNextGroup", _wrap_wxConfig_GetNextGroup, 1 },
	 { "wxConfig_GetFirstEntry", _wrap_wxConfig_GetFirstEntry, 1 },
	 { "wxConfig_GetFirstGroup", _wrap_wxConfig_GetFirstGroup, 1 },
	 { "wxConfig_GetAppName", _wrap_wxConfig_GetAppName, 1 },
	 { "wxConfig_Flush", _wrap_wxConfig_Flush, 1 },
	 { "wxConfig_Exists", _wrap_wxConfig_Exists, 1 },
	 { "wxConfig_DeleteGroup", _wrap_wxConfig_DeleteGroup, 1 },
	 { "wxConfig_DeleteEntry", _wrap_wxConfig_DeleteEntry, 1 },
	 { "wxConfig_DontCreateOnDemand", _wrap_wxConfig_DontCreateOnDemand, 1 },
	 { "delete_wxConfig", _wrap_delete_wxConfig, 1 },
	 { "new_wxConfig", _wrap_new_wxConfig, 1 },
	 { NULL, NULL }
};
static PyObject *SWIG_globals;
#ifdef __cplusplus
extern "C" 
#endif
SWIGEXPORT(void,initutilsc)() {
	 PyObject *m, *d;
	 SWIG_globals = SWIG_newvarlink();
	 m = Py_InitModule("utilsc", utilscMethods);
	 d = PyModule_GetDict(m);
/*
 * These are the pointer type-equivalency mappings. 
 * (Used by the SWIG pointer type-checker).
 */
	 SWIG_RegisterMapping("_signed_long","_long",0);
	 SWIG_RegisterMapping("_long","_unsigned_long",0);
	 SWIG_RegisterMapping("_long","_signed_long",0);
	 SWIG_RegisterMapping("_wxConfig","_class_wxConfig",0);
	 SWIG_RegisterMapping("_unsigned_long","_long",0);
	 SWIG_RegisterMapping("_signed_int","_int",0);
	 SWIG_RegisterMapping("_unsigned_short","_short",0);
	 SWIG_RegisterMapping("_signed_short","_short",0);
	 SWIG_RegisterMapping("_unsigned_int","_int",0);
	 SWIG_RegisterMapping("_short","_unsigned_short",0);
	 SWIG_RegisterMapping("_short","_signed_short",0);
	 SWIG_RegisterMapping("_int","_unsigned_int",0);
	 SWIG_RegisterMapping("_int","_signed_int",0);
	 SWIG_RegisterMapping("_class_wxConfig","_wxConfig",0);
}
