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
	bool findcolor(int * ret_x, int * ret_y, unsigned int color, unsigned int x, unsigned int y, unsigned int w, unsigned int h, double tolerance);
	void findwindow(long long * window, const char * window_name, const char * class_name);

	void window_get_rect(int * ret_x, int * ret_y, int * ret_w, int * ret_h, long long window);
	bool mouse_get_cursor(unsigned int * ret_hash);
	/*
	bool mouse_moveto(unsigned int x, unsigned int y);
	bool mouse_move(int cx, int cy);
	bool mouse_button_click(unsigned int button);
	bool mouse_button_down(unsigned int button);
	bool mouse_button_up(unsigned int button);
	bool mouse_scroll(int offset);
	*/

	/*
	bool keyboard_skey_press(const char * skey);
	bool keyboard_skey_up(const char * skey);
	bool keyboard_skey_down(const char * skey);
	bool keyboard_vkey_press(unsigned int vkey);
	bool keyboard_vkey_up(unsigned int vkey);
	bool keyboard_vkey_down(unsigned int vkey);
	*/
};
