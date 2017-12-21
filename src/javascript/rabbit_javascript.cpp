#include <v8.h>
#include "rabbit_node.h"
#include "rabbit_core.h"

using namespace v8;

void _javascript_log(const FunctionCallbackInfo<Value>& args) {
    Rabbit * rabbit = new Rabbit();
    Isolate* isolate = args.GetIsolate();
    const char * arg_0 = _javascript_to_string(rabbit, args, 0);
    rabbit->log(arg_0);
    delete rabbit;
}

void _javascript_sleep(const FunctionCallbackInfo<Value>& args) {
    Rabbit * rabbit = new Rabbit();
    Isolate* isolate = args.GetIsolate();
    unsigned int arg_0 = _javascript_to_uint32(rabbit, args, 0);
    rabbit->sleep(arg_0);
    delete rabbit;
}

void _javascript_press(const FunctionCallbackInfo<Value>& args) {
    Rabbit * rabbit = new Rabbit();
    Isolate* isolate = args.GetIsolate();
    const char * arg_0 = _javascript_to_string(rabbit, args, 0);
    rabbit->press(arg_0);
    delete rabbit;
}

void _javascript_input(const FunctionCallbackInfo<Value>& args) {
    Rabbit * rabbit = new Rabbit();
    Isolate* isolate = args.GetIsolate();
    const char * arg_0 = _javascript_to_string(rabbit, args, 0);
    rabbit->input(arg_0);
    delete rabbit;
}

void _javascript_moveto(const FunctionCallbackInfo<Value>& args) {
    Rabbit * rabbit = new Rabbit();
    Isolate* isolate = args.GetIsolate();
    unsigned int arg_0 = _javascript_to_uint32(rabbit, args, 0);
    unsigned int arg_1 = _javascript_to_uint32(rabbit, args, 1);
    rabbit->moveto(arg_0 ,arg_1);
    delete rabbit;
}

void _javascript_click(const FunctionCallbackInfo<Value>& args) {
    Rabbit * rabbit = new Rabbit();
    Isolate* isolate = args.GetIsolate();
    rabbit->click();
    delete rabbit;
}

void _javascript_doubleclick(const FunctionCallbackInfo<Value>& args) {
    Rabbit * rabbit = new Rabbit();
    Isolate* isolate = args.GetIsolate();
    rabbit->doubleclick();
    delete rabbit;
}

void _javascript_rightclick(const FunctionCallbackInfo<Value>& args) {
    Rabbit * rabbit = new Rabbit();
    Isolate* isolate = args.GetIsolate();
    rabbit->rightclick();
    delete rabbit;
}

void _javascript_findcolor(const FunctionCallbackInfo<Value>& args) {
    Rabbit * rabbit = new Rabbit();
    Isolate* isolate = args.GetIsolate();
    int ret_0;
    int ret_1;
    unsigned int arg_0 = _javascript_to_uint32(rabbit, args, 0);
    unsigned int arg_1 = _javascript_to_uint32(rabbit, args, 1);
    unsigned int arg_2 = _javascript_to_uint32(rabbit, args, 2);
    unsigned int arg_3 = _javascript_to_uint32(rabbit, args, 3);
    unsigned int arg_4 = _javascript_to_uint32(rabbit, args, 4);
    double arg_5 = _javascript_to_double(rabbit, args, 5);
    rabbit->findcolor(&ret_0 ,&ret_1 ,arg_0 ,arg_1 ,arg_2 ,arg_3 ,arg_4 ,arg_5);
    Handle<Array> ret = Array::New(isolate, 2);
    ret->Set(0, _javascript_to_int32_value(isolate, ret_0));
    ret->Set(1, _javascript_to_int32_value(isolate, ret_1));
    args.GetReturnValue().Set(ret);
    delete rabbit;
}

void _javascript_findwindow(const FunctionCallbackInfo<Value>& args) {
    Rabbit * rabbit = new Rabbit();
    Isolate* isolate = args.GetIsolate();
    long long ret_0;
    const char * arg_0 = _javascript_to_string(rabbit, args, 0);
    const char * arg_1 = _javascript_to_string(rabbit, args, 1);
    rabbit->findwindow(&ret_0 ,arg_0 ,arg_1);
    Local<Value> ret = _javascript_to_int64_value(isolate, ret_0);
    args.GetReturnValue().Set(ret);
    delete rabbit;
}

void _javascript_mouse_get_cursor(const FunctionCallbackInfo<Value>& args) {
    Rabbit * rabbit = new Rabbit();
    Isolate* isolate = args.GetIsolate();
    unsigned int ret_0;
    rabbit->mouse_get_cursor(&ret_0);
    Local<Value> ret = _javascript_to_uint32_value(isolate, ret_0);
    args.GetReturnValue().Set(ret);
    delete rabbit;
}

void _javascript_window_get_rect(const FunctionCallbackInfo<Value>& args) {
    Rabbit * rabbit = new Rabbit();
    Isolate* isolate = args.GetIsolate();
    int ret_0;
    int ret_1;
    int ret_2;
    int ret_3;
    long long arg_0 = _javascript_to_int64(rabbit, args, 0);
    rabbit->window_get_rect(&ret_0 ,&ret_1 ,&ret_2 ,&ret_3 ,arg_0);
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
    NODE_SET_METHOD(exports, "press", _javascript_press);
    NODE_SET_METHOD(exports, "input", _javascript_input);
    NODE_SET_METHOD(exports, "moveto", _javascript_moveto);
    NODE_SET_METHOD(exports, "click", _javascript_click);
    NODE_SET_METHOD(exports, "doubleclick", _javascript_doubleclick);
    NODE_SET_METHOD(exports, "rightclick", _javascript_rightclick);
    NODE_SET_METHOD(exports, "findcolor", _javascript_findcolor);
    NODE_SET_METHOD(exports, "findwindow", _javascript_findwindow);
    NODE_SET_METHOD(exports, "mouse_get_cursor", _javascript_mouse_get_cursor);
    NODE_SET_METHOD(exports, "window_get_rect", _javascript_window_get_rect);
};

Local<Data> rabbit_javascript(Isolate* isolate) {
    Local<ObjectTemplate> rabbit = ObjectTemplate::New(isolate);
    rabbit->Set(String::NewFromUtf8(isolate, "log"), FunctionTemplate::New(isolate, _javascript_log));
    rabbit->Set(String::NewFromUtf8(isolate, "sleep"), FunctionTemplate::New(isolate, _javascript_sleep));
    rabbit->Set(String::NewFromUtf8(isolate, "press"), FunctionTemplate::New(isolate, _javascript_press));
    rabbit->Set(String::NewFromUtf8(isolate, "input"), FunctionTemplate::New(isolate, _javascript_input));
    rabbit->Set(String::NewFromUtf8(isolate, "moveto"), FunctionTemplate::New(isolate, _javascript_moveto));
    rabbit->Set(String::NewFromUtf8(isolate, "click"), FunctionTemplate::New(isolate, _javascript_click));
    rabbit->Set(String::NewFromUtf8(isolate, "doubleclick"), FunctionTemplate::New(isolate, _javascript_doubleclick));
    rabbit->Set(String::NewFromUtf8(isolate, "rightclick"), FunctionTemplate::New(isolate, _javascript_rightclick));
    rabbit->Set(String::NewFromUtf8(isolate, "findcolor"), FunctionTemplate::New(isolate, _javascript_findcolor));
    rabbit->Set(String::NewFromUtf8(isolate, "findwindow"), FunctionTemplate::New(isolate, _javascript_findwindow));
    rabbit->Set(String::NewFromUtf8(isolate, "mouse_get_cursor"), FunctionTemplate::New(isolate, _javascript_mouse_get_cursor));
    rabbit->Set(String::NewFromUtf8(isolate, "window_get_rect"), FunctionTemplate::New(isolate, _javascript_window_get_rect));
    return rabbit;
};
