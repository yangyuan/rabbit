#include <v8.h>
#include "rabbit_core.h"

using namespace v8;

Local<Value> _javascript_to_int32_value(Isolate*, int);
Local<Value> _javascript_to_uint32_value(Isolate*, unsigned int);
Local<Value> _javascript_to_int64_value(Isolate*, long long);
Local<Value> _javascript_to_double_value(Isolate*, double);
Local<Value> _javascript_to_string_value(Isolate*, char *);
int _javascript_to_int32(RabbitCore *, FunctionCallbackInfo<Value>, int);
unsigned int _javascript_to_uint32(RabbitCore *, FunctionCallbackInfo<Value>, int);
long long _javascript_to_int64(RabbitCore *, FunctionCallbackInfo<Value>, int);
double _javascript_to_double(RabbitCore *, FunctionCallbackInfo<Value>, int);
char * _javascript_to_string(RabbitCore *, FunctionCallbackInfo<Value>, int);


#ifndef NODE_SET_METHOD
inline void NODE_SET_METHOD(v8::Local<v8::Object> recv, const char* name, v8::FunctionCallback callback) {
	v8::Isolate* isolate = v8::Isolate::GetCurrent();
	v8::HandleScope handle_scope(isolate);
	v8::Local<v8::FunctionTemplate> t = v8::FunctionTemplate::New(isolate,
		callback);
	v8::Local<v8::Function> fn = t->GetFunction();
	v8::Local<v8::String> fn_name = v8::String::NewFromUtf8(isolate, name);
	fn->SetName(fn_name);
	recv->Set(fn_name, fn);
}
#endif