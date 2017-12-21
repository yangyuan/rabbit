#pragma once

void _rabbit_kayboard_wchar_press(wchar_t keychar);
void _rabbit_kayboard_vkey_press(UINT vkey);
bool _rabbit_mouse_get_cursor(unsigned int * ret_hash);
bool screen_search_color(int * ret_x, int * ret_y,
	unsigned int mode, unsigned int color,
	unsigned int x, unsigned int y, unsigned int w, unsigned int h,
	double tolerance);