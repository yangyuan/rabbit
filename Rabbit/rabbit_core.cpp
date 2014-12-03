#include "common.h"
#include "rabbit_core.h"

void _rabbit_kayboard_wchar_press(wchar_t keychar) {
	INPUT input[2];
	ZeroMemory(input, 2 * sizeof(INPUT));

	input[0].type = INPUT_KEYBOARD;
	input[0].ki.wVk = 0;
	input[0].ki.wScan = keychar;
	input[0].ki.dwFlags = KEYEVENTF_UNICODE;

	input[1].type = INPUT_KEYBOARD;
	input[1].ki.wVk = 0;
	input[1].ki.wScan = keychar;
	input[1].ki.dwFlags = KEYEVENTF_KEYUP | KEYEVENTF_UNICODE;

	SendInput(2, input, sizeof(INPUT));
}

void _rabbit_kayboard_vkey_press(WORD vkey) {
	INPUT input[2];
	ZeroMemory(input, 2 * sizeof(INPUT));

	input[0].type = INPUT_KEYBOARD;
	input[0].ki.wVk = vkey;
	input[0].ki.wScan = 0;
	input[0].ki.dwFlags = NULL;

	input[1].type = INPUT_KEYBOARD;
	input[1].ki.wVk = vkey;
	input[1].ki.wScan = 0;
	input[1].ki.dwFlags = KEYEVENTF_KEYUP;

	SendInput(2, input, sizeof(INPUT));
}

void rabbit_keypress(const char * key) {
	int len = strlen(key);
	wchar_t keyname[16];
	MultiByteToWideChar(CP_UTF8, NULL, key, len, keyname, 16);
	if (keyname[0] == L'1') {
		_rabbit_kayboard_vkey_press(0x31);
	}
	else {
		_rabbit_kayboard_wchar_press(keyname[0]);
	}
}

void rabbit_vkeypress(int vkey) {
	_rabbit_kayboard_vkey_press((WORD)vkey);
}


void rabbit_click() {
	INPUT input[2];
	ZeroMemory(input, 2 * sizeof(INPUT));

	input[0].type = INPUT_MOUSE;
	input[0].mi.dwFlags = MOUSEEVENTF_LEFTDOWN;

	input[1].type = INPUT_MOUSE;
	input[1].mi.dwFlags = MOUSEEVENTF_LEFTUP;

	SendInput(2, input, sizeof(INPUT));
}
void rabbit_doubleclick() {
	rabbit_click();
	Sleep(50);
	rabbit_click();
}
void rabbit_rightclick() {
	INPUT input[2];
	ZeroMemory(input, 2 * sizeof(INPUT));

	input[0].type = INPUT_MOUSE;
	input[0].mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;

	input[1].type = INPUT_MOUSE;
	input[1].mi.dwFlags = MOUSEEVENTF_RIGHTUP;

	SendInput(2, input, sizeof(INPUT));
}
void rabbit_moveto(unsigned int x, unsigned int y) {
	INPUT input;
	ZeroMemory(&input, sizeof(INPUT));
	input.type = INPUT_MOUSE;
	input.mi.dwFlags = MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE;

	double fScreenWidth = GetSystemMetrics(SM_CXSCREEN) - 1;
	double fScreenHeight = GetSystemMetrics(SM_CYSCREEN) - 1;
	double dx = x *65535.0f / fScreenWidth;
	double dy = y *65535.0f / fScreenHeight;

	input.mi.dx = dx;
	input.mi.dy = dy;
	SendInput(1, &input, sizeof(INPUT));
}

void rabbit_sleep(unsigned int milliseconds) {
	Sleep(milliseconds);
}

static unsigned int crc_32_tab[] = { /* CRC polynomial 0xedb88320 */
	0x00000000, 0x77073096, 0xee0e612c, 0x990951ba, 0x076dc419, 0x706af48f,
	0xe963a535, 0x9e6495a3, 0x0edb8832, 0x79dcb8a4, 0xe0d5e91e, 0x97d2d988,
	0x09b64c2b, 0x7eb17cbd, 0xe7b82d07, 0x90bf1d91, 0x1db71064, 0x6ab020f2,
	0xf3b97148, 0x84be41de, 0x1adad47d, 0x6ddde4eb, 0xf4d4b551, 0x83d385c7,
	0x136c9856, 0x646ba8c0, 0xfd62f97a, 0x8a65c9ec, 0x14015c4f, 0x63066cd9,
	0xfa0f3d63, 0x8d080df5, 0x3b6e20c8, 0x4c69105e, 0xd56041e4, 0xa2677172,
	0x3c03e4d1, 0x4b04d447, 0xd20d85fd, 0xa50ab56b, 0x35b5a8fa, 0x42b2986c,
	0xdbbbc9d6, 0xacbcf940, 0x32d86ce3, 0x45df5c75, 0xdcd60dcf, 0xabd13d59,
	0x26d930ac, 0x51de003a, 0xc8d75180, 0xbfd06116, 0x21b4f4b5, 0x56b3c423,
	0xcfba9599, 0xb8bda50f, 0x2802b89e, 0x5f058808, 0xc60cd9b2, 0xb10be924,
	0x2f6f7c87, 0x58684c11, 0xc1611dab, 0xb6662d3d, 0x76dc4190, 0x01db7106,
	0x98d220bc, 0xefd5102a, 0x71b18589, 0x06b6b51f, 0x9fbfe4a5, 0xe8b8d433,
	0x7807c9a2, 0x0f00f934, 0x9609a88e, 0xe10e9818, 0x7f6a0dbb, 0x086d3d2d,
	0x91646c97, 0xe6635c01, 0x6b6b51f4, 0x1c6c6162, 0x856530d8, 0xf262004e,
	0x6c0695ed, 0x1b01a57b, 0x8208f4c1, 0xf50fc457, 0x65b0d9c6, 0x12b7e950,
	0x8bbeb8ea, 0xfcb9887c, 0x62dd1ddf, 0x15da2d49, 0x8cd37cf3, 0xfbd44c65,
	0x4db26158, 0x3ab551ce, 0xa3bc0074, 0xd4bb30e2, 0x4adfa541, 0x3dd895d7,
	0xa4d1c46d, 0xd3d6f4fb, 0x4369e96a, 0x346ed9fc, 0xad678846, 0xda60b8d0,
	0x44042d73, 0x33031de5, 0xaa0a4c5f, 0xdd0d7cc9, 0x5005713c, 0x270241aa,
	0xbe0b1010, 0xc90c2086, 0x5768b525, 0x206f85b3, 0xb966d409, 0xce61e49f,
	0x5edef90e, 0x29d9c998, 0xb0d09822, 0xc7d7a8b4, 0x59b33d17, 0x2eb40d81,
	0xb7bd5c3b, 0xc0ba6cad, 0xedb88320, 0x9abfb3b6, 0x03b6e20c, 0x74b1d29a,
	0xead54739, 0x9dd277af, 0x04db2615, 0x73dc1683, 0xe3630b12, 0x94643b84,
	0x0d6d6a3e, 0x7a6a5aa8, 0xe40ecf0b, 0x9309ff9d, 0x0a00ae27, 0x7d079eb1,
	0xf00f9344, 0x8708a3d2, 0x1e01f268, 0x6906c2fe, 0xf762575d, 0x806567cb,
	0x196c3671, 0x6e6b06e7, 0xfed41b76, 0x89d32be0, 0x10da7a5a, 0x67dd4acc,
	0xf9b9df6f, 0x8ebeeff9, 0x17b7be43, 0x60b08ed5, 0xd6d6a3e8, 0xa1d1937e,
	0x38d8c2c4, 0x4fdff252, 0xd1bb67f1, 0xa6bc5767, 0x3fb506dd, 0x48b2364b,
	0xd80d2bda, 0xaf0a1b4c, 0x36034af6, 0x41047a60, 0xdf60efc3, 0xa867df55,
	0x316e8eef, 0x4669be79, 0xcb61b38c, 0xbc66831a, 0x256fd2a0, 0x5268e236,
	0xcc0c7795, 0xbb0b4703, 0x220216b9, 0x5505262f, 0xc5ba3bbe, 0xb2bd0b28,
	0x2bb45a92, 0x5cb36a04, 0xc2d7ffa7, 0xb5d0cf31, 0x2cd99e8b, 0x5bdeae1d,
	0x9b64c2b0, 0xec63f226, 0x756aa39c, 0x026d930a, 0x9c0906a9, 0xeb0e363f,
	0x72076785, 0x05005713, 0x95bf4a82, 0xe2b87a14, 0x7bb12bae, 0x0cb61b38,
	0x92d28e9b, 0xe5d5be0d, 0x7cdcefb7, 0x0bdbdf21, 0x86d3d2d4, 0xf1d4e242,
	0x68ddb3f8, 0x1fda836e, 0x81be16cd, 0xf6b9265b, 0x6fb077e1, 0x18b74777,
	0x88085ae6, 0xff0f6a70, 0x66063bca, 0x11010b5c, 0x8f659eff, 0xf862ae69,
	0x616bffd3, 0x166ccf45, 0xa00ae278, 0xd70dd2ee, 0x4e048354, 0x3903b3c2,
	0xa7672661, 0xd06016f7, 0x4969474d, 0x3e6e77db, 0xaed16a4a, 0xd9d65adc,
	0x40df0b66, 0x37d83bf0, 0xa9bcae53, 0xdebb9ec5, 0x47b2cf7f, 0x30b5ffe9,
	0xbdbdf21c, 0xcabac28a, 0x53b39330, 0x24b4a3a6, 0xbad03605, 0xcdd70693,
	0x54de5729, 0x23d967bf, 0xb3667a2e, 0xc4614ab8, 0x5d681b02, 0x2a6f2b94,
	0xb40bbe37, 0xc30c8ea1, 0x5a05df1b, 0x2d02ef8d
};
#define UPDC32(octet,crc) (crc_32_tab[((crc) ^ ((BYTE)octet)) & 0xff] ^ ((crc) >> 8))

bool rabbit_get_cursor_hash(unsigned int * ret_hash) {

	// get cursor size
	int cx = GetSystemMetrics(SM_CXCURSOR);
	int cy = GetSystemMetrics(SM_CYCURSOR);

	// get cursor info
	CURSORINFO ci;
	ci.cbSize = sizeof(ci);
	GetCursorInfo(&ci);

	// prepare byte array cache
	HANDLE hheap = GetProcessHeap();
	DWORD len_cache = cx*cy*4;
	void * cache = HeapAlloc(hheap, HEAP_ZERO_MEMORY, len_cache);

	// fetch cursor into byte array
	HDC hdc_screen = GetDC(NULL);
	HDC hdc_cache = CreateCompatibleDC(hdc_screen);
	HBITMAP hbm_cache = CreateCompatibleBitmap(hdc_screen, cx, cy);
	SelectObject(hdc_cache, hbm_cache);
	DrawIcon(hdc_cache, 0, 0, ci.hCursor);
	BITMAPINFO bmi = {};
	bmi.bmiHeader.biSize = sizeof(bmi.bmiHeader);
	bmi.bmiHeader.biWidth = cx;
	bmi.bmiHeader.biHeight = cy;
	bmi.bmiHeader.biPlanes = 1;
	bmi.bmiHeader.biBitCount = 32;
	bmi.bmiHeader.biCompression = BI_RGB;
	int ret = GetDIBits(hdc_cache, hbm_cache, 0, cy, cache, &bmi, DIB_RGB_COLORS);
	DeleteObject(hbm_cache);
	DeleteDC(hdc_cache);
	ReleaseDC(NULL, hdc_screen);

	// use crc32 to get hash
	DWORD hash = 0xFFFFFFFF;
	BYTE * tmp = (BYTE *) cache;
	for (int i = 0; i<len_cache; i++)
	{
		hash = UPDC32(*tmp, hash);
		tmp++;
	}
	hash = ~hash; // | 0x80000000;

	HeapFree(hheap, NULL, cache);
	*ret_hash = hash;
	return true;
}

inline bool checkcolor(unsigned int color, BYTE * buff, double tolerance, int x, int y, int w, int h) {
	if (x < 0 || y < 0) return false;
	if (x >= w || y >= h) return false;

	int offset = (y*w+x)*4;

	int b = buff[offset++];
	int g = buff[offset++];
	int r = buff[offset++];
	int rx = (color & 0xFF0000) >> 16;
	int gx = (color & 0x00FF00) >> 8;
	int bx = (color & 0x0000FF) >> 8;

	int ar = abs(r - rx);
	int ag = abs(g - gx);
	int ab = abs(b - bx);
	int dis = pow(ar, 1.5) + pow(ab, 1.5) + pow(ag, 1.5);
	/*
	
	ar = pow(ar, 1.5);
	ab = pow(ab, 1.5);
	ag = pow(ag, 1.5);
	*/
	//printf("%d %d %d\n", r, g, b);
	// printf("%d %lf\n", dis, tolerance);
	
	if (dis <= tolerance) {
		return true;
	}
	return false;
}

bool rabbit_findcolor(int * ret_x, int * ret_y,
	unsigned int color,
	unsigned int x, unsigned int y, unsigned int w, unsigned int h,
	unsigned int order, double tolerance
	) {

	// prepare byte array cache
	HANDLE hheap = GetProcessHeap();
	DWORD len_cache = w*h*4;
	void * cache = HeapAlloc(hheap, HEAP_ZERO_MEMORY, len_cache);

	// fetch cursor into byte array
	HDC hdc_screen = GetDC(NULL);
	HDC hdc_cache = CreateCompatibleDC(hdc_screen);
	HBITMAP hbm_cache = CreateCompatibleBitmap(hdc_screen, w, h);
	SelectObject(hdc_cache, hbm_cache);
	BitBlt(hdc_cache, 0, 0, w, h, hdc_screen, x, y, SRCCOPY | CAPTUREBLT);
	BITMAPINFO bmi = {};
	bmi.bmiHeader.biSize = sizeof(bmi.bmiHeader);
	bmi.bmiHeader.biWidth = w;
	bmi.bmiHeader.biHeight = h;
	bmi.bmiHeader.biPlanes = 1;
	bmi.bmiHeader.biBitCount = 32;
	bmi.bmiHeader.biCompression = BI_RGB;
	int ret = GetDIBits(hdc_screen, hbm_cache, 0, h, cache, &bmi, DIB_RGB_COLORS);
	DeleteObject(hbm_cache);
	DeleteDC(hdc_cache);
	ReleaseDC(NULL, hdc_screen);

	BYTE * map = (BYTE *)cache;

	tolerance = pow(tolerance, 2);
	tolerance *= 3072;

	printf("%lf\n", tolerance);

	int mx = (w+1)/2, my = (h+1)/2;
	int sx, sy = 0;
	int j, k = 0;
	bool found = false;
	for (int i = 0; i < 65536; i++) {
		sx = mx - i;
		sy = my - i;
		if (sx < 0 && sy < 0) break;
		k = i * 2 + 1;
		while (k--) {
			sx += 1;
			if (checkcolor(color, map, tolerance, sx, sy, w, h)) { found = true; break; }
		}
		if (found) break;
		k = i * 2 + 1;
		while (k--) {
			sy += 1;
			if (checkcolor(color, map, tolerance, sx, sy, w, h)) { found = true; break; }
		}
		if (found) break;
		k = i * 2 + 1;
		while (k--) {
			sx -= 1;
			if (checkcolor(color, map, tolerance, sx, sy, w, h)) { found = true; break; }
		}
		if (found) break;
		k = i * 2 + 1;
		while (k--) {
			sy -= 1;
			if (checkcolor(color, map, tolerance, sx, sy, w, h)) { found = true; break; }
		}
		if (found) break;
	}

	if (found) {
		*ret_x = x + sx;
		*ret_y = y + h-sy;
	}
	else {
		*ret_x = -1;
		*ret_y = -1;
	}
	
	HeapFree(hheap, NULL, cache);
	return true;
}