#pragma once
#ifndef HANDLEWINDOW_HPP
#define HANDLEWINDOW_HPP

#include <Windows.h>

//window-and-screen-buffer-size
namespace window {
	int get_taskbar_height();
	SIZE get_work_area_size();
} // namespace window

#endif // end HANDLEWINDOW_HPP