#ifndef HANDLEWINDOW_H
#define HANDLEWINDOW_H
#pragma once

#include <Windows.h>

//window-and-screen-buffer-size
namespace window {
	namespace moveTo {
		void top();
		void topLeft();
		void topRight();
		void bottom();
		void bottomLeft();
		void bottomRight();
		void left();
		void right();
		void center();
	} // namespace move
	void moveToXY(short posX, short posY);
	void resize(short width, short height);
} // namespace window

#endif // end HANDLEWINDOW_H