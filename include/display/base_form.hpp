#pragma once
#ifndef BASE_FORM_HPP
#define BASE_FORM_HPP

#include <iostream>
#include <vector>

#include "display/box_border.hpp"
#include "display/console_color.hpp"
#include "display/sysutils.hpp"
#include "display/utilities.hpp"

class BaseForm {
protected:
    static const int width_;
    static const box::Border border_;

    static void setup_window_layout();
    static void draw_header(std::string header);
    static void pause_screen();

    static void write_fields(
        std::string header,
        std::vector<std::pair<std::string, std::string>> fields
    );
    static std::vector<std::string>
    read_fields(std::string header, std::vector<std::string> fields);
};

#endif  // end BASE_FORM_HPP
