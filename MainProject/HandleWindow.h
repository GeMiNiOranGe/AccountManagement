#ifndef HANDLEWINDOW_H
#define HANDLEWINDOW_H
#pragma once

#include <Windows.h>

//window-and-screen-buffer-size
namespace window {
	namespace moveTo {
		void leftTop();
		void left();
		void leftBottom();
		void top();
		void center();
		void bottom();
		void rightTop();
		void right();
		void rightBottom();
		extern const short OFFSET_LEFT;
		extern const short OFFSET_RIGHT;
		extern const short OFFSET_MIDDLE;
		extern const short OFFSET_BOTTOM;
		extern const LONG WORK_AREA_CX;
		extern const LONG WORK_AREA_CY;
	};
	int getTaskBarHeight();
	SIZE getWorkAreaSize();
	void moveToXY(short posX, short posY);
	void resize(short width, short height);
} // namespace window

#endif // end HANDLEWINDOW_H