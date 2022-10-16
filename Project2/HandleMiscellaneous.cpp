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
	int colorCode = backgroundColor * 16 + textColor;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorCode);
}

void resizeConsole(int width, int height) {
	RECT r;
	GetWindowRect(GetConsoleWindow(), &r);
	MoveWindow(GetConsoleWindow(), r.left, r.top, width, height, TRUE);
}

void gotoXY(int x, int y) {
	COORD pos = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void chooseWrong() {
	textAndBackgroundColor(7, 4);
	cout << "\a\tLua chon khong hop le!!!" << endl;
	textAndBackgroundColor(7, 0);
	cout << "\t";
	system("pause");
}
