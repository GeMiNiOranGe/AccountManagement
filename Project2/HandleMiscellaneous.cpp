#include "HandleMiscellaneous.h"

void encodePassword(string & strPassword) {
	char cEvent;
	do {
		cEvent = _getch();
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
void textAndBackgroundColor(int textColor, int backgroundColor) {
	int colorCode = backgroundColor * 16 + textColor;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorCode);
}
void resizeConsole(int width, int height) {
	RECT r;
	GetWindowRect(GetConsoleWindow(), &r);
	MoveWindow(GetConsoleWindow(), r.left, r.top, width, height, TRUE);
}
void gotoXY(short x, short y) {
	COORD pos = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void warning(string strMessage) {
	textAndBackgroundColor(7, 4);
	cout << "\a" << strMessage << endl;
	textAndBackgroundColor(7, 0);
	system("pause");
}
char* convertStringToChar(string strInput) {
	char* p_cOutput = new char[strInput.length() + 1];
	strcpy_s(p_cOutput, strInput.length() + 1, strInput.c_str());
	return p_cOutput;
}