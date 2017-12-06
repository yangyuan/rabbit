#include "common.h"
#include "rabbit.h"
#include "rabbit_core.h"

PyObject * _python_rabbit_sleep(PyObject * self, PyObject * args) {
    unsigned int arg_0;
    int tupleret = PyArg_ParseTuple(args, "I", &arg_0);
    rabbit_sleep(arg_0);
    return Py_BuildValue("");
}

int _lua_rabbit_sleep(lua_State * L) {
    int argc = lua_gettop(L);
    unsigned int arg_0 = lua_tounsigned(L, 1);
    rabbit_sleep(arg_0);
    return 0;
}

PyObject * _python_rabbit_keypress(PyObject * self, PyObject * args) {
    const char * arg_0;
    int tupleret = PyArg_ParseTuple(args, "s", &arg_0);
    rabbit_keypress(arg_0);
    return Py_BuildValue("");
}

int _lua_rabbit_keypress(lua_State * L) {
    int argc = lua_gettop(L);
    const char * arg_0 = lua_tostring(L, 1);
    rabbit_keypress(arg_0);
    return 0;
}

PyObject * _python_rabbit_input(PyObject * self, PyObject * args) {
    const char * arg_0;
    int tupleret = PyArg_ParseTuple(args, "s", &arg_0);
    rabbit_input(arg_0);
    return Py_BuildValue("");
}

int _lua_rabbit_input(lua_State * L) {
    int argc = lua_gettop(L);
    const char * arg_0 = lua_tostring(L, 1);
    rabbit_input(arg_0);
    return 0;
}

PyObject * _python_rabbit_moveto(PyObject * self, PyObject * args) {
    unsigned int arg_0;
    unsigned int arg_1;
    int tupleret = PyArg_ParseTuple(args, "II", &arg_0, &arg_1);
    rabbit_moveto(arg_0, arg_1);
    return Py_BuildValue("");
}

int _lua_rabbit_moveto(lua_State * L) {
    int argc = lua_gettop(L);
    unsigned int arg_0 = lua_tounsigned(L, 1);
    unsigned int arg_1 = lua_tounsigned(L, 2);
    rabbit_moveto(arg_0, arg_1);
    return 0;
}

PyObject * _python_rabbit_click(PyObject * self, PyObject * args) {
    int tupleret = PyArg_ParseTuple(args, "");
    rabbit_click();
    return Py_BuildValue("");
}

int _lua_rabbit_click(lua_State * L) {
    int argc = lua_gettop(L);
    rabbit_click();
    return 0;
}

PyObject * _python_rabbit_doubleclick(PyObject * self, PyObject * args) {
    int tupleret = PyArg_ParseTuple(args, "");
    rabbit_doubleclick();
    return Py_BuildValue("");
}

int _lua_rabbit_doubleclick(lua_State * L) {
    int argc = lua_gettop(L);
    rabbit_doubleclick();
    return 0;
}

PyObject * _python_rabbit_rightclick(PyObject * self, PyObject * args) {
    int tupleret = PyArg_ParseTuple(args, "");
    rabbit_rightclick();
    return Py_BuildValue("");
}

int _lua_rabbit_rightclick(lua_State * L) {
    int argc = lua_gettop(L);
    rabbit_rightclick();
    return 0;
}

PyObject * _python_rabbit_findcolor(PyObject * self, PyObject * args) {
    int ret_0;
    int ret_1;
    unsigned int arg_0;
    unsigned int arg_1;
    unsigned int arg_2;
    unsigned int arg_3;
    unsigned int arg_4;
    double arg_5;
    int tupleret = PyArg_ParseTuple(args, "IIIIId", &arg_0, &arg_1, &arg_2, &arg_3, &arg_4, &arg_5);
    rabbit_findcolor(&ret_0, &ret_1, arg_0, arg_1, arg_2, arg_3, arg_4, arg_5);
    return Py_BuildValue("ii", ret_0, ret_1);
}

int _lua_rabbit_findcolor(lua_State * L) {
    int argc = lua_gettop(L);
    int ret_0;
    int ret_1;
    unsigned int arg_0 = lua_tounsigned(L, 1);
    unsigned int arg_1 = lua_tounsigned(L, 2);
    unsigned int arg_2 = lua_tounsigned(L, 3);
    unsigned int arg_3 = lua_tounsigned(L, 4);
    unsigned int arg_4 = lua_tounsigned(L, 5);
    double arg_5 = lua_tonumber(L, 6);
    rabbit_findcolor(&ret_0, &ret_1, arg_0, arg_1, arg_2, arg_3, arg_4, arg_5);
    lua_pushinteger(L, ret_0);
    lua_pushinteger(L, ret_1);
    return 2;
}

PyObject * _python_rabbit_mouse_fetch_cursor(PyObject * self, PyObject * args) {
    unsigned int ret_0;
    int tupleret = PyArg_ParseTuple(args, "");
    rabbit_mouse_fetch_cursor(&ret_0);
    return Py_BuildValue("I", ret_0);
}

int _lua_rabbit_mouse_fetch_cursor(lua_State * L) {
    int argc = lua_gettop(L);
    unsigned int ret_0;
    rabbit_mouse_fetch_cursor(&ret_0);
    lua_pushunsigned(L, ret_0);
    return 1;
}

PyObject * _python_rabbit_findwindow(PyObject * self, PyObject * args) {
    unsigned int ret_0;
    const char * arg_0;
    int tupleret = PyArg_ParseTuple(args, "s", &arg_0);
    rabbit_findwindow(&ret_0, arg_0);
    return Py_BuildValue("I", ret_0);
}

int _lua_rabbit_findwindow(lua_State * L) {
    int argc = lua_gettop(L);
    unsigned int ret_0;
    const char * arg_0 = lua_tostring(L, 1);
    rabbit_findwindow(&ret_0, arg_0);
    lua_pushunsigned(L, ret_0);
    return 1;
}

PyObject * _python_rabbit_find_window(PyObject * self, PyObject * args) {
    unsigned int ret_0;
    const char * arg_0;
    const char * arg_1;
    int tupleret = PyArg_ParseTuple(args, "ss", &arg_0, &arg_1);
    rabbit_find_window(&ret_0, arg_0, arg_1);
    return Py_BuildValue("I", ret_0);
}

int _lua_rabbit_find_window(lua_State * L) {
    int argc = lua_gettop(L);
    unsigned int ret_0;
    const char * arg_0 = lua_tostring(L, 1);
    const char * arg_1 = lua_tostring(L, 2);
    rabbit_find_window(&ret_0, arg_0, arg_1);
    lua_pushunsigned(L, ret_0);
    return 1;
}

PyObject * _python_rabbit_get_window_rect(PyObject * self, PyObject * args) {
    int ret_0;
    int ret_1;
    int ret_2;
    int ret_3;
    unsigned int arg_0;
    int tupleret = PyArg_ParseTuple(args, "I", &arg_0);
    rabbit_get_window_rect(&ret_0, &ret_1, &ret_2, &ret_3, arg_0);
    return Py_BuildValue("iiii", ret_0, ret_1, ret_2, ret_3);
}

int _lua_rabbit_get_window_rect(lua_State * L) {
    int argc = lua_gettop(L);
    int ret_0;
    int ret_1;
    int ret_2;
    int ret_3;
    unsigned int arg_0 = lua_tounsigned(L, 1);
    rabbit_get_window_rect(&ret_0, &ret_1, &ret_2, &ret_3, arg_0);
    lua_pushinteger(L, ret_0);
    lua_pushinteger(L, ret_1);
    lua_pushinteger(L, ret_2);
    lua_pushinteger(L, ret_3);
    return 4;
}

luaL_Reg _rabbit_lib[] = {
    { "sleep", _lua_rabbit_sleep },
    { "keypress", _lua_rabbit_keypress },
    { "input", _lua_rabbit_input },
    { "moveto", _lua_rabbit_moveto },
    { "click", _lua_rabbit_click },
    { "doubleclick", _lua_rabbit_doubleclick },
    { "rightclick", _lua_rabbit_rightclick },
    { "findcolor", _lua_rabbit_findcolor },
    { "mouse_fetch_cursor", _lua_rabbit_mouse_fetch_cursor },
    { "findwindow", _lua_rabbit_findwindow },
    { "find_window", _lua_rabbit_find_window },
    { "get_window_rect", _lua_rabbit_get_window_rect },
    { NULL, NULL }
};

PyMethodDef _rabbit_defs[] = {
    { "sleep", _python_rabbit_sleep, METH_VARARGS, NULL },
    { "keypress", _python_rabbit_keypress, METH_VARARGS, NULL },
    { "input", _python_rabbit_input, METH_VARARGS, NULL },
    { "moveto", _python_rabbit_moveto, METH_VARARGS, NULL },
    { "click", _python_rabbit_click, METH_VARARGS, NULL },
    { "doubleclick", _python_rabbit_doubleclick, METH_VARARGS, NULL },
    { "rightclick", _python_rabbit_rightclick, METH_VARARGS, NULL },
    { "findcolor", _python_rabbit_findcolor, METH_VARARGS, NULL },
    { "mouse_fetch_cursor", _python_rabbit_mouse_fetch_cursor, METH_VARARGS, NULL },
    { "findwindow", _python_rabbit_findwindow, METH_VARARGS, NULL },
    { "find_window", _python_rabbit_find_window, METH_VARARGS, NULL },
    { "get_window_rect", _python_rabbit_get_window_rect, METH_VARARGS, NULL },
    { NULL, NULL, 0, NULL }
};

void rabbit_init(RABBIT_MODE mode, void * instance) {
    if (mode == RABBIT_MODE_LUA) {
        lua_State * L = (lua_State *)instance;
        luaL_newlib(L, _rabbit_lib);
        lua_setglobal(L, "rabbit");
    }
    else {
        Py_InitModule("rabbit", _rabbit_defs);
        PyRun_SimpleString("import rabbit");
    }
}
