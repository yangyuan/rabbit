#include "rabbit_core_common.h"
#include "rabbit_core.h"
#include "rabbit_core_utils.h"

RabbitCore::RabbitCore() {
	// do nothing
}

RabbitCore::~RabbitCore() {
	while (!this->callStack.empty())
	{
		free(this->callStack.top());
		this->callStack.pop();
	}
	// do nothing
}
void * RabbitCore::allocate(size_t size) {
	void * memory = malloc(size);
	this->callStack.push(memory);
	return memory;
}

void Rabbit::log(const char * text) {
	printf("%s\n", text);
}

void Rabbit::sleep(unsigned int milliseconds) {
	Sleep((DWORD) milliseconds);
}

void Rabbit::press(const char * key) {
	std::string keyName(key);
	UINT vkey = NULL;
	if ((key[0] == 'F' || key[0] == 'f') && (key[1] >= '1' && key[1] <= '9')) {
		int fid = std::stoi(keyName.substr(1));
		if (fid > 0 && fid < 13) {
			vkey = VK_F1 - 1 + fid;
		}
	}
	else if ((key[0] >= '0' && key[0] <= '9') || (key[0] >= 'A' && key[0] <= 'Z') || (key[0] >= 'a' && key[0] <= 'z')) {
		vkey = key[0];
	}

	if (vkey != NULL) {
		_rabbit_kayboard_vkey_press(vkey);
	}
}

void Rabbit::input(const char * text) {
	int len = (int)strlen(text);
	int wlen = MultiByteToWideChar(CP_UTF8, NULL, text, len, NULL, 0);
	size_t blen = (wlen + 1) * sizeof(wchar_t);
	wchar_t * utext = (wchar_t *)malloc(blen);
	ZeroMemory(utext, blen);
	MultiByteToWideChar(CP_UTF8, NULL, text, len, utext, wlen);

	for (int i = 0; i < wlen; i++) {
		_rabbit_kayboard_wchar_press(utext[i]);
	}
}

void Rabbit::moveto(unsigned int x, unsigned int y) {
	INPUT input;
	ZeroMemory(&input, sizeof(INPUT));
	input.type = INPUT_MOUSE;
	input.mi.dwFlags = MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE;

	double fScreenWidth = GetSystemMetrics(SM_CXSCREEN);
	double fScreenHeight = GetSystemMetrics(SM_CYSCREEN);
	double dx = x * 65536.0f / fScreenWidth;
	double dy = y * 65536.0f / fScreenHeight;

	input.mi.dx = (LONG)dx;
	input.mi.dy = (LONG)dy;
	SendInput(1, &input, sizeof(INPUT));
}

void Rabbit::click() {
	INPUT input[2];
	ZeroMemory(input, 2 * sizeof(INPUT));

	input[0].type = INPUT_MOUSE;
	input[0].mi.dwFlags = MOUSEEVENTF_LEFTDOWN;

	input[1].type = INPUT_MOUSE;
	input[1].mi.dwFlags = MOUSEEVENTF_LEFTUP;

	SendInput(2, input, sizeof(INPUT));
}

void Rabbit::doubleclick() {
	this->click();
	Sleep(50);
	this->click();
}

void Rabbit::rightclick() {
	INPUT input[2];
	ZeroMemory(input, 2 * sizeof(INPUT));

	input[0].type = INPUT_MOUSE;
	input[0].mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;

	input[1].type = INPUT_MOUSE;
	input[1].mi.dwFlags = MOUSEEVENTF_RIGHTUP;

	SendInput(2, input, sizeof(INPUT));
}

void Rabbit::findcolor(int * ret_x, int * ret_y,
	unsigned int color,
	unsigned int x, unsigned int y, unsigned int w, unsigned int h,
	double tolerance) {
	screen_search_color(ret_x, ret_y, 0, color, x, y, w, h, tolerance);
}

void Rabbit::findwindow(long long * window, const char * window_name, const char * class_name) {
	if (strlen(class_name) == 0) {
		class_name = NULL;
	}

	*window = (long long)FindWindowA(class_name, window_name);
}

void Rabbit::window_get_rect(int * ret_x, int * ret_y, int * ret_w, int * ret_h, long long window) {
	RECT rect;
	GetWindowRect((HWND)window, &rect);
	*ret_x = rect.left;
	*ret_y = rect.top;
	*ret_w = rect.right - rect.left;
	*ret_h = rect.bottom - rect.top;
}

void Rabbit::window_find_focus(long long * window) {
	*window = (long long) GetForegroundWindow();
}

void Rabbit::mouse_get_cursor(unsigned int * cursor) {
	unsigned int _id, _hash;
	_rabbit_mouse_get_cursor(&_id, &_hash);

	if (_id != 0) {
		*cursor = _id;
	}
	else {
		*cursor = _hash;
	}
}

void Rabbit::mouse_get_cursor_id(unsigned int * id) {
	unsigned int _hash;
	_rabbit_mouse_get_cursor(id, &_hash);
}

void Rabbit::mouse_get_cursor_hash(unsigned int * hash) {
	unsigned int _id;
	_rabbit_mouse_get_cursor(&_id, hash);
}

void Rabbit::keyboard_press_vkey(unsigned int vkey) {
	_rabbit_kayboard_vkey_press(vkey);
}