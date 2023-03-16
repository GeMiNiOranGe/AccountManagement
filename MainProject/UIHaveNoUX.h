#ifndef UIHAVENOUX_H
#define UIHAVENOUX_H
#pragma once

#include <iomanip>
#include <io.h>
#include <fcntl.h>
#include <vector>
#include <tuple>
#include "BoxBorder.h"
#include "HandleIO.h"
#include "HandleMain.h"
#include "HandleMiscellaneous.h"
//#include "CUser.h"
//#include "HandleMain.h"
// if ((title.size() + fillSize) % 2 == 1) fillSize++; else sumSize++;

std::string formLogin(std::string & strUsername, std::string & strPassword);
void formInfo(short labelSize, short fillSize, std::wstring title);
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
void showBorder(std::vector<short> numberOfFill, std::string posBorder);
void showInfoAnAccount(std::vector<std::tuple<short, std::wstring>> _vector, Color textColor, wchar_t fillType = L' ');
void showInfoAllEmployee();

char menuAdmin();
char menuEmployee();
char menuUpdateInfo();

std::wstring convertToWString(const std::string & _string);

#endif
