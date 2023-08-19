#include "HandleConsole.h"

void console::resize(short width, short height) {
	HWND hwnd = GetConsoleWindow();
	RECT rect_client, rect_window;
	POINT ptDiff;
	GetClientRect(hwnd, &rect_client);
	GetWindowRect(hwnd, &rect_window);
	// find the offset to add to the screen (e.g: x = 33, y = 39)
	ptDiff.x = (rect_window.right - rect_window.left) - rect_client.right;
	ptDiff.y = (rect_window.bottom - rect_window.top) - rect_client.bottom;
	MoveWindow(hwnd, rect_window.left, rect_window.top, width + ptDiff.x, height + ptDiff.y, TRUE);
}
