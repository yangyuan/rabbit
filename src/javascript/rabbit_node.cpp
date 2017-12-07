#include <v8.h>
#include "rabbit_core.h"

using namespace v8;
Local<Value> _javascript_to_int32_value(Isolate* isolate, int value) {
	return Int32::New(isolate, value);
}
Local<Value> _javascript_to_uint32_value(Isolate* isolate, unsigned int value) {
	return Uint32::New(isolate, value);
}
Local<Value> _javascript_to_double_value(Isolate* isolate, double value) {
	return Number::New(isolate, value);
}
Local<Value> _javascript_to_string_value(Isolate* isolate, char * value) {
	return String::NewFromUtf8(isolate, value);
}
int _javascript_to_int32(FunctionCallbackInfo<Value> args, int index) {
	Isolate* isolate = args.GetIsolate();

	if (args.Length() <= index) {
		isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Wrong number of arguments")));
	}

	Local<Value> value = args[index];
	if (value->IsInt32()) {
		return value->Int32Value();
	}

	isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Wrong type of argument")));
}
unsigned int _javascript_to_uint32(FunctionCallbackInfo<Value> args, int index) {
	Isolate* isolate = args.GetIsolate();

	if (args.Length() <= index) {
		isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Wrong number of arguments")));
	}

	Local<Value> value = args[index];
	if (value->IsUint32()) {
		return value->Uint32Value();
	}

	isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Wrong type of argument")));
}
double _javascript_to_double(FunctionCallbackInfo<Value> args, int index) {
	Isolate* isolate = args.GetIsolate();

	if (args.Length() <= index) {
		isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Wrong number of arguments")));
	}

	Local<Value> value = args[index];
	if (value->IsNumber()) {
		return value->NumberValue();
	}

	isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Wrong type of argument")));
}
char * _javascript_to_string(FunctionCallbackInfo<Value> args, int index) {
	Isolate* isolate = args.GetIsolate();

	if (args.Length() <= index) {
		isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Wrong number of arguments")));
	}

	Local<Value> value = args[index];
	if (value->IsString()) {
		String::Utf8Value tmp(value);
		std::string str(*tmp);
		// TODO: change all char * to std::string to fix memleak
		char * buff = (char *)malloc(tmp.length() * 2 + 2);
		memcpy_s(buff, tmp.length() + 1, str.c_str(), tmp.length() + 1);

		return buff;
	}

	isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Wrong type of argument")));
}