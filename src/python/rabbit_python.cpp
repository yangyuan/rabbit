#include <Python.h>
#include "rabbit_core.h"

PyObject * _python_log(PyObject * self, PyObject * args) {
    const char * arg_0;
    PyArg_ParseTuple(args, "s", &arg_0);
    rabbit_log(arg_0);
    return Py_BuildValue("");
}

PyObject * _python_sleep(PyObject * self, PyObject * args) {
    unsigned int arg_0;
    PyArg_ParseTuple(args, "I", &arg_0);
    rabbit_sleep(arg_0);
    return Py_BuildValue("");
}

PyObject * _python_keypress(PyObject * self, PyObject * args) {
    const char * arg_0;
    PyArg_ParseTuple(args, "s", &arg_0);
    rabbit_keypress(arg_0);
    return Py_BuildValue("");
}

PyObject * _python_input(PyObject * self, PyObject * args) {
    const char * arg_0;
    PyArg_ParseTuple(args, "s", &arg_0);
    rabbit_input(arg_0);
    return Py_BuildValue("");
}

PyObject * _python_moveto(PyObject * self, PyObject * args) {
    unsigned int arg_0;
    unsigned int arg_1;
    PyArg_ParseTuple(args, "II", &arg_0, &arg_1);
    rabbit_moveto(arg_0 ,arg_1);
    return Py_BuildValue("");
}

PyObject * _python_click(PyObject * self, PyObject * args) {
    PyArg_ParseTuple(args, "");
    rabbit_click();
    return Py_BuildValue("");
}

PyObject * _python_doubleclick(PyObject * self, PyObject * args) {
    PyArg_ParseTuple(args, "");
    rabbit_doubleclick();
    return Py_BuildValue("");
}

PyObject * _python_rightclick(PyObject * self, PyObject * args) {
    PyArg_ParseTuple(args, "");
    rabbit_rightclick();
    return Py_BuildValue("");
}

PyObject * _python_findcolor(PyObject * self, PyObject * args) {
    int ret_0;
    int ret_1;
    unsigned int arg_0;
    unsigned int arg_1;
    unsigned int arg_2;
    unsigned int arg_3;
    unsigned int arg_4;
    double arg_5;
    PyArg_ParseTuple(args, "IIIIId", &arg_0, &arg_1, &arg_2, &arg_3, &arg_4, &arg_5);
    rabbit_findcolor(&ret_0 ,&ret_1 ,arg_0 ,arg_1 ,arg_2 ,arg_3 ,arg_4 ,arg_5);
    return Py_BuildValue("ii", ret_0, ret_1);
}

PyObject * _python_mouse_fetch_cursor(PyObject * self, PyObject * args) {
    unsigned int ret_0;
    PyArg_ParseTuple(args, "");
    rabbit_mouse_fetch_cursor(&ret_0);
    return Py_BuildValue("I", ret_0);
}

PyObject * _python_findwindow(PyObject * self, PyObject * args) {
    unsigned int ret_0;
    const char * arg_0;
    PyArg_ParseTuple(args, "s", &arg_0);
    rabbit_findwindow(&ret_0 ,arg_0);
    return Py_BuildValue("I", ret_0);
}

PyObject * _python_find_window(PyObject * self, PyObject * args) {
    unsigned int ret_0;
    const char * arg_0;
    const char * arg_1;
    PyArg_ParseTuple(args, "ss", &arg_0, &arg_1);
    rabbit_find_window(&ret_0 ,arg_0 ,arg_1);
    return Py_BuildValue("I", ret_0);
}

PyObject * _python_get_window_rect(PyObject * self, PyObject * args) {
    int ret_0;
    int ret_1;
    int ret_2;
    int ret_3;
    unsigned int arg_0;
    PyArg_ParseTuple(args, "I", &arg_0);
    rabbit_get_window_rect(&ret_0 ,&ret_1 ,&ret_2 ,&ret_3 ,arg_0);
    return Py_BuildValue("iiii", ret_0, ret_1, ret_2, ret_3);
}

PyMethodDef _rabbit_python_methods[] = {
    { "log", _python_log, METH_VARARGS, NULL },
    { "sleep", _python_sleep, METH_VARARGS, NULL },
    { "keypress", _python_keypress, METH_VARARGS, NULL },
    { "input", _python_input, METH_VARARGS, NULL },
    { "moveto", _python_moveto, METH_VARARGS, NULL },
    { "click", _python_click, METH_VARARGS, NULL },
    { "doubleclick", _python_doubleclick, METH_VARARGS, NULL },
    { "rightclick", _python_rightclick, METH_VARARGS, NULL },
    { "findcolor", _python_findcolor, METH_VARARGS, NULL },
    { "mouse_fetch_cursor", _python_mouse_fetch_cursor, METH_VARARGS, NULL },
    { "findwindow", _python_findwindow, METH_VARARGS, NULL },
    { "find_window", _python_find_window, METH_VARARGS, NULL },
    { "get_window_rect", _python_get_window_rect, METH_VARARGS, NULL },
    { NULL, NULL, 0, NULL }
};

static struct PyModuleDef rabbit_python = {
    PyModuleDef_HEAD_INIT, "rabbit", NULL, -1,
    _rabbit_python_methods, NULL, NULL, NULL, NULL
};

PyObject * PyInit_rabbit() {
    return PyModule_Create(&rabbit_python);
};
