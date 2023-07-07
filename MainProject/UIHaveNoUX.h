#ifndef UIHAVENOUX_H
#define UIHAVENOUX_H
#pragma once

#include <iomanip>
#include <io.h>
#include <fcntl.h>
#include <vector>
#include "BoxBorder.h"
#include "HandleIO.h"
#include "HandleMain.h"
#include "HandleMiscellaneous.h"
#include "Convert.h"
//#include "CUser.h"
//#include "HandleMain.h"
// if ((title.size() + fillSize) % 2 == 1) fillSize++; else sumSize++;

enum class Position {
	FIRST,
	MIDDLE,
	LAST
};

std::string formLogin(std::string & strUsername, std::string & strPassword);
void formInfo(short labelSize, short fillSize, std::wstring title, box::BorderStyle _style);
char chooseAdminOrEmployee();
void loginAdmin(std::string & strUsername, std::string & strPassword);
void loginEmployees(std::string & strUsername, std::string & strPassword, int iMaxLogin);

//#pragma region Variable template function
//// TODO: make variadic pack first: showInfoAnAccount(std::tuple<int, std::string> arg, Color textColor, char fillType = ' ');
//// Modify single tuple
//void showInfoAnAccount(Color textColor, wchar_t fillType, std::tuple<short, std::string> arg);
//// Modify multiple tuple. Here we use parameters pack by '...T'
//template<typename ...T>
//void showInfoAnAccount(Color textColor, wchar_t fillType, std::tuple<short, std::string> arg, T ...args) {
//	showInfoAnAccount(textColor, fillType, arg);
//	showInfoAnAccount(textColor, fillType, args...);
//}
//#pragma endregion
void show_a_part_border(std::vector<short> number_of_fill, Position _position, box::BorderStyle _style = box::BorderStyle::SINGLE);
void show_info_account(
	std::vector<std::pair<short, std::wstring>> maxSizeAndWStringPairs,
	Color textColor,
	wchar_t fillType = L' ',
	box::BorderStyle _style = box::BorderStyle::SINGLE);
void show_info_accounts();

char menuAdmin();
char menuEmployee();
char menuUpdateInfo();

std::wstring convert_to_wstring(const std::string & _string);

#endif
