#pragma once
#ifndef UI_HAVE_NO_UX_HPP
#define UI_HAVE_NO_UX_HPP

#include <iomanip>
#include <io.h>
#include <fcntl.h>
#include <vector>

#include "user_manager.hpp"
#include "account_manager.hpp"
#include "box_border.hpp"
#include "convert.hpp"
#include "position.hpp"
#include "console_io.hpp"

short get_max_size_of_labels(std::vector<std::wstring> _labels);

std::pair<std::string, std::string> show_login_form(box::BorderStyle _style = box::BorderStyle::SINGLE);
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

#endif // end UI_HAVE_NO_UX_HPP