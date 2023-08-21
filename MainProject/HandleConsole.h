#ifndef HANDLECONSOLE_H
#define HANDLECONSOLE_H
#pragma once

#include <Windows.h>
#include "HandleWindow.h"

namespace console {
	namespace move_to {
		void top_left();
		void top();
		void top_right();
		void left();
		void center();
		void right();
		void bottom_left();
		void bottom();
		void bottom_right();
		extern const short OFFSET_MIDDLE_COLUMN;
		extern const short OFFSET_RIGHT;
		extern const short OFFSET_MIDDLE_ROW;
		extern const short OFFSET_BOTTOM;
		extern const SIZE WORK_AREA_SIZE;
	} // namespace move_to
	void move_to_xy(short posX, short posY);
	void resize(short width, short height);
} // namespace console

#endif // end HANDLECONSOLE_H