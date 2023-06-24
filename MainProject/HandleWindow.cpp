#include "HandleWindow.h"

void window::moveTo::top() {

}

void window::moveTo::topLeft() {
}

void window::moveTo::topRight() {
}

void window::moveTo::bottom() {
}

void window::moveTo::bottomLeft() {
}

void window::moveTo::bottomRight() {
}

void window::moveTo::left() {
}

void window::moveTo::right() {
}

void window::moveTo::center() {
	RECT rectClient, rectWindow;
	HWND hWnd = GetConsoleWindow();
	GetClientRect(hWnd, &rectClient);
	GetWindowRect(hWnd, &rectWindow);
	int posx, posy;
	posx = GetSystemMetrics(SM_CXSCREEN) / 2 - (rectWindow.right - rectWindow.left) / 2;
	posy = GetSystemMetrics(SM_CYSCREEN) / 2 - (rectWindow.bottom - rectWindow.top) / 2;

	MoveWindow(hWnd, posx, posy, rectClient.right - rectClient.left, rectClient.bottom - rectClient.top, TRUE);
}

void window::moveToXY(short posX, short posY) {
	RECT rectClient, rectWindow;
	HWND hWnd = GetConsoleWindow();
	GetClientRect(hWnd, &rectClient);
	GetWindowRect(hWnd, &rectWindow);
	MoveWindow(hWnd, posX, posY, rectClient.right - rectClient.left, rectClient.bottom - rectClient.top, TRUE);
}

void window::resize(short width, short height) {
}
