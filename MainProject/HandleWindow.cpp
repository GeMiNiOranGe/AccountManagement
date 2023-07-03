#include "HandleWindow.h"

const short window::moveTo::OFFSET_LEFT = -6;
const short window::moveTo::OFFSET_RIGHT = 6;
const short window::moveTo::OFFSET_MIDDLE = 3;
const short window::moveTo::OFFSET_BOTTOM = 6;

const LONG window::moveTo::WORK_AREA_CX = window::getWorkAreaSize().cx;
const LONG window::moveTo::WORK_AREA_CY = window::getWorkAreaSize().cy;

#pragma region Left side of the screen
void window::moveTo::leftTop() {
	int posX = OFFSET_LEFT,
		posY = 0;
	moveToXY(posX, posY);
}
void window::moveTo::left() {
	RECT rectWindow;
	HWND hWnd = GetConsoleWindow();
	GetWindowRect(hWnd, &rectWindow);
	int posX = OFFSET_LEFT,
		posY = WORK_AREA_CY / 2 - (rectWindow.bottom - rectWindow.top) / 2 + OFFSET_MIDDLE;
	moveToXY(posX, posY);
}
void window::moveTo::leftBottom() {
	RECT rectWindow;
	HWND hWnd = GetConsoleWindow();
	GetWindowRect(hWnd, &rectWindow);
	int posX = OFFSET_LEFT,
		posY = WORK_AREA_CY - (rectWindow.bottom - rectWindow.top) + OFFSET_BOTTOM;
	moveToXY(posX, posY);
}
#pragma endregion

#pragma region Middle of the screen
void window::moveTo::top() {
	RECT rectWindow;
	HWND hWnd = GetConsoleWindow();
	GetWindowRect(hWnd, &rectWindow);
	int posX = WORK_AREA_CX / 2 - (rectWindow.right - rectWindow.left) / 2,
		posY = 0;
	moveToXY(posX, posY);
}
void window::moveTo::center() {
	RECT rectWindow;
	HWND hWnd = GetConsoleWindow();
	GetWindowRect(hWnd, &rectWindow);
	int posX = WORK_AREA_CX / 2 - (rectWindow.right - rectWindow.left) / 2,
		posY = WORK_AREA_CY / 2 - (rectWindow.bottom - rectWindow.top) / 2 + OFFSET_MIDDLE;
	moveToXY(posX, posY);
}
void window::moveTo::bottom() {
	RECT rectWindow;
	HWND hWnd = GetConsoleWindow();
	GetWindowRect(hWnd, &rectWindow);
	int posX = WORK_AREA_CX / 2 - (rectWindow.right - rectWindow.left) / 2,
		posY = WORK_AREA_CY - (rectWindow.bottom - rectWindow.top) + OFFSET_BOTTOM;
	moveToXY(posX, posY);
}
#pragma endregion

#pragma region Right side of the screen
void window::moveTo::rightTop() {
	RECT rectWindow;
	HWND hWnd = GetConsoleWindow();
	GetWindowRect(hWnd, &rectWindow);
	int posX = WORK_AREA_CX - (rectWindow.right - rectWindow.left) + OFFSET_RIGHT,
		posY = 0;
	moveToXY(posX, posY);
}
void window::moveTo::right() {
	RECT rectWindow;
	HWND hWnd = GetConsoleWindow();
	GetWindowRect(hWnd, &rectWindow);
	int posX = WORK_AREA_CX - (rectWindow.right - rectWindow.left) + OFFSET_RIGHT,
		posY = WORK_AREA_CY / 2 - (rectWindow.bottom - rectWindow.top) / 2 + OFFSET_MIDDLE;
	moveToXY(posX, posY);
}
void window::moveTo::rightBottom() {
	RECT rectWindow;
	HWND hWnd = GetConsoleWindow();
	GetWindowRect(hWnd, &rectWindow);
	int posX = WORK_AREA_CX - (rectWindow.right - rectWindow.left) + OFFSET_RIGHT,
		posY = WORK_AREA_CY - (rectWindow.bottom - rectWindow.top) + OFFSET_BOTTOM;
	moveToXY(posX, posY);
}
#pragma endregion

int window::getTaskBarHeight() {
	RECT rect;
	HWND taskBar = FindWindow(L"Shell_traywnd", NULL);
	GetWindowRect(taskBar, &rect);
	int height = rect.bottom - rect.top;
	return height;
}

SIZE window::getWorkAreaSize() {
	RECT rectWorkArea;
	SystemParametersInfo(SPI_GETWORKAREA, 0, &rectWorkArea, 0);
	SIZE workAreaSize = {
		rectWorkArea.right - rectWorkArea.left,
		rectWorkArea.bottom - rectWorkArea.top
	};
	return workAreaSize;
}

void window::moveToXY(short posX, short posY) {
	RECT rectWindow;
	HWND hWnd = GetConsoleWindow();
	GetWindowRect(hWnd, &rectWindow);
	MoveWindow(hWnd, posX, posY, rectWindow.right - rectWindow.left, rectWindow.bottom - rectWindow.top, TRUE);
}

void window::resize(short width, short height) {
	RECT rectWindow;
	HWND hWnd = GetConsoleWindow();
	GetWindowRect(hWnd, &rectWindow);
	MoveWindow(hWnd, rectWindow.left, rectWindow.top, width, height, TRUE);
}