#include "app.h"
#include <v8.h>
#include <libplatform/libplatform.h>
#include <Python.h>
#include <lua.hpp>

bool load_script(LPCTSTR path, LPSTR &buffer, DWORD &length)
{
	// LOAD FILE AND CONVERT TO UTF8
	HANDLE hFile = CreateFile(path, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile == INVALID_HANDLE_VALUE) return false;

	length = GetFileSize(hFile, NULL);
	if (length)
	{
		LPSTR cache = new char[length + 1];
		DWORD dwRead;
		if (ReadFile(hFile, cache, length, &dwRead, NULL))
		{
			cache[length] = _T('\000');
			buffer = (LPSTR)cache;
			if (cache[0] == '\xEF' && cache[1] == '\xBB' && cache[2] == '\xBF') {
				LPSTR result = new char[length-2];
				strncpy_s(result, length - 2, cache + 3, length - 2);
				buffer = result;
				delete cache;
			} else if (IsTextUnicode(cache, length, NULL))
			{
				LPSTR result = new char[length+1];
				WideCharToMultiByte(CP_UTF8, 0, (WCHAR*)cache, length, result, length, NULL, NULL);
				buffer = result;
				delete cache;
			}
		}
		else
		{
			delete[] cache;
		}
	}
	CloseHandle(hFile);
	return true;
}

void rabbit_init_lua(lua_State * L);
extern PyObject * PyInit_rabbit();
v8::Local<v8::Data> rabbit_javascript(v8::Isolate* isolate);

static v8::Isolate * isolate = NULL;

void rabbit_string(RABBIT_MODE mode, char * script)
{
	if (mode == RABBIT_MODE_LUA) {
		lua_State * L = luaL_newstate();
		luaL_openlibs(L);
		rabbit_init_lua(L);
		luaL_loadstring(L, script);
		int status = lua_pcall(L, 0, LUA_MULTRET, 0);
		lua_close(L);
	}
	else if(mode == RABBIT_MODE_JAVASCRIPT) {
		using namespace v8;

		if (isolate == NULL) {
			V8::InitializeICU(".\\icudtl.dat");
			V8::InitializeExternalStartupData(".");
			Platform* platform = platform::CreateDefaultPlatform();
			V8::InitializePlatform(platform);

			v8::V8::Initialize();
			v8::Isolate::CreateParams create_params;
			create_params.array_buffer_allocator = v8::ArrayBuffer::Allocator::NewDefaultAllocator();
			isolate = Isolate::New(create_params);
		}

		Isolate::Scope isolate_scope(isolate);
		HandleScope handle_scope(isolate);
		v8::Local<v8::ObjectTemplate> global = v8::ObjectTemplate::New(isolate);
		Local<Data> rabbit = rabbit_javascript(isolate);
		global->Set(String::NewFromUtf8(isolate, "rabbit", NewStringType::kNormal).ToLocalChecked(), rabbit);

		Local<Context> context = Context::New(isolate, NULL, global);
		Context::Scope context_scope(context);
		Local<String> source = String::NewFromUtf8(isolate, script, NewStringType::kNormal).ToLocalChecked();
		Local<Script> script = Script::Compile(context, source).ToLocalChecked();
		script->Run(context);
	}
	else {
		Py_SetProgramName(L"rabbit");
		Py_SetPythonHome(L".");
		PyImport_AppendInittab("rabbit", &PyInit_rabbit);
		Py_Initialize();
		PyRun_SimpleString("import rabbit");
		PyRun_SimpleString(script);
		Py_Finalize();
	}
}

void rabbit_file(RABBIT_MODE mode, LPCTSTR path)
{
	char * script = NULL;
	DWORD size;
	load_script(path, script, size);
	if (script != NULL) {
		rabbit_string(mode, script);
		delete script;
	} else {
	}
}
