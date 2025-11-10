#pragma once
#ifndef UI_HAVE_NO_UX_HPP
#define UI_HAVE_NO_UX_HPP

#include <fcntl.h>
#include <io.h>
#include <iomanip>
#include <unordered_map>
#include <vector>

#include "account_storage.hpp"
#include "box_border.hpp"
#include "console_io.hpp"
#include "convert.hpp"
#include "position.hpp"
#include "user_storage.hpp"

short get_max_size_of_labels(std::vector<std::wstring> _labels);

std::pair<std::string, std::string> show_login_form(
    box::BorderStyle _style = box::BorderStyle::SINGLE
);
void form_info(
    std::wstring title,
    std::vector<std::wstring> _labels,
    box::BorderStyle _style = box::BorderStyle::SINGLE,
    short fill_size = 30
);

void show_a_part_border(
    std::vector<std::pair<std::string, short>> number_of_fill,
    Position _position,
    box::BorderStyle _style = box::BorderStyle::SINGLE
);
void show_info_account(
    std::vector<std::pair<std::wstring, short>> _max_size_and_wstring_pairs,
    Color _text_color,
    wchar_t _fill_type = L' ',
    box::BorderStyle _style = box::BorderStyle::SINGLE
);
void show_info_accounts();

char menu_options(
    std::wstring _title,
    std::vector<std::wstring> _options,
    std::vector<std::wstring> _sub_options = std::vector<std::wstring>(),
    box::BorderStyle _style = box::BorderStyle::SINGLE
);

#endif  // end UI_HAVE_NO_UX_HPP
