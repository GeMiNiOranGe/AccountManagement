#pragma once
#ifndef TABLE_HPP
#define TABLE_HPP

#include <iostream>
#include <string>

namespace box {
enum class Alignment { LEFT, CENTER, RIGHT };

// Structure for storing UTF-8 alignment parameters
struct utf8_setw_t {
    size_t width;
    std::string fill;
    std::string content;
    Alignment align;
};

// Manipulator outputs correct width UTF-8
std::ostream & operator<<(std::ostream & os, const utf8_setw_t & f);

// Calculate the actual number of displayed characters (characters, not bytes)
size_t utf8_length(const std::string & s);

// Helper to create manipulator
inline utf8_setw_t utf8_setw(
    size_t width,
    std::string fill = " ",
    std::string content = "",
    Alignment align = Alignment::LEFT
) {
    return {width, fill, content, align};
}

enum class BorderPart { TOP, MIDDLE, BOTTOM };

/*
void draw_line(
    BorderPart where,
    std::vector<int> widths,
    BorderStyle style = BorderStyle::SINGLE
);
*/
};  // namespace box

#endif  // end TABLE_HPP
