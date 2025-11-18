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
    // ╭╮╰╯
};
}  // namespace box

#endif  // end BOX_BORDER_HPP
