#include "HandleConsole.hpp"

const short console::move_to::OFFSET_MIDDLE_COLUMN = 8;
const short console::move_to::OFFSET_RIGHT = 16;
const short console::move_to::OFFSET_MIDDLE_ROW = 4;
const short console::move_to::OFFSET_BOTTOM = 8;

const SIZE console::move_to::WORK_AREA_SIZE = window::get_work_area_size();

#pragma region Top of the screen
void console::move_to::top_left() {
	int pos_x = 0,
		pos_y = 0;
	move_to_xy(pos_x, pos_y);
}
void console::move_to::top() {
	RECT rect_window;
	HWND hwnd = GetConsoleWindow();
	GetWindowRect(hwnd, &rect_window);
	int pos_x = WORK_AREA_SIZE.cx / 2 - (rect_window.right - rect_window.left) / 2 + OFFSET_MIDDLE_COLUMN,
		pos_y = 0;
	move_to_xy(pos_x, pos_y);
}
void console::move_to::top_right() {
	RECT rect_window;
	HWND hwnd = GetConsoleWindow();
	GetWindowRect(hwnd, &rect_window);
	int pos_x = WORK_AREA_SIZE.cx - (rect_window.right - rect_window.left) + OFFSET_RIGHT,
		pos_y = 0;
	move_to_xy(pos_x, pos_y);
}
#pragma endregion

#pragma region Middle of the screen
void console::move_to::left() {
	RECT rect_window;
	HWND hwnd = GetConsoleWindow();
	GetWindowRect(hwnd, &rect_window);
	int pos_x = 0,
		pos_y = WORK_AREA_SIZE.cy / 2 - (rect_window.bottom - rect_window.top) / 2 + OFFSET_MIDDLE_ROW;
	move_to_xy(pos_x, pos_y);
}
void console::move_to::center() {
	RECT rect_window;
	HWND hwnd = GetConsoleWindow();
	GetWindowRect(hwnd, &rect_window);
	int pos_x = WORK_AREA_SIZE.cx / 2 - (rect_window.right - rect_window.left) / 2 + OFFSET_MIDDLE_COLUMN,
		pos_y = WORK_AREA_SIZE.cy / 2 - (rect_window.bottom - rect_window.top) / 2 + OFFSET_MIDDLE_ROW;
	move_to_xy(pos_x, pos_y);
}
void console::move_to::right() {
	RECT rect_window;
	HWND hwnd = GetConsoleWindow();
	GetWindowRect(hwnd, &rect_window);
	int pos_x = WORK_AREA_SIZE.cx - (rect_window.right - rect_window.left) + OFFSET_RIGHT,
		pos_y = WORK_AREA_SIZE.cy / 2 - (rect_window.bottom - rect_window.top) / 2 + OFFSET_MIDDLE_ROW;
	move_to_xy(pos_x, pos_y);
}
#pragma endregion

#pragma region Bottom of the screen
void console::move_to::bottom_left() {
	RECT rect_window;
	HWND hwnd = GetConsoleWindow();
	GetWindowRect(hwnd, &rect_window);
	int pos_x = 0,
		pos_y = WORK_AREA_SIZE.cy - (rect_window.bottom - rect_window.top) + OFFSET_BOTTOM;
	move_to_xy(pos_x, pos_y);
}
void console::move_to::bottom() {
	RECT rect_window;
	HWND hwnd = GetConsoleWindow();
	GetWindowRect(hwnd, &rect_window);
	int pos_x = WORK_AREA_SIZE.cx / 2 - (rect_window.right - rect_window.left) / 2 + OFFSET_MIDDLE_COLUMN,
		pos_y = WORK_AREA_SIZE.cy - (rect_window.bottom - rect_window.top) + OFFSET_BOTTOM;
	move_to_xy(pos_x, pos_y);
}
void console::move_to::bottom_right() {
	RECT rect_window;
	HWND hwnd = GetConsoleWindow();
	GetWindowRect(hwnd, &rect_window);
	int pos_x = WORK_AREA_SIZE.cx - (rect_window.right - rect_window.left) + OFFSET_RIGHT,
		pos_y = WORK_AREA_SIZE.cy - (rect_window.bottom - rect_window.top) + OFFSET_BOTTOM;
	move_to_xy(pos_x, pos_y);
}
#pragma endregion

void console::move_to_xy(short pos_x, short pos_y) {
	RECT rect_window;
	HWND hwnd = GetConsoleWindow();
	GetWindowRect(hwnd, &rect_window);
	MoveWindow(hwnd, pos_x - 8, pos_y, rect_window.right - rect_window.left, rect_window.bottom - rect_window.top, TRUE);
}

void console::resize(short width, short height) {
	RECT rect_client, rect_window;
	POINT point_offset;
	HWND hwnd = GetConsoleWindow();
	GetClientRect(hwnd, &rect_client);
	GetWindowRect(hwnd, &rect_window);
	// find the offset to add to the screen (e.g: x = 33, y = 39)
	point_offset.x = (rect_window.right - rect_window.left) - rect_client.right;
	point_offset.y = (rect_window.bottom - rect_window.top) - rect_client.bottom;
	MoveWindow(hwnd, rect_window.left, rect_window.top, width + point_offset.x, height + point_offset.y, TRUE);
}
