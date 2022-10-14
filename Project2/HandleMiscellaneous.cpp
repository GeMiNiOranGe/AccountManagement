#include "HandleMiscellaneous.h"

void encodePassword(string & strPassword) {
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
			cout << "\b \b";
			strPassword.pop_back();
		}
		else {
			strPassword.push_back(cEvent);
			cout << cEvent;
			Sleep(100);
			cout << "\b \b*";
		}
	}
	while (cEvent != 13);
}

// 0 = Black  |  8 = Gray
// 1 = Blue   |  9 = Light Blue
// 2 = Green  | 10 = Light Green
// 3 = Aqua   | 11 = Light Aqua
// 4 = Red    | 12 = Light Red
// 5 = Purple | 13 = Light Purple
// 6 = Yellow | 14 = Light Yellow
// 7 = White  | 15 = Bright White
void textAndBackgroundColor(int textColor, int backgroundColor) {
	int tempColor = backgroundColor * 16 + textColor;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, tempColor);
}

void resizeConsole(int width, int height) {
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}