#include <node.h>
#include "rabbit_core.h"

using namespace v8;

void _javascript_sleep(const FunctionCallbackInfo<Value>& args) {
    unsigned int arg_0 = _javascript_to_uint32(args, 1);
    rabbit_sleep(arg_0);
}

void _javascript_keypress(const FunctionCallbackInfo<Value>& args) {
    const char * arg_0 = _javascript_to_string(args, 1);
    rabbit_keypress(arg_0);
}

void _javascript_input(const FunctionCallbackInfo<Value>& args) {
    const char * arg_0 = _javascript_to_string(args, 1);
    rabbit_input(arg_0);
}

void _javascript_moveto(const FunctionCallbackInfo<Value>& args) {
    unsigned int arg_0 = _javascript_to_uint32(args, 1);
    unsigned int arg_1 = _javascript_to_uint32(args, 2);
    rabbit_moveto(arg_0 ,arg_1);
}

void _javascript_click(const FunctionCallbackInfo<Value>& args) {
    rabbit_click();
}

void _javascript_doubleclick(const FunctionCallbackInfo<Value>& args) {
    rabbit_doubleclick();
}

void _javascript_rightclick(const FunctionCallbackInfo<Value>& args) {
    rabbit_rightclick();
}

void _javascript_findcolor(const FunctionCallbackInfo<Value>& args) {
    int ret_0;
    int ret_1;
    unsigned int arg_0 = _javascript_to_uint32(args, 1);
    unsigned int arg_1 = _javascript_to_uint32(args, 2);
    unsigned int arg_2 = _javascript_to_uint32(args, 3);
    unsigned int arg_3 = _javascript_to_uint32(args, 4);
    unsigned int arg_4 = _javascript_to_uint32(args, 5);
    double arg_5 = _javascript_to_number(args, 6);
    rabbit_findcolor(&ret_0 ,&ret_1 ,arg_0 ,arg_1 ,arg_2 ,arg_3 ,arg_4 ,arg_5);
    Handle<Array> ret = Array::New(2);
    ret->Set(0, _javascript_to_int32_value(ret_0));
    ret->Set(1, _javascript_to_int32_value(ret_1));
    args.GetReturnValue().Set(ret);
}

void _javascript_mouse_fetch_cursor(const FunctionCallbackInfo<Value>& args) {
    unsigned int ret_0;
    rabbit_mouse_fetch_cursor(&ret_0);
    Value ret = _javascript_to_uint32_value(ret_0);
    args.GetReturnValue().Set(ret);
}

void _javascript_findwindow(const FunctionCallbackInfo<Value>& args) {
    unsigned int ret_0;
    const char * arg_0 = _javascript_to_string(args, 1);
    rabbit_findwindow(&ret_0 ,arg_0);
    Value ret = _javascript_to_uint32_value(ret_0);
    args.GetReturnValue().Set(ret);
}

void _javascript_find_window(const FunctionCallbackInfo<Value>& args) {
    unsigned int ret_0;
    const char * arg_0 = _javascript_to_string(args, 1);
    const char * arg_1 = _javascript_to_string(args, 2);
    rabbit_find_window(&ret_0 ,arg_0 ,arg_1);
    Value ret = _javascript_to_uint32_value(ret_0);
    args.GetReturnValue().Set(ret);
}

void _javascript_get_window_rect(const FunctionCallbackInfo<Value>& args) {
    int ret_0;
    int ret_1;
    int ret_2;
    int ret_3;
    unsigned int arg_0 = _javascript_to_uint32(args, 1);
    rabbit_get_window_rect(&ret_0 ,&ret_1 ,&ret_2 ,&ret_3 ,arg_0);
    Handle<Array> ret = Array::New(4);
    ret->Set(0, _javascript_to_int32_value(ret_0));
    ret->Set(1, _javascript_to_int32_value(ret_1));
    ret->Set(2, _javascript_to_int32_value(ret_2));
    ret->Set(3, _javascript_to_int32_value(ret_3));
    args.GetReturnValue().Set(ret);
}

void _rabbit_javascript_init(Local<Object> exports) {
    NODE_SET_METHOD(exports, "sleep", _javascript_sleep);
    NODE_SET_METHOD(exports, "keypress", _javascript_keypress);
    NODE_SET_METHOD(exports, "input", _javascript_input);
    NODE_SET_METHOD(exports, "moveto", _javascript_moveto);
    NODE_SET_METHOD(exports, "click", _javascript_click);
    NODE_SET_METHOD(exports, "doubleclick", _javascript_doubleclick);
    NODE_SET_METHOD(exports, "rightclick", _javascript_rightclick);
    NODE_SET_METHOD(exports, "findcolor", _javascript_findcolor);
    NODE_SET_METHOD(exports, "mouse_fetch_cursor", _javascript_mouse_fetch_cursor);
    NODE_SET_METHOD(exports, "findwindow", _javascript_findwindow);
    NODE_SET_METHOD(exports, "find_window", _javascript_find_window);
    NODE_SET_METHOD(exports, "get_window_rect", _javascript_get_window_rect);
};
