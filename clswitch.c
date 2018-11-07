#include <windows.h>

HHOOK hook;

LRESULT CALLBACK keyboardHook(int nCode, WPARAM wParam, LPARAM lParam) {
	KBDLLHOOKSTRUCT *p = (KBDLLHOOKSTRUCT *)lParam;
	WORD keyCode = (WORD)p->vkCode;
	if ((keyCode == VK_CAPITAL) && !(p->flags&LLKHF_INJECTED) && nCode >= 0) {
		if (GetKeyState(VK_CONTROL) & 0x8000) goto call_next;
		if (wParam == WM_KEYUP)
			PostMessage(GetForegroundWindow(), WM_INPUTLANGCHANGEREQUEST, 2, 0);
		return 1;
	};
call_next:
	return CallNextHookEx(hook, nCode, wParam, lParam);
}

LRESULT CALLBACK WndProc(HWND ihwnd, UINT umsg, WPARAM wParam, LPARAM lParam) {
	if ((umsg == WM_CLOSE) || (umsg == WM_DESTROY) || (umsg == WM_ENDSESSION)) {
		PostQuitMessage(0);
		return 0;
	}
	else return DefWindowProc(ihwnd, umsg, wParam, lParam);
}

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow) {
	LPCSTR cl_name = (LPCSTR)"capsfinder";
	SetLastError(0);
	HANDLE iMutex = CreateMutex(NULL, TRUE, cl_name);
	if (iMutex) {
		if (GetLastError() == ERROR_ALREADY_EXISTS) return 0;
	}
	else return 0;
	HWND hwnd;
	WNDCLASS wc = {};;
	wc.lpfnWndProc = WndProc;
	wc.hInstance = hInstance;
	wc.lpszClassName = cl_name;
	if (!RegisterClass(&wc)) goto return_point_1;
	hwnd = CreateWindow(cl_name, NULL, 0, 0, 0, 0, 0, 0, 0, hInstance, 0);
	if (!hwnd) goto return_point_2;
	hook = SetWindowsHookEx(WH_KEYBOARD_LL, keyboardHook, NULL, 0);
	if (hook) {
		MSG msg;
		while (GetMessage(&msg, NULL, 0, 0) > 0)
			DispatchMessage(&msg);
	};
return_point_2:
	UnregisterClass(cl_name, hInstance);
return_point_1:
	CloseHandle(iMutex);
	return 0;
}
