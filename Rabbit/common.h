#pragma once

#include <tchar.h>
#include <Windows.h>
#include <iostream>
#include <lua.hpp>
#ifdef _DEBUG
#undef _DEBUG
#define _DEBUG_PYTHON
#endif 
#include <Python.h>
#ifdef _DEBUG_PYTHON
#undef _DEBUG_PYTHON
#define _DEBUG
#endif
#include <v7.h>
