#include "handle_window.hpp"

int window::get_taskbar_height() {
	RECT rect;
	HWND taskbar = FindWindow(L"Shell_traywnd", NULL);
	GetWindowRect(taskbar, &rect);
	int height = rect.bottom - rect.top;
	return height;
}

SIZE window::get_work_area_size() {
	RECT rect_work_area;
	SystemParametersInfo(SPI_GETWORKAREA, 0, &rect_work_area, 0);
	SIZE work_area_size = {
		rect_work_area.right - rect_work_area.left,
		rect_work_area.bottom - rect_work_area.top
	};
	return work_area_size;
}
