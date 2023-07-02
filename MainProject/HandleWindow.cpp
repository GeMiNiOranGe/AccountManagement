#include "HandleWindow.h"

short window::moveTo::offsetLeft = -6;
short window::moveTo::offsetMiddle = 17;
short window::moveTo::offsetRight = 40;

#pragma region Left side of the screen
void window::moveTo::leftTop() {
	int posX = offsetleft,
		posY = 0;
	moveToXY(posX, posY);
}
void window::moveTo::left() {
	RECT rectWindow;
	HWND hWnd = GetConsoleWindow();
	GetWindowRect(hWnd, &rectWindow);
	int posX = offsetLeft,
		posY = GetSystemMetrics(SM_CYSCREEN) / 2 - (rectWindow.bottom - rectWindow.top) / 2;
	moveToXY(posX, posY);
}
void window::moveTo::leftBottom() {
	RECT rectWindow;
	HWND hWnd = GetConsoleWindow();
	GetWindowRect(hWnd, &rectWindow);
	int posX = offsetLeft,
		posY = GetSystemMetrics(SM_CYSCREEN) - (rectWindow.bottom - rectWindow.top);
	moveToXY(posX, posY);
}
#pragma endregion

#pragma region Middle of the screen
void window::moveTo::top() {
	RECT rectWindow;
	HWND hWnd = GetConsoleWindow();
	GetWindowRect(hWnd, &rectWindow);
	int posX = GetSystemMetrics(SM_CXSCREEN) / 2 - (rectWindow.right - rectWindow.left) / 2 + offsetMiddle,
		posY = 0;
	moveToXY(posX, posY);
}
void window::moveTo::center() {
	RECT rectWindow;
	HWND hWnd = GetConsoleWindow();
	GetWindowRect(hWnd, &rectWindow);
	int posX = GetSystemMetrics(SM_CXSCREEN) / 2 - (rectWindow.right - rectWindow.left) / 2 + offsetMiddle,
		posY = GetSystemMetrics(SM_CYSCREEN) / 2 - (rectWindow.bottom - rectWindow.top) / 2;
	moveToXY(posX, posY);
}
void window::moveTo::bottom() {
	RECT rectWindow;
	HWND hWnd = GetConsoleWindow();
	GetWindowRect(hWnd, &rectWindow);
	int posX = GetSystemMetrics(SM_CXSCREEN) / 2 - (rectWindow.right - rectWindow.left) / 2 + offsetMiddle,
		posY = GetSystemMetrics(SM_CYSCREEN) - (rectWindow.bottom - rectWindow.top);
	moveToXY(posX, posY);
}
#pragma endregion

#pragma region Right side of the screen
void window::moveTo::rightTop() {
	RECT rectWindow;
	HWND hWnd = GetConsoleWindow();
	GetWindowRect(hWnd, &rectWindow);
	int posX = GetSystemMetrics(SM_CXSCREEN) - (rectWindow.right - rectWindow.left) + offsetRight,
		posY = 0;
	moveToXY(posX, posY);
}
void window::moveTo::right() {
	RECT rectWindow;
	HWND hWnd = GetConsoleWindow();
	GetWindowRect(hWnd, &rectWindow);
	int posX = GetSystemMetrics(SM_CXSCREEN) - (rectWindow.right - rectWindow.left) + offsetRight,
		posY = GetSystemMetrics(SM_CYSCREEN) / 2 - (rectWindow.bottom - rectWindow.top) / 2;
	moveToXY(posX, posY);
}
void window::moveTo::rightBottom() {
	RECT rectWindow;
	HWND hWnd = GetConsoleWindow();
	GetWindowRect(hWnd, &rectWindow);
	int posX = GetSystemMetrics(SM_CXSCREEN) - (rectWindow.right - rectWindow.left) + offsetRight,
		posY = GetSystemMetrics(SM_CYSCREEN) - (rectWindow.bottom - rectWindow.top);
	moveToXY(posX, posY);
}
#pragma endregion

void window::moveToXY(short posX, short posY) {
	RECT rectClient;
	HWND hWnd = GetConsoleWindow();
	GetClientRect(hWnd, &rectClient);
	MoveWindow(hWnd, posX, posY, rectClient.right - rectClient.left, rectClient.bottom - rectClient.top, TRUE);
}

void window::resize(short width, short height) {
}
