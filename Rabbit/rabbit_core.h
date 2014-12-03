#pragma once

void rabbit_sleep(unsigned int milliseconds);

// Press a key by name (UTF8) such as 'A', 'F1', 'жа'
void rabbit_keypress(const char * key);
// Press a key by vkey code: http://msdn.microsoft.com/en-us/library/windows/desktop/dd375731.aspx
void rabbit_vkeypress(int vkey);

void rabbit_click();
void rabbit_doubleclick();
void rabbit_rightclick();
void rabbit_moveto(unsigned int x, unsigned int y);

bool rabbit_get_cursor_hash(unsigned int * ret_hash);
bool rabbit_findcolor(int * ret_x, int * ret_y,
	unsigned int color,
	unsigned int x, unsigned int y, unsigned int w, unsigned int h,
	unsigned int order, double tolerance
	);