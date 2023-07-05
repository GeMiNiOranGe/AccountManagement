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
void textAndBackgroundColor(Color textColor, Color backgroundColor) {
	short colorCode = static_cast<short>(backgroundColor) * 16 + static_cast<short>(textColor);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorCode);

	//TODO: class ConsoleColor by singleton in namespace console
	// getForeColor, getBackColor
}
void resizeConsole(int width, int height) {
	RECT r;
	GetWindowRect(GetConsoleWindow(), &r);
	MoveWindow(GetConsoleWindow(), r.left, r.top, width, height, TRUE);
}
void gotoXY(short x, short y) {
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void warning(std::string strMessage) {
	textAndBackgroundColor(Color::WHITE, Color::RED);
	std::cout << "\a" << strMessage << std::endl;
	textAndBackgroundColor(Color::WHITE, Color::BLACK);
	system("pause");
}
std::wstring convertToWString(const std::string & _string) {
	return std::wstring(_string.begin(), _string.end());
}
//char * convertStringToChar(std::string strInput) {
//	char * p_cOutput = new char[strInput.length() + 1];
//	strcpy_s(p_cOutput, strInput.length() + 1, strInput.c_str());
//	return p_cOutput;
//}

