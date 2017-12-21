#pragma once

#include <stack>

class RabbitCore {
public:
	RabbitCore();
	~RabbitCore();
	void * allocate(size_t size);
private:
	std::stack<void *> callStack;
};

class Rabbit : public RabbitCore {
public:
	void log(const char * text);
	void sleep(unsigned int milliseconds);
	void press(const char * key);
	void input(const char * text);
	void moveto(unsigned int x, unsigned int y);
	void click();
	void doubleclick();
	void rightclick();
	bool findcolor(int * ret_x, int * ret_y, unsigned int color, unsigned int x, unsigned int y, unsigned int w, unsigned int h, double tolerance);
	void findwindow(long long * window, const char * window_name, const char * class_name);

	void window_get_rect(int * ret_x, int * ret_y, int * ret_w, int * ret_h, long long window);
	bool mouse_get_cursor(unsigned int * ret_hash);
};




bool rabbit_get_cursor_hash(unsigned int * ret_hash);
// Press a key by name (UTF8) such as 'A', 'F1'
// Press a key by vkey code: http://msdn.microsoft.com/en-us/library/windows/desktop/dd375731.aspx
bool rabbit_keyboard_skey_press(const char * skey);
bool rabbit_keyboard_skey_up(const char * skey);
bool rabbit_keyboard_skey_down(const char * skey);
bool rabbit_keyboard_vkey_press(unsigned int vkey);
bool rabbit_keyboard_vkey_up(unsigned int vkey);
bool rabbit_keyboard_vkey_down(unsigned int vkey);

// VK_LBUTTON 0x01
// VK_RBUTTON 0x02
// 0x03
// VK_MBUTTON 0x04
// VK_XBUTTON1 0x05
// VK_XBUTTON2 0x06
bool rabbit_mouse_moveto(unsigned int x, unsigned int y);
bool rabbit_mouse_move(int cx, int cy);
bool rabbit_mouse_button_click(unsigned int button);
bool rabbit_mouse_button_down(unsigned int button);
bool rabbit_mouse_button_up(unsigned int button);
bool rabbit_mouse_scroll(int offset);


