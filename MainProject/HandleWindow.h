#ifndef HANDLEWINDOW_H
#define HANDLEWINDOW_H
#pragma once

#include <Windows.h>

//window-and-screen-buffer-size
namespace window {
	namespace move_to {
		void left_top();
		void left();
		void left_bottom();
		void top();
		void center();
		void bottom();
		void right_top();
		void right();
		void right_bottom();
		extern const short OFFSET_LEFT;
		extern const short OFFSET_RIGHT;
		extern const short OFFSET_MIDDLE;
		extern const short OFFSET_BOTTOM;
		extern const LONG WORK_AREA_CX;
		extern const LONG WORK_AREA_CY;
	};
	int get_taskbar_height();
	SIZE get_work_area_size();
	void move_to_xy(short posX, short posY);
	void resize(short width, short height);
} // namespace window

#endif // end HANDLEWINDOW_H