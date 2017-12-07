#pragma once

#include <tchar.h>
#include <Windows.h>
#include <iostream>

enum RABBIT_MODE
{
	RABBIT_MODE_LUA,
	RABBIT_MODE_PYTHON,
	RABBIT_MODE_JAVASCRIPT,
};

typedef struct {
	RABBIT_MODE mode;
	TCHAR * path;
	char * script;
} RABBIT_PROC;

void rabbit_file(RABBIT_MODE mode, LPCTSTR path);
void rabbit_string(RABBIT_MODE mode, char * script);
void rabbit_debug();