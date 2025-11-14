#pragma once
#ifndef BOX_BORDER_HPP
#define BOX_BORDER_HPP

#include <iostream>

namespace box {
enum class BorderStyle {
    SINGLE,
    DOUBLE,
    CORNER_SINGLE,
    CORNER_DOUBLE,
    VERTICAL_DOUBLE,
    HORIZONTAL_DOUBLE,
    DOUBLE_OUTER_SINGLE_INNER
};

class Border {
public:
    static wchar_t horizontal(BorderStyle _style);
    static wchar_t vertical(BorderStyle _style);

    static wchar_t top_left(BorderStyle _style);
    static wchar_t top(BorderStyle _style);
    static wchar_t top_right(BorderStyle _style);

    static wchar_t left(BorderStyle _style);
    static wchar_t center(BorderStyle _style);
    static wchar_t right(BorderStyle _style);

    static wchar_t bottom_left(BorderStyle _style);
    static wchar_t bottom(BorderStyle _style);
    static wchar_t bottom_right(BorderStyle _style);
    // ─│┌┐└┘├┤┬┴┼
    // ═║╔╗╚╝╠╣╦╩╬
    //   ╒╕╘╛╞╡╤╧╪
    //   ╓╖╙╜╟╢╥╨╫
    // ⩴⫬═≕≔≖
    // ͰΤ⫟⫞⊦⊢⊤⌜⌌⌍⌏⌎◜◞⌊⌈|⨽⨼⫠⫥⫭⫪⫬Τ—−––--−−——⌈‖Τ
};

class Border2 {
private:
    BorderStyle style_;

public:
    explicit Border2(BorderStyle style);

    std::string horizontal() const;
    std::string vertical() const;

    std::string top_left() const;
    std::string top() const;
    std::string top_right() const;

    std::string left() const;
    std::string center() const;
    std::string right() const;

    std::string bottom_left() const;
    std::string bottom() const;
    std::string bottom_right() const;
    // ─│┌┐└┘├┤┬┴┼
    // ═║╔╗╚╝╠╣╦╩╬
    //   ╒╕╘╛╞╡╤╧╪
    //   ╓╖╙╜╟╢╥╨╫
    // ⩴⫬═≕≔≖
    // ͰΤ⫟⫞⊦⊢⊤⌜⌌⌍⌏⌎◜◞⌊⌈|⨽⨼⫠⫥⫭⫪⫬Τ—−––--−−——⌈‖Τ
};
}  // namespace box

#endif  // end BOX_BORDER_HPP
