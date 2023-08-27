#pragma once
#ifndef UIHAVENOUX_HPP
#define UIHAVENOUX_HPP

#include <iomanip>
#include <io.h>
#include <fcntl.h>
#include <vector>
#include "BoxBorder.h"
#include "FileIO.h"
#include "HandleMain.h"
#include "HandleMiscellaneous.h"
#include "Convert.h"
#include "Position.h"
//#include "CUser.h"

short get_max_size_of_labels(std::vector<std::wstring> _labels);

std::pair<std::string, std::string> form_login(box::BorderStyle _style = box::BorderStyle::SINGLE);
void form_info(std::wstring title, std::vector<std::wstring> _labels, box::BorderStyle _style = box::BorderStyle::SINGLE, short fill_size = 30);
char chooseAdminOrEmployee();
void loginAdmin(std::string & strUsername, std::string & strPassword);
void loginEmployees(std::string & strUsername, std::string & strPassword, int iMaxLogin);

void show_a_part_border(std::vector<short> number_of_fill, Position _position, box::BorderStyle _style = box::BorderStyle::SINGLE);
void show_info_account(
	std::vector<std::pair<short, std::wstring>> maxSizeAndWStringPairs,
	Color text_color,
	wchar_t fill_type = L' ',
	box::BorderStyle _style = box::BorderStyle::SINGLE);
void show_info_accounts();

char menu_options(std::wstring _title, std::vector<std::wstring> _options, box::BorderStyle _style = box::BorderStyle::SINGLE);
char menuUpdateInfo();

#endif // end UIHAVENOUX_HPP