#ifndef HANDLEMISCELLANEOUS_H
#define HANDLEMISCELLANEOUS_H
#pragma once

#include <iostream>
#include <Windows.h>
#include <string>
#include <conio.h>

using namespace std;

void encodePassword(string & strHandle);
void textAndBackgroundColor(int textColor, int backgroundColor);
void resizeConsole(int width, int height);
void gotoXY(int x, int y);
void chooseWrong();

#endif