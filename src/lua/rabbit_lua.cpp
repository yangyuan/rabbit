#include <lua.hpp>
#include "rabbit_core.h"

int _lua_log(lua_State * L) {
    Rabbit * rabbit = new Rabbit();
    const char * arg_0 = lua_tostring(L, 1);
    rabbit->log(arg_0);
    delete rabbit;
    return 0;
}

int _lua_sleep(lua_State * L) {
    Rabbit * rabbit = new Rabbit();
    unsigned int arg_0 = lua_tointeger(L, 1);
    rabbit->sleep(arg_0);
    delete rabbit;
    return 0;
}

int _lua_press(lua_State * L) {
    Rabbit * rabbit = new Rabbit();
    const char * arg_0 = lua_tostring(L, 1);
    rabbit->press(arg_0);
    delete rabbit;
    return 0;
}

int _lua_input(lua_State * L) {
    Rabbit * rabbit = new Rabbit();
    const char * arg_0 = lua_tostring(L, 1);
    rabbit->input(arg_0);
    delete rabbit;
    return 0;
}

int _lua_moveto(lua_State * L) {
    Rabbit * rabbit = new Rabbit();
    unsigned int arg_0 = lua_tointeger(L, 1);
    unsigned int arg_1 = lua_tointeger(L, 2);
    rabbit->moveto(arg_0 ,arg_1);
    delete rabbit;
    return 0;
}

int _lua_click(lua_State * L) {
    Rabbit * rabbit = new Rabbit();
    rabbit->click();
    delete rabbit;
    return 0;
}

int _lua_doubleclick(lua_State * L) {
    Rabbit * rabbit = new Rabbit();
    rabbit->doubleclick();
    delete rabbit;
    return 0;
}

int _lua_rightclick(lua_State * L) {
    Rabbit * rabbit = new Rabbit();
    rabbit->rightclick();
    delete rabbit;
    return 0;
}

int _lua_findcolor(lua_State * L) {
    Rabbit * rabbit = new Rabbit();
    int ret_0;
    int ret_1;
    unsigned int arg_0 = lua_tointeger(L, 1);
    unsigned int arg_1 = lua_tointeger(L, 2);
    unsigned int arg_2 = lua_tointeger(L, 3);
    unsigned int arg_3 = lua_tointeger(L, 4);
    unsigned int arg_4 = lua_tointeger(L, 5);
    double arg_5 = lua_tonumber(L, 6);
    rabbit->findcolor(&ret_0 ,&ret_1 ,arg_0 ,arg_1 ,arg_2 ,arg_3 ,arg_4 ,arg_5);
    lua_pushinteger(L, ret_0);
    lua_pushinteger(L, ret_1);
    delete rabbit;
    return 2;
}

int _lua_findwindow(lua_State * L) {
    Rabbit * rabbit = new Rabbit();
    long long ret_0;
    const char * arg_0 = lua_tostring(L, 1);
    const char * arg_1 = lua_tostring(L, 2);
    rabbit->findwindow(&ret_0 ,arg_0 ,arg_1);
    lua_pushinteger(L, ret_0);
    delete rabbit;
    return 1;
}

int _lua_mouse_get_cursor(lua_State * L) {
    Rabbit * rabbit = new Rabbit();
    unsigned int ret_0;
    rabbit->mouse_get_cursor(&ret_0);
    lua_pushinteger(L, ret_0);
    delete rabbit;
    return 1;
}

int _lua_mouse_get_cursor_id(lua_State * L) {
    Rabbit * rabbit = new Rabbit();
    unsigned int ret_0;
    rabbit->mouse_get_cursor_id(&ret_0);
    lua_pushinteger(L, ret_0);
    delete rabbit;
    return 1;
}

int _lua_mouse_get_cursor_hash(lua_State * L) {
    Rabbit * rabbit = new Rabbit();
    unsigned int ret_0;
    rabbit->mouse_get_cursor_hash(&ret_0);
    lua_pushinteger(L, ret_0);
    delete rabbit;
    return 1;
}

int _lua_keyboard_press_vkey(lua_State * L) {
    Rabbit * rabbit = new Rabbit();
    unsigned int arg_0 = lua_tointeger(L, 1);
    rabbit->keyboard_press_vkey(arg_0);
    delete rabbit;
    return 0;
}

int _lua_window_get_rect(lua_State * L) {
    Rabbit * rabbit = new Rabbit();
    int ret_0;
    int ret_1;
    int ret_2;
    int ret_3;
    long long arg_0 = lua_tointeger(L, 1);
    rabbit->window_get_rect(&ret_0 ,&ret_1 ,&ret_2 ,&ret_3 ,arg_0);
    lua_pushinteger(L, ret_0);
    lua_pushinteger(L, ret_1);
    lua_pushinteger(L, ret_2);
    lua_pushinteger(L, ret_3);
    delete rabbit;
    return 4;
}

int _lua_window_find_focus(lua_State * L) {
    Rabbit * rabbit = new Rabbit();
    long long ret_0;
    rabbit->window_find_focus(&ret_0);
    lua_pushinteger(L, ret_0);
    delete rabbit;
    return 1;
}

luaL_Reg _rabbit_lua_methods[] = {
    { "log", _lua_log },
    { "sleep", _lua_sleep },
    { "press", _lua_press },
    { "input", _lua_input },
    { "moveto", _lua_moveto },
    { "click", _lua_click },
    { "doubleclick", _lua_doubleclick },
    { "rightclick", _lua_rightclick },
    { "findcolor", _lua_findcolor },
    { "findwindow", _lua_findwindow },
    { "mouse_get_cursor", _lua_mouse_get_cursor },
    { "mouse_get_cursor_id", _lua_mouse_get_cursor_id },
    { "mouse_get_cursor_hash", _lua_mouse_get_cursor_hash },
    { "keyboard_press_vkey", _lua_keyboard_press_vkey },
    { "window_get_rect", _lua_window_get_rect },
    { "window_find_focus", _lua_window_find_focus },
    { NULL, NULL }
};

void rabbit_init_lua (lua_State * L) {
    luaL_newlib(L, _rabbit_lua_methods);
    lua_setglobal(L, "rabbit");
};
