#include "HandleMiscellaneous.h"

void encodePassword(std::string & strPassword) {
	char cEvent;
	do {
		cEvent = _getch();
		// ESC key
		//if (cEvent == 27) {
		//	exit(0);
		//}

		//TODO: make erase a line with "ctrl + backspace" ascii: 127

		// ENTER key
		if (cEvent == 13) {
			break;
		}
		// BACKSPACE key
		if (cEvent == 8 && !strPassword.empty()) {
			std::cout << "\b \b";
			strPassword.pop_back();
		}
		else {
			strPassword.push_back(cEvent);
			std::cout << cEvent;
			Sleep(100);
			std::cout << "\b \b*";
		}
	} while (cEvent != 13);
}
void textAndBackgroundColor(Color text_color, Color background_color) {
	short color_code = static_cast<short>(background_color) * 16 + static_cast<short>(text_color);
	HANDLE handle_std_out = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle_std_out, color_code);

	//TODO: class ConsoleColor by singleton in namespace console
	// getForeColor, getBackColor
}
void gotoXY(short x, short y) {
	COORD pos = { x, y };
	HANDLE handle_std_out = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(handle_std_out, pos);
}
void warning(std::string strMessage) {
	textAndBackgroundColor(Color::WHITE, Color::RED);
	std::cout << "\a" << strMessage << std::endl;
	textAndBackgroundColor(Color::WHITE, Color::BLACK);
	system("pause");
}
