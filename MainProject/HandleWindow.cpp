#include "HandleWindow.h"

void window::moveTo::top() {
	RECT rectWindow;
	HWND hWnd = GetConsoleWindow();
	GetWindowRect(hWnd, &rectWindow);
	int posX = GetSystemMetrics(SM_CXSCREEN) / 2 - (rectWindow.right - rectWindow.left) / 2,
		posY = 0;
	moveToXY(posX, posY);
}

void window::moveTo::topLeft() {
	RECT rectWindow;
	HWND hWnd = GetConsoleWindow();
	GetWindowRect(hWnd, &rectWindow);
	int posX = 0,
		posY = 0;
	moveToXY(posX, posY);
}

void window::moveTo::topRight() {
	RECT rectWindow;
	HWND hWnd = GetConsoleWindow();
	GetWindowRect(hWnd, &rectWindow);
	int posX = GetSystemMetrics(SM_CXSCREEN) - (rectWindow.right - rectWindow.left),
		posY = 0;
	moveToXY(posX, posY);
}

void window::moveTo::bottom() {
	RECT rectWindow;
	HWND hWnd = GetConsoleWindow();
	GetWindowRect(hWnd, &rectWindow);
	int posX = GetSystemMetrics(SM_CXSCREEN) / 2 - (rectWindow.right - rectWindow.left) / 2,
		posY = GetSystemMetrics(SM_CYSCREEN) - (rectWindow.bottom - rectWindow.top);
	moveToXY(posX, posY);
}

void window::moveTo::bottomLeft() {
	RECT rectWindow;
	HWND hWnd = GetConsoleWindow();
	GetWindowRect(hWnd, &rectWindow);
	int posX = 0,
		posY = GetSystemMetrics(SM_CYSCREEN) - (rectWindow.bottom - rectWindow.top);
	moveToXY(posX, posY);
}

void window::moveTo::bottomRight() {
	RECT rectWindow;
	HWND hWnd = GetConsoleWindow();
	GetWindowRect(hWnd, &rectWindow);
	int posX = GetSystemMetrics(SM_CXSCREEN) - (rectWindow.right - rectWindow.left),
		posY = GetSystemMetrics(SM_CYSCREEN) - (rectWindow.bottom - rectWindow.top);
	moveToXY(posX, posY);
}

void window::moveTo::left() {
	RECT rectWindow;
	HWND hWnd = GetConsoleWindow();
	GetWindowRect(hWnd, &rectWindow);
	int posX = 0,
		posY = GetSystemMetrics(SM_CYSCREEN) / 2 - (rectWindow.bottom - rectWindow.top) / 2;
	moveToXY(posX, posY);
}

void window::moveTo::right() {
	RECT rectWindow;
	HWND hWnd = GetConsoleWindow();
	GetWindowRect(hWnd, &rectWindow);
	int posX = GetSystemMetrics(SM_CXSCREEN) - (rectWindow.right - rectWindow.left),
		posY = GetSystemMetrics(SM_CYSCREEN) / 2 - (rectWindow.bottom - rectWindow.top) / 2;
	moveToXY(posX, posY);
}

void window::moveTo::center() {
	RECT rectWindow;
	HWND hWnd = GetConsoleWindow();
	GetWindowRect(hWnd, &rectWindow);
	int posX = GetSystemMetrics(SM_CXSCREEN) / 2 - (rectWindow.right - rectWindow.left) / 2,
		posY = GetSystemMetrics(SM_CYSCREEN) / 2 - (rectWindow.bottom - rectWindow.top) / 2;
	moveToXY(posX, posY);
}

void window::moveToXY(short posX, short posY) {
	RECT rectClient;
	HWND hWnd = GetConsoleWindow();
	GetClientRect(hWnd, &rectClient);
	MoveWindow(hWnd, posX, posY, rectClient.right - rectClient.left, rectClient.bottom - rectClient.top, TRUE);
}

void window::resize(short width, short height) {
}
