#include "display/box_border.hpp"

namespace box {
Border2::Border2(BorderStyle style) : style_(style) {}

std::string Border2::horizontal() const {
    switch (this->style_) {
        case BorderStyle::SINGLE:
        case BorderStyle::CORNER_DOUBLE:
        case BorderStyle::VERTICAL_DOUBLE: {
            return u8"─";
        }
        case BorderStyle::DOUBLE:
        case BorderStyle::CORNER_SINGLE:
        case BorderStyle::HORIZONTAL_DOUBLE: {
            return u8"═";
        }
        default: {
            return u8"\0";
        }
    }
}

std::string Border2::vertical() const {
    switch (this->style_) {
        case BorderStyle::SINGLE:
        case BorderStyle::CORNER_DOUBLE:
        case BorderStyle::HORIZONTAL_DOUBLE: {
            return u8"│";
        }
        case BorderStyle::DOUBLE:
        case BorderStyle::CORNER_SINGLE:
        case BorderStyle::VERTICAL_DOUBLE: {
            return u8"║";
        }
        default: {
            return u8"\0";
        }
    }
}

std::string Border2::top_left() const {
    switch (this->style_) {
        case BorderStyle::SINGLE:
        case BorderStyle::CORNER_SINGLE: {
            return u8"┌";
        }
        case BorderStyle::DOUBLE:
        case BorderStyle::CORNER_DOUBLE: {
            return u8"╔";
        }
        case BorderStyle::VERTICAL_DOUBLE: {
            return u8"╓";
        }
        case BorderStyle::HORIZONTAL_DOUBLE: {
            return u8"╒";
        }
        default: {
            return u8"\0";
        }
    }
}

std::string Border2::top() const {
    switch (this->style_) {
        case BorderStyle::SINGLE:
        case BorderStyle::CORNER_SINGLE: {
            return u8"┬";
        }
        case BorderStyle::DOUBLE:
        case BorderStyle::CORNER_DOUBLE: {
            return u8"╦";
        }
        case BorderStyle::VERTICAL_DOUBLE: {
            return u8"╥";
        }
        case BorderStyle::HORIZONTAL_DOUBLE: {
            return u8"╤";
        }
        default: {
            return u8"\0";
        }
    }
}

std::string Border2::top_right() const {
    switch (this->style_) {
        case BorderStyle::SINGLE:
        case BorderStyle::CORNER_SINGLE: {
            return u8"┐";
        }
        case BorderStyle::DOUBLE:
        case BorderStyle::CORNER_DOUBLE: {
            return u8"╗";
        }
        case BorderStyle::VERTICAL_DOUBLE: {
            return u8"╖";
        }
        case BorderStyle::HORIZONTAL_DOUBLE: {
            return u8"╕";
        }
        default: {
            return u8"\0";
        }
    }
}

std::string Border2::left() const {
    switch (this->style_) {
        case BorderStyle::SINGLE:
        case BorderStyle::CORNER_SINGLE: {
            return u8"├";
        }
        case BorderStyle::DOUBLE:
        case BorderStyle::CORNER_DOUBLE: {
            return u8"╠";
        }
        case BorderStyle::VERTICAL_DOUBLE: {
            return u8"╟";
        }
        case BorderStyle::HORIZONTAL_DOUBLE: {
            return u8"╞";
        }
        default: {
            return u8"\0";
        }
    }
}

std::string Border2::center() const {
    switch (this->style_) {
        case BorderStyle::SINGLE:
        case BorderStyle::CORNER_SINGLE: {
            return u8"┼";
        }
        case BorderStyle::DOUBLE:
        case BorderStyle::CORNER_DOUBLE: {
            return u8"╬";
        }
        case BorderStyle::VERTICAL_DOUBLE: {
            return u8"╫";
        }
        case BorderStyle::HORIZONTAL_DOUBLE: {
            return u8"╪";
        }
        default: {
            return u8"\0";
        }
    }
}

std::string Border2::right() const {
    switch (this->style_) {
        case BorderStyle::SINGLE:
        case BorderStyle::CORNER_SINGLE: {
            return u8"┤";
        }
        case BorderStyle::DOUBLE:
        case BorderStyle::CORNER_DOUBLE: {
            return u8"╣";
        }
        case BorderStyle::VERTICAL_DOUBLE: {
            return u8"╢";
        }
        case BorderStyle::HORIZONTAL_DOUBLE: {
            return u8"╡";
        }
        default: {
            return u8"\0";
        }
    }
}

std::string Border2::bottom_left() const {
    switch (this->style_) {
        case BorderStyle::SINGLE:
        case BorderStyle::CORNER_SINGLE: {
            return u8"└";
        }
        case BorderStyle::DOUBLE:
        case BorderStyle::CORNER_DOUBLE: {
            return u8"╚";
        }
        case BorderStyle::VERTICAL_DOUBLE: {
            return u8"╙";
        }
        case BorderStyle::HORIZONTAL_DOUBLE: {
            return u8"╘";
        }
        default: {
            return u8"\0";
        }
    }
}

std::string Border2::bottom() const {
    switch (this->style_) {
        case BorderStyle::SINGLE:
        case BorderStyle::CORNER_SINGLE: {
            return u8"┴";
        }
        case BorderStyle::DOUBLE:
        case BorderStyle::CORNER_DOUBLE: {
            return u8"╩";
        }
        case BorderStyle::VERTICAL_DOUBLE: {
            return u8"╨";
        }
        case BorderStyle::HORIZONTAL_DOUBLE: {
            return u8"╧";
        }
        default: {
            return u8"\0";
        }
    }
}

std::string Border2::bottom_right() const {
    switch (this->style_) {
        case BorderStyle::SINGLE:
        case BorderStyle::CORNER_SINGLE: {
            return u8"┘";
        }
        case BorderStyle::DOUBLE:
        case BorderStyle::CORNER_DOUBLE: {
            return u8"╝";
        }
        case BorderStyle::VERTICAL_DOUBLE: {
            return u8"╜";
        }
        case BorderStyle::HORIZONTAL_DOUBLE: {
            return u8"╛";
        }
        default: {
            return u8"\0";
        }
    }
}
}  // namespace box
