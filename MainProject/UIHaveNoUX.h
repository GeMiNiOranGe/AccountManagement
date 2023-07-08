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

std::string form_login(std::string & username, std::string & password, box::BorderStyle style = box::BorderStyle::SINGLE);
void form_info(std::wstring title, std::vector<std::wstring> labels, box::BorderStyle style = box::BorderStyle::SINGLE, short fill_size = 25);
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
void show_a_part_border(std::vector<short> number_of_fill, Position _position, box::BorderStyle style = box::BorderStyle::SINGLE);
void show_info_account(
	std::vector<std::pair<short, std::wstring>> maxSizeAndWStringPairs,
	Color textColor,
	wchar_t fillType = L' ',
	box::BorderStyle style = box::BorderStyle::SINGLE);
void show_info_accounts();

char menuAdmin();
char menuEmployee();
char menuUpdateInfo();

#endif
