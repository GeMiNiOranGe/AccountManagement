#pragma once
#ifndef CONSOLE_COLOR_HPP
#define CONSOLE_COLOR_HPP

#include <windows.h>
#include <iostream>

#include "display/color.hpp"

void set_color(Color foreground, Color background = Color::BLACK);

// ---------------------------------------------
// Foreground only manipulators
// ---------------------------------------------
#define DEFINE_COLOR_MANIP(name, foreground)                                   \
    inline std::ostream & name(std::ostream & os) {                            \
        set_color(Color::foreground);                                          \
        return os;                                                             \
    }                                                                          \
    inline std::wostream & name(std::wostream & wos) {                         \
        set_color(Color::foreground);                                          \
        return wos;                                                            \
    }

// ---------------------------------------------
// Foreground + Background combinations
// ---------------------------------------------
#define DEFINE_COLOR_PAIR_MANIP(name, foreground, background)                  \
    inline std::ostream & name(std::ostream & os) {                            \
        set_color(Color::foreground, Color::background);                       \
        return os;                                                             \
    }                                                                          \
    inline std::wostream & name(std::wostream & wos) {                         \
        set_color(Color::foreground, Color::background);                       \
        return wos;                                                            \
    }

// Reset to default console color
inline std::ostream & reset_color(std::ostream & os) {
    set_color(Color::BRIGHT_WHITE, Color::BLACK);
    return os;
}

// Reset to default console color
inline std::wostream & reset_color(std::wostream & os) {
    set_color(Color::BRIGHT_WHITE, Color::BLACK);
    return os;
}

DEFINE_COLOR_MANIP(black, BLACK)
DEFINE_COLOR_MANIP(blue, BLUE)
DEFINE_COLOR_MANIP(green, GREEN)
DEFINE_COLOR_MANIP(aqua, AQUA)
DEFINE_COLOR_MANIP(red, RED)
DEFINE_COLOR_MANIP(purple, PURPLE)
DEFINE_COLOR_MANIP(yellow, YELLOW)
DEFINE_COLOR_MANIP(white, WHITE)
DEFINE_COLOR_MANIP(bblack, BRIGHT_BLACK)
DEFINE_COLOR_MANIP(bblue, BRIGHT_BLUE)
DEFINE_COLOR_MANIP(bgreen, BRIGHT_GREEN)
DEFINE_COLOR_MANIP(baqua, BRIGHT_AQUA)
DEFINE_COLOR_MANIP(bred, BRIGHT_RED)
DEFINE_COLOR_MANIP(bpurple, BRIGHT_PURPLE)
DEFINE_COLOR_MANIP(byellow, BRIGHT_YELLOW)
DEFINE_COLOR_MANIP(bwhite, BRIGHT_WHITE)

DEFINE_COLOR_PAIR_MANIP(black_on_black, BLACK, BLACK)
DEFINE_COLOR_PAIR_MANIP(blue_on_black, BLUE, BLACK)
DEFINE_COLOR_PAIR_MANIP(green_on_black, GREEN, BLACK)
DEFINE_COLOR_PAIR_MANIP(aqua_on_black, AQUA, BLACK)
DEFINE_COLOR_PAIR_MANIP(red_on_black, RED, BLACK)
DEFINE_COLOR_PAIR_MANIP(purple_on_black, PURPLE, BLACK)
DEFINE_COLOR_PAIR_MANIP(yellow_on_black, YELLOW, BLACK)
DEFINE_COLOR_PAIR_MANIP(white_on_black, WHITE, BLACK)
DEFINE_COLOR_PAIR_MANIP(bblack_on_black, BRIGHT_BLACK, BLACK)
DEFINE_COLOR_PAIR_MANIP(bblue_on_black, BRIGHT_BLUE, BLACK)
DEFINE_COLOR_PAIR_MANIP(bgreen_on_black, BRIGHT_GREEN, BLACK)
DEFINE_COLOR_PAIR_MANIP(baqua_on_black, BRIGHT_AQUA, BLACK)
DEFINE_COLOR_PAIR_MANIP(bred_on_black, BRIGHT_RED, BLACK)
DEFINE_COLOR_PAIR_MANIP(bpurple_on_black, BRIGHT_PURPLE, BLACK)
DEFINE_COLOR_PAIR_MANIP(byellow_on_black, BRIGHT_YELLOW, BLACK)
DEFINE_COLOR_PAIR_MANIP(bwhite_on_black, BRIGHT_WHITE, BLACK)

DEFINE_COLOR_PAIR_MANIP(black_on_red, BLACK, RED)
DEFINE_COLOR_PAIR_MANIP(blue_on_red, BLUE, RED)
DEFINE_COLOR_PAIR_MANIP(green_on_red, GREEN, RED)
DEFINE_COLOR_PAIR_MANIP(aqua_on_red, AQUA, RED)
DEFINE_COLOR_PAIR_MANIP(red_on_red, RED, RED)
DEFINE_COLOR_PAIR_MANIP(purple_on_red, PURPLE, RED)
DEFINE_COLOR_PAIR_MANIP(yellow_on_red, YELLOW, RED)
DEFINE_COLOR_PAIR_MANIP(white_on_red, WHITE, RED)
DEFINE_COLOR_PAIR_MANIP(bblack_on_red, BRIGHT_BLACK, RED)
DEFINE_COLOR_PAIR_MANIP(bblue_on_red, BRIGHT_BLUE, RED)
DEFINE_COLOR_PAIR_MANIP(bgreen_on_red, BRIGHT_GREEN, RED)
DEFINE_COLOR_PAIR_MANIP(baqua_on_red, BRIGHT_AQUA, RED)
DEFINE_COLOR_PAIR_MANIP(bred_on_red, BRIGHT_RED, RED)
DEFINE_COLOR_PAIR_MANIP(bpurple_on_red, BRIGHT_PURPLE, RED)
DEFINE_COLOR_PAIR_MANIP(byellow_on_red, BRIGHT_YELLOW, RED)
DEFINE_COLOR_PAIR_MANIP(bwhite_on_red, BRIGHT_WHITE, RED)

DEFINE_COLOR_PAIR_MANIP(black_on_white, BLACK, WHITE)
DEFINE_COLOR_PAIR_MANIP(blue_on_white, BLUE, WHITE)
DEFINE_COLOR_PAIR_MANIP(green_on_white, GREEN, WHITE)
DEFINE_COLOR_PAIR_MANIP(aqua_on_white, AQUA, WHITE)
DEFINE_COLOR_PAIR_MANIP(red_on_white, RED, WHITE)
DEFINE_COLOR_PAIR_MANIP(purple_on_white, PURPLE, WHITE)
DEFINE_COLOR_PAIR_MANIP(yellow_on_white, YELLOW, WHITE)
DEFINE_COLOR_PAIR_MANIP(white_on_white, WHITE, WHITE)
DEFINE_COLOR_PAIR_MANIP(bblack_on_white, BRIGHT_BLACK, WHITE)
DEFINE_COLOR_PAIR_MANIP(bblue_on_white, BRIGHT_BLUE, WHITE)
DEFINE_COLOR_PAIR_MANIP(bgreen_on_white, BRIGHT_GREEN, WHITE)
DEFINE_COLOR_PAIR_MANIP(baqua_on_white, BRIGHT_AQUA, WHITE)
DEFINE_COLOR_PAIR_MANIP(bred_on_white, BRIGHT_RED, WHITE)
DEFINE_COLOR_PAIR_MANIP(bpurple_on_white, BRIGHT_PURPLE, WHITE)
DEFINE_COLOR_PAIR_MANIP(byellow_on_white, BRIGHT_YELLOW, WHITE)
DEFINE_COLOR_PAIR_MANIP(bwhite_on_white, BRIGHT_WHITE, WHITE)

#endif  // end CONSOLE_COLOR_HPP
