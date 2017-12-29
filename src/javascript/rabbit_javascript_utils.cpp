#include <v8.h>
#include "rabbit_core.h"

using namespace v8;

Local<Value> _javascript_to_int32_value(Isolate* isolate, int value) {
	return Int32::New(isolate, value);
}

Local<Value> _javascript_to_uint32_value(Isolate* isolate, unsigned int value) {
	return Uint32::New(isolate, value);
}

Local<Value> _javascript_to_int64_value(Isolate* isolate, long long value) {
	return _javascript_to_int32_value(isolate, (int)value);
}

Local<Value> _javascript_to_double_value(Isolate* isolate, double value) {
	return Number::New(isolate, value);
}

Local<Value> _javascript_to_string_value(Isolate* isolate, char * value) {
	return String::NewFromUtf8(isolate, value);
}

int _javascript_to_int32(RabbitCore * core, FunctionCallbackInfo<Value> args, int index) {
	Isolate* isolate = args.GetIsolate();
	Local<Value> value = args[index];
	return value->Int32Value();
}

unsigned int _javascript_to_uint32(RabbitCore * core, FunctionCallbackInfo<Value> args, int index) {
	Isolate* isolate = args.GetIsolate();
	Local<Value> value = args[index];
	return value->Uint32Value();
}

long long _javascript_to_int64(RabbitCore * core, FunctionCallbackInfo<Value> args, int index) {
	return (long long)_javascript_to_int32(core, args, index);
}

double _javascript_to_double(RabbitCore * core, FunctionCallbackInfo<Value> args, int index) {
	Isolate* isolate = args.GetIsolate();
	Local<Value> value = args[index];
	return value->NumberValue();
}

char * _javascript_to_string(RabbitCore * core, FunctionCallbackInfo<Value> args, int index) {
	Isolate* isolate = args.GetIsolate();
	Local<Value> value = args[index];
	String::Utf8Value tmp(value);
	std::string str(*tmp);
	char * buff = (char *)core->allocate(tmp.length() * 2 + 2);
	memcpy_s(buff, tmp.length() + 1, str.c_str(), tmp.length() + 1);
	return buff;
}