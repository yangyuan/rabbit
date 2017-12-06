#include <Python.h>

extern PyMethodDef _rabbit_methods[];

static struct PyModuleDef rabbit_python = {
    PyModuleDef_HEAD_INIT,
    "rabbit",
    NULL,
    -1,
    _rabbit_methods
};


PyMODINIT_FUNC PyInit_rabbit(void)
{
    return PyModule_Create(&rabbit_python);
}