#ifndef HANDLEWINDOW_H
#define HANDLEWINDOW_H
#pragma once

#include <Windows.h>

//window-and-screen-buffer-size
namespace window {
	class moveTo {
	public:
		static void leftTop();
		static void left();
		static void leftBottom();
		static void top();
		static void center();
		static void bottom();
		static void rightTop();
		static void right();
		static void rightBottom();
	private:
		static const short offsetLeft = -6;
		static const short offsetMiddle = 17;
		static const short offsetRight = 40;
	};
	void moveToXY(short posX, short posY);
	void resize(short width, short height);
} // namespace window

#endif // end HANDLEWINDOW_H