#pragma once
#ifndef UI_HAVE_NO_UX_HPP
#define UI_HAVE_NO_UX_HPP

#include <iomanip>
#include <unordered_map>
#include <vector>

#include "display/box_border.hpp"
#include "display/console_io.hpp"
#include "display/position.hpp"
#include "display/table.hpp"
#include "storage/account_storage.hpp"
#include "storage/user_storage.hpp"

size_t get_max_size_of_strings(std::vector<std::string> strings);

std::pair<std::string, std::string> show_login_form(
    box::BorderStyle style = box::BorderStyle::SINGLE
);

void form_info(
    std::string title,
    std::vector<std::string> labels,
    box::BorderStyle style = box::BorderStyle::SINGLE,
    size_t input_size = 30
);

void show_a_part_border_horizontal(
    box::Border2 border,
    std::vector<std::pair<std::string, size_t>> number_of_fill,
    std::string middle,
    std::string last
);

void show_a_part_border(
    std::vector<std::pair<std::string, size_t>> number_of_fill,
    Position position,
    box::BorderStyle style = box::BorderStyle::SINGLE
);

void show_info_account(
    std::vector<std::pair<std::string, size_t>> max_size_and_wstring_pairs,
    Color text_color,
    std::string fill_type = " ",
    box::BorderStyle style = box::BorderStyle::SINGLE
);

void show_info_accounts();

char menu_options(
    std::string title,
    std::vector<std::string> options,
    std::vector<std::string> sub_options = {},
    box::BorderStyle style = box::BorderStyle::SINGLE
);

#endif  // end UI_HAVE_NO_UX_HPP
