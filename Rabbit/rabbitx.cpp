#include "common.h"
#include "rabbit.h"
#include "rabbit_core.h"

int _lua_rabbit_keypress(lua_State *L)
{
	const char * keychar;
	int argc = lua_gettop(L);
	if (argc != 1) return 0;
	keychar = lua_tostring(L, 1);
	rabbit_keypress(keychar);
	return 0;
}

PyObject * _python_rabbit_keypress(PyObject *self, PyObject *args) {
	char * keychar;
	int tupleret = PyArg_ParseTuple(args, "s", &keychar);
	rabbit_keypress(keychar);
	return Py_BuildValue("");
}

int _lua_rabbit_sleep(lua_State *L)
{
	unsigned int milliseconds;
	int argc = lua_gettop(L);
	if (argc != 1) return 0;
	milliseconds = lua_tounsigned(L, 1);
	rabbit_sleep(milliseconds);
	return 0;
}

PyObject * _python_rabbit_sleep(PyObject *self, PyObject *args) {
	unsigned int milliseconds;
	int tupleret = PyArg_ParseTuple(args, "I", &milliseconds);
	rabbit_sleep(milliseconds);
	return Py_BuildValue("");
}

int _lua_rabbit_click(lua_State *L) { rabbit_click(); return 0; }
PyObject * _python_rabbit_click(PyObject *self, PyObject *args) { rabbit_click(); return Py_BuildValue(""); }

int _lua_rabbit_rightclick(lua_State *L) { rabbit_rightclick(); return 0; }
PyObject * _python_rabbit_rightclick(PyObject *self, PyObject *args) { rabbit_rightclick(); return Py_BuildValue(""); }

int _lua_rabbit_doubleclick(lua_State *L) { rabbit_doubleclick(); return 0; }
PyObject * _python_rabbit_doubleclick(PyObject *self, PyObject *args) { rabbit_doubleclick(); return Py_BuildValue(""); }

int _lua_rabbit_moveto(lua_State *L) {
	unsigned int x;
	unsigned int y;
	int argc = lua_gettop(L);
	if (argc != 2) return 0;
	x = lua_tounsigned(L, 1);
	y = lua_tounsigned(L, 2);
	rabbit_moveto(x, y);
	return 0;
}

PyObject * _python_rabbit_moveto(PyObject *self, PyObject *args) {
	unsigned int x;
	unsigned int y;
	int tupleret = PyArg_ParseTuple(args, "II", &x, &y);
	rabbit_moveto(x, y);
	return Py_BuildValue("");
}

int _lua_rabbit_findcolor(lua_State *L) {
	unsigned int color;
	unsigned int x;
	unsigned int y;
	unsigned int w;
	unsigned int h;
	unsigned int order;
	double tolerance;

	
	int argc = lua_gettop(L);
	if (argc != 7) return 0;
	color = lua_tounsigned(L, 1);
	x = lua_tounsigned(L, 2);
	y = lua_tounsigned(L, 3);
	w = lua_tounsigned(L, 4);
	h = lua_tounsigned(L, 5);
	order = lua_tounsigned(L, 6);
	tolerance = lua_tonumber(L, 7);

	int ret_x;
	int ret_y;
	rabbit_findcolor(&ret_x, &ret_y, color, x, y, w, h, order, tolerance);
	lua_pushinteger(L, ret_x);
	lua_pushinteger(L, ret_y);
	return 2;
}



PyObject * _python_rabbit_findcolor(PyObject *self, PyObject *args) {
	unsigned int color;
	unsigned int x;
	unsigned int y;
	unsigned int w;
	unsigned int h;
	unsigned int order;
	double tolerance;
	int tupleret = PyArg_ParseTuple(args, "IIIIIId", &color, &x, &y, &w, &h, &order, &tolerance);
	int ret_x;
	int ret_y;
	rabbit_findcolor(&ret_x, &ret_y, color, x, y, w, h, order, tolerance);
	return Py_BuildValue("ii", ret_x, ret_y);
}

PyObject * _python_rabbit_get_cursor_hash(PyObject *self, PyObject *args) {
	unsigned int ret;
	rabbit_get_cursor_hash(&ret);
	return Py_BuildValue("I", ret);
}



luaL_Reg rabbitlib[] = {
	{ "keypress", _lua_rabbit_keypress },
	{ "sleep", _lua_rabbit_sleep },
	{ "click", _lua_rabbit_click },
	{ "rightclick", _lua_rabbit_rightclick },
	{ "doubleclick", _lua_rabbit_doubleclick },
	{ "moveto", _lua_rabbit_moveto },
	{ "findcolor", _lua_rabbit_findcolor },
	{ NULL, NULL }
};

PyMethodDef rabbitdefs[] = {
	{ "keypress", _python_rabbit_keypress, METH_VARARGS, NULL },
	{ "sleep", _python_rabbit_sleep, METH_VARARGS, NULL },
	{ "click", _python_rabbit_click, METH_VARARGS, NULL },
	{ "rightclick", _python_rabbit_rightclick, METH_VARARGS, NULL },
	{ "doubleclick", _python_rabbit_doubleclick, METH_VARARGS, NULL },
	{ "moveto", _python_rabbit_moveto, METH_VARARGS, NULL },
	{ "findcolor", _python_rabbit_findcolor, METH_VARARGS, NULL },
	{ "get_cursor_hash", _python_rabbit_get_cursor_hash, METH_VARARGS, NULL },
	
	{ NULL, NULL, 0, NULL }
};

void rabbit_init(RABBIT_MODE mode, void * instance) {
	if (mode == RABBIT_MODE_LUA) {
		lua_State * L = (lua_State *)instance;
		luaL_newlib(L, rabbitlib);
		lua_setglobal(L, "rabbit");
	}
	else {
		Py_InitModule("rabbit", rabbitdefs);
		PyRun_SimpleString("import rabbit");
	}
}
