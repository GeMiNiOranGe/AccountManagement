#pragma once
#ifndef SYSUTILS_HPP
#define SYSUTILS_HPP

#include <Windows.h>
#include <dwmapi.h>

#pragma comment(lib, "Dwmapi.lib")

namespace screen {
int get_taskbar_height();
SIZE get_work_area_size();
}  // namespace screen

namespace window {
extern const SIZE WORK_AREA_SIZE;
void move_to_top_left(bool visual = true);
void move_to_top(bool visual = true);
void move_to_top_right(bool visual = true);
void move_to_left(bool visual = true);
void move_to_center(bool visual = true);
void move_to_right(bool visual = true);
void move_to_bottom_left(bool visual = true);
void move_to_bottom(bool visual = true);
void move_to_bottom_right(bool visual = true);
void move_to_xy(LONG x_coord, LONG y_coord, bool visual = true);
void resize(LONG width, LONG height);
namespace visual {
void move_to_top_left();
void move_to_top();
void move_to_top_right();
void move_to_left();
void move_to_center();
void move_to_right();
void move_to_bottom_left();
void move_to_bottom();
void move_to_bottom_right();
void move_to_xy(LONG x_coord, LONG y_coord);
}  // namespace visual
namespace standard {
void move_to_top_left();
void move_to_top();
void move_to_top_right();
void move_to_left();
void move_to_center();
void move_to_right();
void move_to_bottom_left();
void move_to_bottom();
void move_to_bottom_right();
void move_to_xy(LONG x_coord, LONG y_coord);
}  // namespace standard
}  // namespace window

#endif // end SYSUTILS_HPP
