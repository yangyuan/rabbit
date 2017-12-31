#pragma once

#include "rabbit_core_common.h"

void rabbit_kayboard_wchar_press(wchar_t keychar);
void rabbit_kayboard_vkey_press(UINT vkey);

bool rabbit_mouse_get_cursor(unsigned int * id, unsigned int * hash);

bool rabbit_screen_search_color(int * ret_x, int * ret_y,
	unsigned int mode, unsigned int color,
	unsigned int x, unsigned int y, unsigned int w, unsigned int h,
	double tolerance);

void rabbit_system_hotkey(int id, UINT vkey, UINT modifiers);