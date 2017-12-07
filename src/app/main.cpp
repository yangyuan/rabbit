#include "rabbit.h"

DWORD WINAPI ThreadProc(LPVOID lpParameter) {
	RABBIT_PROC proc = *(RABBIT_PROC *)lpParameter; // copy value, original pionter might be dis
	if (proc.path != NULL) {
		rabbit_file(proc.mode, proc.path);
	}
	else {
		rabbit_string(proc.mode, proc.script);
	}
	return 0;
}

bool quit = false;

BOOL CtrlHandler(DWORD fdwCtrlType)
{
	switch (fdwCtrlType)
	{
	case CTRL_C_EVENT:
	case CTRL_CLOSE_EVENT:
	case CTRL_BREAK_EVENT:
	case CTRL_LOGOFF_EVENT:
	case CTRL_SHUTDOWN_EVENT:
		Beep(750, 300);
		quit = true;
		return(TRUE);
	default:
		return FALSE;
	}
}

BOOL FileExists(LPCTSTR szPath)
{
	DWORD dwAttrib = GetFileAttributes(szPath);

	return (dwAttrib != INVALID_FILE_ATTRIBUTES &&
		!(dwAttrib & FILE_ATTRIBUTE_DIRECTORY));
}

int _tmain(int argc, _TCHAR* argv[])
{
	BOOL ret;
	HANDLE ThreadHandle = NULL;

	ret = RegisterHotKey(NULL, 0, NULL, VK_F7);
	ret = RegisterHotKey(NULL, 1, NULL, VK_F8);

	SetConsoleCtrlHandler((PHANDLER_ROUTINE)CtrlHandler, TRUE);

	MSG msg;
	while (true)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE) == 0) {
			if (quit) break;
			Sleep(128);
			continue;
		}
		switch (msg.message) {
		case WM_HOTKEY:
			if (msg.wParam == 0) {
				printf("F7\n");
				Beep(400, 125);
				Beep(700, 125);
				RABBIT_PROC proc;

				if (FileExists(_T("script.py"))) {
					proc.mode = RABBIT_MODE_PYTHON;
					proc.path = _T("script.py");
				} else if (FileExists(_T("script.js"))) {
					proc.mode = RABBIT_MODE_JAVASCRIPT;
					proc.path = _T("script.js");
				} else if (FileExists(_T("script.lua"))) {
					proc.mode = RABBIT_MODE_LUA;
					proc.path = _T("script.lua");
				} else {
					printf(_T("no script file found."));
				}

				DWORD dwThreadId = NULL;
				if (ThreadHandle == NULL) {
					ThreadHandle = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)&ThreadProc, (LPVOID)&proc, 0, &dwThreadId);
				}
			}
			else if (msg.wParam == 1) {
				printf("F8\n");
				Beep(700, 125);
				Beep(400, 125);
				if (ThreadHandle != NULL) {
					BOOL tret = TerminateThread(ThreadHandle, 0);
					if (tret) {
						ThreadHandle = NULL;
					}
				}
				// idk why i have to call it again here
				SetConsoleCtrlHandler((PHANDLER_ROUTINE)CtrlHandler, TRUE);
			}
			break;
		default:
			break;
		}
	}
	return 0;
}