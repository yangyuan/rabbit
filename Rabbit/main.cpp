#include "common.h"
#include "rabbit.h"

DWORD WINAPI ThreadProc(LPVOID lpParameter) {
	RABBIT_PROC proc = * (RABBIT_PROC *) lpParameter; // copy value, original pionter might be dis
	if (proc.path != NULL) {
		rabbit_file(proc.mode, proc.path);
	}
	else {
		rabbit_string(proc.mode, proc.script);
	}
	return 0;
}

int _tmain(int argc, _TCHAR* argv[])
{
	BOOL ret;
	HANDLE ThreadHandle = NULL;

	ret = RegisterHotKey(NULL, 0, NULL, VK_F7);
	ret = RegisterHotKey(NULL, 1, NULL, VK_F8);
	MSG msg;
	while ((ret = GetMessage(&msg, NULL, 0, 0)) != 0)
	{
		switch (msg.message) {
		case WM_HOTKEY:
			if (msg.wParam == 0) {
				printf("F7\n");
				RABBIT_PROC proc;
				proc.mode = RABBIT_MODE_PYTHON;
				proc.path = _T("script.py");
				//proc.path = _T("script.lua");
				DWORD dwThreadId = NULL;
				if (ThreadHandle == NULL) {
					ThreadHandle = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)&ThreadProc, (LPVOID)&proc, 0, &dwThreadId);
				}
			}
			else if (msg.wParam == 1) {
				printf("F8\n");
				if (ThreadHandle != NULL) {
					bool tret = TerminateThread(ThreadHandle, 0);
					if (tret) {
						ThreadHandle = NULL;
					}
				}
			}
			break;
		default:
			break;
		}
	}
	return 0;
}