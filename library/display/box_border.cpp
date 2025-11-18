#include "display/box_border.hpp"

namespace box {
Border::Border(BorderStyle style) : style_(style) {}

std::string Border::horizontal() const {
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

std::string Border::vertical() const {
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

std::string Border::top_left() const {
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

std::string Border::top() const {
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

std::string Border::top_right() const {
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

std::string Border::left() const {
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

std::string Border::center() const {
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

std::string Border::right() const {
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

std::string Border::bottom_left() const {
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

std::string Border::bottom() const {
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

std::string Border::bottom_right() const {
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
