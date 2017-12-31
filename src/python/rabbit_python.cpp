#include <Python.h>
#include "rabbit_core.h"

PyObject * _python_log(PyObject * self, PyObject * args) {
    Rabbit * rabbit = new Rabbit();
    const char * arg_0;
    PyArg_ParseTuple(args, "s", &arg_0);
    rabbit->log(arg_0);
    delete rabbit;
    return Py_BuildValue("");
}

PyObject * _python_sleep(PyObject * self, PyObject * args) {
    Rabbit * rabbit = new Rabbit();
    unsigned int arg_0;
    PyArg_ParseTuple(args, "I", &arg_0);
    rabbit->sleep(arg_0);
    delete rabbit;
    return Py_BuildValue("");
}

PyObject * _python_press(PyObject * self, PyObject * args) {
    Rabbit * rabbit = new Rabbit();
    const char * arg_0;
    PyArg_ParseTuple(args, "s", &arg_0);
    rabbit->press(arg_0);
    delete rabbit;
    return Py_BuildValue("");
}

PyObject * _python_input(PyObject * self, PyObject * args) {
    Rabbit * rabbit = new Rabbit();
    const char * arg_0;
    PyArg_ParseTuple(args, "s", &arg_0);
    rabbit->input(arg_0);
    delete rabbit;
    return Py_BuildValue("");
}

PyObject * _python_moveto(PyObject * self, PyObject * args) {
    Rabbit * rabbit = new Rabbit();
    unsigned int arg_0;
    unsigned int arg_1;
    PyArg_ParseTuple(args, "II", &arg_0, &arg_1);
    rabbit->moveto(arg_0 ,arg_1);
    delete rabbit;
    return Py_BuildValue("");
}

PyObject * _python_click(PyObject * self, PyObject * args) {
    Rabbit * rabbit = new Rabbit();
    PyArg_ParseTuple(args, "");
    rabbit->click();
    delete rabbit;
    return Py_BuildValue("");
}

PyObject * _python_doubleclick(PyObject * self, PyObject * args) {
    Rabbit * rabbit = new Rabbit();
    PyArg_ParseTuple(args, "");
    rabbit->doubleclick();
    delete rabbit;
    return Py_BuildValue("");
}

PyObject * _python_rightclick(PyObject * self, PyObject * args) {
    Rabbit * rabbit = new Rabbit();
    PyArg_ParseTuple(args, "");
    rabbit->rightclick();
    delete rabbit;
    return Py_BuildValue("");
}

PyObject * _python_findcolor(PyObject * self, PyObject * args) {
    Rabbit * rabbit = new Rabbit();
    int ret_0;
    int ret_1;
    unsigned int arg_0;
    unsigned int arg_1;
    unsigned int arg_2;
    unsigned int arg_3;
    unsigned int arg_4;
    double arg_5;
    PyArg_ParseTuple(args, "IIIIId", &arg_0, &arg_1, &arg_2, &arg_3, &arg_4, &arg_5);
    rabbit->findcolor(&ret_0 ,&ret_1 ,arg_0 ,arg_1 ,arg_2 ,arg_3 ,arg_4 ,arg_5);
    delete rabbit;
    return Py_BuildValue("ii", ret_0, ret_1);
}

PyObject * _python_findwindow(PyObject * self, PyObject * args) {
    Rabbit * rabbit = new Rabbit();
    long long ret_0;
    const char * arg_0;
    const char * arg_1;
    PyArg_ParseTuple(args, "ss", &arg_0, &arg_1);
    rabbit->findwindow(&ret_0 ,arg_0 ,arg_1);
    delete rabbit;
    return Py_BuildValue("L", ret_0);
}

PyObject * _python_mouse_get_cursor(PyObject * self, PyObject * args) {
    Rabbit * rabbit = new Rabbit();
    unsigned int ret_0;
    PyArg_ParseTuple(args, "");
    rabbit->mouse_get_cursor(&ret_0);
    delete rabbit;
    return Py_BuildValue("I", ret_0);
}

PyObject * _python_mouse_get_cursor_id(PyObject * self, PyObject * args) {
    Rabbit * rabbit = new Rabbit();
    unsigned int ret_0;
    PyArg_ParseTuple(args, "");
    rabbit->mouse_get_cursor_id(&ret_0);
    delete rabbit;
    return Py_BuildValue("I", ret_0);
}

PyObject * _python_mouse_get_cursor_hash(PyObject * self, PyObject * args) {
    Rabbit * rabbit = new Rabbit();
    unsigned int ret_0;
    PyArg_ParseTuple(args, "");
    rabbit->mouse_get_cursor_hash(&ret_0);
    delete rabbit;
    return Py_BuildValue("I", ret_0);
}

PyObject * _python_keyboard_press_vkey(PyObject * self, PyObject * args) {
    Rabbit * rabbit = new Rabbit();
    unsigned int arg_0;
    PyArg_ParseTuple(args, "I", &arg_0);
    rabbit->keyboard_press_vkey(arg_0);
    delete rabbit;
    return Py_BuildValue("");
}

PyObject * _python_window_get_rect(PyObject * self, PyObject * args) {
    Rabbit * rabbit = new Rabbit();
    int ret_0;
    int ret_1;
    int ret_2;
    int ret_3;
    long long arg_0;
    PyArg_ParseTuple(args, "L", &arg_0);
    rabbit->window_get_rect(&ret_0 ,&ret_1 ,&ret_2 ,&ret_3 ,arg_0);
    delete rabbit;
    return Py_BuildValue("iiii", ret_0, ret_1, ret_2, ret_3);
}

PyObject * _python_window_find_focus(PyObject * self, PyObject * args) {
    Rabbit * rabbit = new Rabbit();
    long long ret_0;
    PyArg_ParseTuple(args, "");
    rabbit->window_find_focus(&ret_0);
    delete rabbit;
    return Py_BuildValue("L", ret_0);
}

PyObject * _python_system_hotkey(PyObject * self, PyObject * args) {
    Rabbit * rabbit = new Rabbit();
    int arg_0;
    unsigned int arg_1;
    unsigned int arg_2;
    PyArg_ParseTuple(args, "iII", &arg_0, &arg_1, &arg_2);
    rabbit->system_hotkey(arg_0 ,arg_1 ,arg_2);
    delete rabbit;
    return Py_BuildValue("");
}

PyMethodDef _rabbit_python_methods[] = {
    { "log", _python_log, METH_VARARGS, NULL },
    { "sleep", _python_sleep, METH_VARARGS, NULL },
    { "press", _python_press, METH_VARARGS, NULL },
    { "input", _python_input, METH_VARARGS, NULL },
    { "moveto", _python_moveto, METH_VARARGS, NULL },
    { "click", _python_click, METH_VARARGS, NULL },
    { "doubleclick", _python_doubleclick, METH_VARARGS, NULL },
    { "rightclick", _python_rightclick, METH_VARARGS, NULL },
    { "findcolor", _python_findcolor, METH_VARARGS, NULL },
    { "findwindow", _python_findwindow, METH_VARARGS, NULL },
    { "mouse_get_cursor", _python_mouse_get_cursor, METH_VARARGS, NULL },
    { "mouse_get_cursor_id", _python_mouse_get_cursor_id, METH_VARARGS, NULL },
    { "mouse_get_cursor_hash", _python_mouse_get_cursor_hash, METH_VARARGS, NULL },
    { "keyboard_press_vkey", _python_keyboard_press_vkey, METH_VARARGS, NULL },
    { "window_get_rect", _python_window_get_rect, METH_VARARGS, NULL },
    { "window_find_focus", _python_window_find_focus, METH_VARARGS, NULL },
    { "system_hotkey", _python_system_hotkey, METH_VARARGS, NULL },
    { NULL, NULL, 0, NULL }
};

static struct PyModuleDef rabbit_python = {
    PyModuleDef_HEAD_INIT, "rabbit", NULL, -1,
    _rabbit_python_methods, NULL, NULL, NULL, NULL
};

PyMODINIT_FUNC PyInit_rabbit() {
    return PyModule_Create(&rabbit_python);
};
