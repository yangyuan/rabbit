#include "common.h"
#include "rabbit.h"

// in rabbitx.cpp
void rabbit_init(RABBIT_MODE mode, void * instance);

void rabbit_debug() {
	printf("xxxxxx");
}

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
				strncpy(result, cache + 3, length - 2);
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

void rabbit_string(RABBIT_MODE mode, char * script)
{
	if (mode == RABBIT_MODE_LUA) {
		lua_State * L = luaL_newstate();
		luaL_openlibs(L);
		rabbit_init(mode, L);
		luaL_loadstring(L, script);
		int status = lua_pcall(L, 0, LUA_MULTRET, 0);
		lua_close(L);
	}
	else {
		Py_SetProgramName("rabbit");
		Py_SetPythonHome(".");
		Py_Initialize();
		rabbit_init(mode, NULL);
		PyRun_SimpleString(script);
		Py_Finalize();
	}

}

void rabbit_file(RABBIT_MODE mode, LPCTSTR path)
{
	char * script;
	DWORD size;
	load_script(path, script, size);
	rabbit_string(mode, script);
	delete script;
}



