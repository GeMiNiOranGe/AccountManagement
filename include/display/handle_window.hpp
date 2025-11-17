#pragma once
#ifndef HANDLE_WINDOW_HPP
#define HANDLE_WINDOW_HPP

#include <Windows.h>

// window-and-screen-buffer-size
namespace window {
int get_taskbar_height();
SIZE get_work_area_size();
}  // namespace window

#endif  // end HANDLE_WINDOW_HPP
