#pragma once
#include "rabbit_core_common.h"

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
	void scroll(double tolerance);
	void findcolor(int * ret_x, int * ret_y, unsigned int color, unsigned int x, unsigned int y, unsigned int w, unsigned int h, double tolerance);
	void findwindow(long long * window, const char * window_name, const char * class_name);

	void window_get_rect(int * ret_x, int * ret_y, int * ret_w, int * ret_h, long long window);
	void window_find_focus(long long * window);

	void mouse_get_cursor(unsigned int * cursor);
	void mouse_get_cursor_id(unsigned int * id);
	void mouse_get_cursor_hash(unsigned int * hash);

	void keyboard_press_vkey(unsigned int vkey);

	void system_hotkey(int id, unsigned int vkey, unsigned int modifiers);
	/*
	void mouse_moveto(unsigned int x, unsigned int y);
	void mouse_move(int cx, int cy);
	void mouse_click_button(unsigned int button);
	void mouse_click_button_down(unsigned int button);
	void mouse_click_button_up(unsigned int button);
	void mouse_scroll(int offset);
	*/

	/*
	void keyboard_press_skey(const char * skey);
	void keyboard_press_skey_up(const char * skey);
	void keyboard_press_skey_down(const char * skey);
	void keyboard_press_vkey_up(unsigned int vkey);
	void keyboard_press_vkey_down(unsigned int vkey);
	*/
};
