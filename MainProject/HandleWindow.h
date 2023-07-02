#ifndef HANDLEWINDOW_H
#define HANDLEWINDOW_H
#pragma once

#include <Windows.h>

//window-and-screen-buffer-size
namespace window {
	namespace moveTo {
		extern short offsetLeft;
		extern short offsetMiddle;
		extern short offsetRight;
		void leftTop();
		void left();
		void leftBottom();
		void top();
		void center();
		void bottom();
		void rightTop();
		void right();
		void rightBottom();
	} // namespace move
	void moveToXY(short posX, short posY);
	void resize(short width, short height);
} // namespace window

#endif // end HANDLEWINDOW_H