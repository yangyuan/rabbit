#include <lua.hpp>
#include "rabbit_core.h"

int _lua_log(lua_State * L) {
    const char * arg_0 = lua_tostring(L, 1);
    rabbit_log(arg_0);
    return 0;
}

int _lua_sleep(lua_State * L) {
    unsigned int arg_0 = lua_tointeger(L, 1);
    rabbit_sleep(arg_0);
    return 0;
}

int _lua_keypress(lua_State * L) {
    const char * arg_0 = lua_tostring(L, 1);
    rabbit_keypress(arg_0);
    return 0;
}

int _lua_input(lua_State * L) {
    const char * arg_0 = lua_tostring(L, 1);
    rabbit_input(arg_0);
    return 0;
}

int _lua_moveto(lua_State * L) {
    unsigned int arg_0 = lua_tointeger(L, 1);
    unsigned int arg_1 = lua_tointeger(L, 2);
    rabbit_moveto(arg_0 ,arg_1);
    return 0;
}

int _lua_click(lua_State * L) {
    rabbit_click();
    return 0;
}

int _lua_doubleclick(lua_State * L) {
    rabbit_doubleclick();
    return 0;
}

int _lua_rightclick(lua_State * L) {
    rabbit_rightclick();
    return 0;
}

int _lua_findcolor(lua_State * L) {
    int ret_0;
    int ret_1;
    unsigned int arg_0 = lua_tointeger(L, 1);
    unsigned int arg_1 = lua_tointeger(L, 2);
    unsigned int arg_2 = lua_tointeger(L, 3);
    unsigned int arg_3 = lua_tointeger(L, 4);
    unsigned int arg_4 = lua_tointeger(L, 5);
    double arg_5 = lua_tonumber(L, 6);
    rabbit_findcolor(&ret_0 ,&ret_1 ,arg_0 ,arg_1 ,arg_2 ,arg_3 ,arg_4 ,arg_5);
    lua_pushinteger(L, ret_0);
    lua_pushinteger(L, ret_1);
    return 2;
}

int _lua_mouse_fetch_cursor(lua_State * L) {
    unsigned int ret_0;
    rabbit_mouse_fetch_cursor(&ret_0);
    lua_pushinteger(L, ret_0);
    return 1;
}

int _lua_findwindow(lua_State * L) {
    unsigned int ret_0;
    const char * arg_0 = lua_tostring(L, 1);
    rabbit_findwindow(&ret_0 ,arg_0);
    lua_pushinteger(L, ret_0);
    return 1;
}

int _lua_find_window(lua_State * L) {
    unsigned int ret_0;
    const char * arg_0 = lua_tostring(L, 1);
    const char * arg_1 = lua_tostring(L, 2);
    rabbit_find_window(&ret_0 ,arg_0 ,arg_1);
    lua_pushinteger(L, ret_0);
    return 1;
}

int _lua_get_window_rect(lua_State * L) {
    int ret_0;
    int ret_1;
    int ret_2;
    int ret_3;
    unsigned int arg_0 = lua_tointeger(L, 1);
    rabbit_get_window_rect(&ret_0 ,&ret_1 ,&ret_2 ,&ret_3 ,arg_0);
    lua_pushinteger(L, ret_0);
    lua_pushinteger(L, ret_1);
    lua_pushinteger(L, ret_2);
    lua_pushinteger(L, ret_3);
    return 4;
}

luaL_Reg _rabbit_lua_methods[] = {
    { "log", _lua_log },
    { "sleep", _lua_sleep },
    { "keypress", _lua_keypress },
    { "input", _lua_input },
    { "moveto", _lua_moveto },
    { "click", _lua_click },
    { "doubleclick", _lua_doubleclick },
    { "rightclick", _lua_rightclick },
    { "findcolor", _lua_findcolor },
    { "mouse_fetch_cursor", _lua_mouse_fetch_cursor },
    { "findwindow", _lua_findwindow },
    { "find_window", _lua_find_window },
    { "get_window_rect", _lua_get_window_rect },
    { NULL, NULL }
};

void rabbit_init_lua (lua_State * L) {
    luaL_newlib(L, _rabbit_lua_methods);
    lua_setglobal(L, "rabbit");
};
