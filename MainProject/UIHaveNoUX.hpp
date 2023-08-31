#pragma once
#ifndef UIHAVENOUX_HPP
#define UIHAVENOUX_HPP

#include <iomanip>
#include <io.h>
#include <fcntl.h>
#include <vector>
#include "BoxBorder.hpp"
#include "HandleMain.hpp"
#include "Convert.hpp"
#include "Position.hpp"

short get_max_size_of_labels(std::vector<std::wstring> _labels);

std::pair<std::string, std::string> form_login(box::BorderStyle _style = box::BorderStyle::SINGLE);
void form_info(std::wstring title, std::vector<std::wstring> _labels, box::BorderStyle _style = box::BorderStyle::SINGLE, short fill_size = 30);

void show_a_part_border(std::vector<short> number_of_fill, Position _position, box::BorderStyle _style = box::BorderStyle::SINGLE);
void show_info_account(
	std::vector<std::pair<short, std::wstring>> _max_size_and_wstring_pairs,
	Color _text_color,
	wchar_t _fill_type = L' ',
	box::BorderStyle _style = box::BorderStyle::SINGLE);
void show_info_accounts();

char menu_options(
	std::wstring _title,
	std::vector<std::wstring> _options,
	std::vector<std::wstring> _sub_options = std::vector<std::wstring>(),
	box::BorderStyle _style = box::BorderStyle::SINGLE);

#endif // end UIHAVENOUX_HPP