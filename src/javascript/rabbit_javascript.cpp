#include <v8.h>
#include "rabbit_node.h"
#include "rabbit_core.h"

using namespace v8;

void _javascript_log(const FunctionCallbackInfo<Value>& args) {
    RabbitCore * rabbit = new RabbitCore();
    Isolate* isolate = args.GetIsolate();
    const char * arg_0 = _javascript_to_string(rabbit, args, 0);
    rabbit_log(arg_0);
    delete rabbit;
}

void _javascript_sleep(const FunctionCallbackInfo<Value>& args) {
    RabbitCore * rabbit = new RabbitCore();
    Isolate* isolate = args.GetIsolate();
    unsigned int arg_0 = _javascript_to_uint32(rabbit, args, 0);
    rabbit_sleep(arg_0);
    delete rabbit;
}

void _javascript_keypress(const FunctionCallbackInfo<Value>& args) {
    RabbitCore * rabbit = new RabbitCore();
    Isolate* isolate = args.GetIsolate();
    const char * arg_0 = _javascript_to_string(rabbit, args, 0);
    rabbit_keypress(arg_0);
    delete rabbit;
}

void _javascript_input(const FunctionCallbackInfo<Value>& args) {
    RabbitCore * rabbit = new RabbitCore();
    Isolate* isolate = args.GetIsolate();
    const char * arg_0 = _javascript_to_string(rabbit, args, 0);
    rabbit_input(arg_0);
    delete rabbit;
}

void _javascript_moveto(const FunctionCallbackInfo<Value>& args) {
    RabbitCore * rabbit = new RabbitCore();
    Isolate* isolate = args.GetIsolate();
    unsigned int arg_0 = _javascript_to_uint32(rabbit, args, 0);
    unsigned int arg_1 = _javascript_to_uint32(rabbit, args, 1);
    rabbit_moveto(arg_0 ,arg_1);
    delete rabbit;
}

void _javascript_click(const FunctionCallbackInfo<Value>& args) {
    RabbitCore * rabbit = new RabbitCore();
    Isolate* isolate = args.GetIsolate();
    rabbit_click();
    delete rabbit;
}

void _javascript_doubleclick(const FunctionCallbackInfo<Value>& args) {
    RabbitCore * rabbit = new RabbitCore();
    Isolate* isolate = args.GetIsolate();
    rabbit_doubleclick();
    delete rabbit;
}

void _javascript_rightclick(const FunctionCallbackInfo<Value>& args) {
    RabbitCore * rabbit = new RabbitCore();
    Isolate* isolate = args.GetIsolate();
    rabbit_rightclick();
    delete rabbit;
}

void _javascript_findcolor(const FunctionCallbackInfo<Value>& args) {
    RabbitCore * rabbit = new RabbitCore();
    Isolate* isolate = args.GetIsolate();
    int ret_0;
    int ret_1;
    unsigned int arg_0 = _javascript_to_uint32(rabbit, args, 0);
    unsigned int arg_1 = _javascript_to_uint32(rabbit, args, 1);
    unsigned int arg_2 = _javascript_to_uint32(rabbit, args, 2);
    unsigned int arg_3 = _javascript_to_uint32(rabbit, args, 3);
    unsigned int arg_4 = _javascript_to_uint32(rabbit, args, 4);
    double arg_5 = _javascript_to_double(rabbit, args, 5);
    rabbit_findcolor(&ret_0 ,&ret_1 ,arg_0 ,arg_1 ,arg_2 ,arg_3 ,arg_4 ,arg_5);
    Handle<Array> ret = Array::New(isolate, 2);
    ret->Set(0, _javascript_to_int32_value(isolate, ret_0));
    ret->Set(1, _javascript_to_int32_value(isolate, ret_1));
    args.GetReturnValue().Set(ret);
    delete rabbit;
}

void _javascript_mouse_fetch_cursor(const FunctionCallbackInfo<Value>& args) {
    RabbitCore * rabbit = new RabbitCore();
    Isolate* isolate = args.GetIsolate();
    unsigned int ret_0;
    rabbit_mouse_fetch_cursor(&ret_0);
    Local<Value> ret = _javascript_to_uint32_value(isolate, ret_0);
    args.GetReturnValue().Set(ret);
    delete rabbit;
}

void _javascript_findwindow(const FunctionCallbackInfo<Value>& args) {
    RabbitCore * rabbit = new RabbitCore();
    Isolate* isolate = args.GetIsolate();
    unsigned int ret_0;
    const char * arg_0 = _javascript_to_string(rabbit, args, 0);
    rabbit_findwindow(&ret_0 ,arg_0);
    Local<Value> ret = _javascript_to_uint32_value(isolate, ret_0);
    args.GetReturnValue().Set(ret);
    delete rabbit;
}

void _javascript_find_window(const FunctionCallbackInfo<Value>& args) {
    RabbitCore * rabbit = new RabbitCore();
    Isolate* isolate = args.GetIsolate();
    unsigned int ret_0;
    const char * arg_0 = _javascript_to_string(rabbit, args, 0);
    const char * arg_1 = _javascript_to_string(rabbit, args, 1);
    rabbit_find_window(&ret_0 ,arg_0 ,arg_1);
    Local<Value> ret = _javascript_to_uint32_value(isolate, ret_0);
    args.GetReturnValue().Set(ret);
    delete rabbit;
}

void _javascript_get_window_rect(const FunctionCallbackInfo<Value>& args) {
    RabbitCore * rabbit = new RabbitCore();
    Isolate* isolate = args.GetIsolate();
    int ret_0;
    int ret_1;
    int ret_2;
    int ret_3;
    unsigned int arg_0 = _javascript_to_uint32(rabbit, args, 0);
    rabbit_get_window_rect(&ret_0 ,&ret_1 ,&ret_2 ,&ret_3 ,arg_0);
    Handle<Array> ret = Array::New(isolate, 4);
    ret->Set(0, _javascript_to_int32_value(isolate, ret_0));
    ret->Set(1, _javascript_to_int32_value(isolate, ret_1));
    ret->Set(2, _javascript_to_int32_value(isolate, ret_2));
    ret->Set(3, _javascript_to_int32_value(isolate, ret_3));
    args.GetReturnValue().Set(ret);
    delete rabbit;
}

void _rabbit_javascript_init(Local<Object> exports) {
    NODE_SET_METHOD(exports, "log", _javascript_log);
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

Local<Data> rabbit_javascript(Isolate* isolate) {
    Local<ObjectTemplate> rabbit = ObjectTemplate::New(isolate);
    rabbit->Set(String::NewFromUtf8(isolate, "log"), FunctionTemplate::New(isolate, _javascript_log));
    rabbit->Set(String::NewFromUtf8(isolate, "sleep"), FunctionTemplate::New(isolate, _javascript_sleep));
    rabbit->Set(String::NewFromUtf8(isolate, "keypress"), FunctionTemplate::New(isolate, _javascript_keypress));
    rabbit->Set(String::NewFromUtf8(isolate, "input"), FunctionTemplate::New(isolate, _javascript_input));
    rabbit->Set(String::NewFromUtf8(isolate, "moveto"), FunctionTemplate::New(isolate, _javascript_moveto));
    rabbit->Set(String::NewFromUtf8(isolate, "click"), FunctionTemplate::New(isolate, _javascript_click));
    rabbit->Set(String::NewFromUtf8(isolate, "doubleclick"), FunctionTemplate::New(isolate, _javascript_doubleclick));
    rabbit->Set(String::NewFromUtf8(isolate, "rightclick"), FunctionTemplate::New(isolate, _javascript_rightclick));
    rabbit->Set(String::NewFromUtf8(isolate, "findcolor"), FunctionTemplate::New(isolate, _javascript_findcolor));
    rabbit->Set(String::NewFromUtf8(isolate, "mouse_fetch_cursor"), FunctionTemplate::New(isolate, _javascript_mouse_fetch_cursor));
    rabbit->Set(String::NewFromUtf8(isolate, "findwindow"), FunctionTemplate::New(isolate, _javascript_findwindow));
    rabbit->Set(String::NewFromUtf8(isolate, "find_window"), FunctionTemplate::New(isolate, _javascript_find_window));
    rabbit->Set(String::NewFromUtf8(isolate, "get_window_rect"), FunctionTemplate::New(isolate, _javascript_get_window_rect));
    return rabbit;
};
