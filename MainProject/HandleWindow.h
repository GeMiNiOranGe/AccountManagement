#ifndef HANDLEWINDOW_H
#define HANDLEWINDOW_H
#pragma once

#include <Windows.h>

//window-and-screen-buffer-size
namespace window {
	int get_taskbar_height();
	SIZE get_work_area_size();
} // namespace window

#endif // end HANDLEWINDOW_H