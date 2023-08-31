#include "HandleMiscellaneous.hpp"

void encode_password(std::string & _password) {
	char event_key;
	do {
		event_key = _getch();
		// ESC key
		if (event_key == 27)
			exit(0);
		// BACKSPACE key
		if (event_key == 8 && !_password.empty()) {
			std::cout << "\b \b";
			_password.pop_back();
		}
		// Erase a line with "CTRL + BACKSPACE"
		if (event_key == 127) {
			for (int i = 0; i < _password.size(); i++)
				std::cout << "\b \b";
			_password.clear();
		}
		// Printable characters
		if (isprint(event_key)) {
			_password.push_back(event_key);
			std::cout << event_key;
			Sleep(100);
			std::cout << "\b \b*";
		}
		// Not the ENTER key
	} while (event_key != 13);
}
void set_color(Color text_color, Color background_color) {
	short color_code = static_cast<short>(background_color) * 16 + static_cast<short>(text_color);
	HANDLE handle_std_out = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle_std_out, color_code);

	//TODO: class ConsoleColor by singleton in namespace console
	// getForeColor, getBackColor
}
void go_to_xy(short x, short y) {
	COORD pos = { x, y };
	HANDLE handle_std_out = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(handle_std_out, pos);
}
void warning(std::string _message) {
	set_color(Color::WHITE, Color::RED);
	std::cout << "\a" << _message << std::endl;
	set_color(Color::WHITE, Color::BLACK);
	system("pause");
}
