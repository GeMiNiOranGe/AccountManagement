#include "display/box_border.hpp"

wchar_t box::Border::horizontal(BorderStyle _style) {
    switch (_style) {
        case BorderStyle::SINGLE:
        case BorderStyle::CORNER_DOUBLE:
        case BorderStyle::VERTICAL_DOUBLE:
            return L'─';
        case BorderStyle::DOUBLE:
        case BorderStyle::CORNER_SINGLE:
        case BorderStyle::HORIZONTAL_DOUBLE:
            return L'═';
        default:
            return L'\0';
    }
}
wchar_t box::Border::vertical(BorderStyle _style) {
    switch (_style) {
        case BorderStyle::SINGLE:
        case BorderStyle::CORNER_DOUBLE:
        case BorderStyle::HORIZONTAL_DOUBLE:
            return L'│';
        case BorderStyle::DOUBLE:
        case BorderStyle::CORNER_SINGLE:
        case BorderStyle::VERTICAL_DOUBLE:
            return L'║';
        default:
            return L'\0';
    }
}

wchar_t box::Border::top_left(BorderStyle _style) {
    switch (_style) {
        case BorderStyle::SINGLE:
        case BorderStyle::CORNER_SINGLE:
            return L'┌';
        case BorderStyle::DOUBLE:
        case BorderStyle::CORNER_DOUBLE:
            return L'╔';
        case BorderStyle::VERTICAL_DOUBLE:
            return L'╓';
        case BorderStyle::HORIZONTAL_DOUBLE:
            return L'╒';
        default:
            return L'\0';
    }
}
wchar_t box::Border::top(BorderStyle _style) {
    switch (_style) {
        case BorderStyle::SINGLE:
        case BorderStyle::CORNER_SINGLE:
            return L'┬';
        case BorderStyle::DOUBLE:
        case BorderStyle::CORNER_DOUBLE:
            return L'╦';
        case BorderStyle::VERTICAL_DOUBLE:
            return L'╥';
        case BorderStyle::HORIZONTAL_DOUBLE:
            return L'╤';
        default:
            return L'\0';
    }
}
wchar_t box::Border::top_right(BorderStyle _style) {
    switch (_style) {
        case BorderStyle::SINGLE:
        case BorderStyle::CORNER_SINGLE:
            return L'┐';
        case BorderStyle::DOUBLE:
        case BorderStyle::CORNER_DOUBLE:
            return L'╗';
        case BorderStyle::VERTICAL_DOUBLE:
            return L'╖';
        case BorderStyle::HORIZONTAL_DOUBLE:
            return L'╕';
        default:
            return L'\0';
    }
}

wchar_t box::Border::left(BorderStyle _style) {
    switch (_style) {
        case BorderStyle::SINGLE:
        case BorderStyle::CORNER_SINGLE:
            return L'├';
        case BorderStyle::DOUBLE:
        case BorderStyle::CORNER_DOUBLE:
            return L'╠';
        case BorderStyle::VERTICAL_DOUBLE:
            return L'╟';
        case BorderStyle::HORIZONTAL_DOUBLE:
            return L'╞';
        default:
            return L'\0';
    }
}
wchar_t box::Border::center(BorderStyle _style) {
    switch (_style) {
        case BorderStyle::SINGLE:
        case BorderStyle::CORNER_SINGLE:
            return L'┼';
        case BorderStyle::DOUBLE:
        case BorderStyle::CORNER_DOUBLE:
            return L'╬';
        case BorderStyle::VERTICAL_DOUBLE:
            return L'╫';
        case BorderStyle::HORIZONTAL_DOUBLE:
            return L'╪';
        default:
            return L'\0';
    }
}
wchar_t box::Border::right(BorderStyle _style) {
    switch (_style) {
        case BorderStyle::SINGLE:
        case BorderStyle::CORNER_SINGLE:
            return L'┤';
        case BorderStyle::DOUBLE:
        case BorderStyle::CORNER_DOUBLE:
            return L'╣';
        case BorderStyle::VERTICAL_DOUBLE:
            return L'╢';
        case BorderStyle::HORIZONTAL_DOUBLE:
            return L'╡';
        default:
            return L'\0';
    }
}

wchar_t box::Border::bottom_left(BorderStyle _style) {
    switch (_style) {
        case BorderStyle::SINGLE:
        case BorderStyle::CORNER_SINGLE:
            return L'└';
        case BorderStyle::DOUBLE:
        case BorderStyle::CORNER_DOUBLE:
            return L'╚';
        case BorderStyle::VERTICAL_DOUBLE:
            return L'╙';
        case BorderStyle::HORIZONTAL_DOUBLE:
            return L'╘';
        default:
            return L'\0';
    }
}
wchar_t box::Border::bottom(BorderStyle _style) {
    switch (_style) {
        case BorderStyle::SINGLE:
        case BorderStyle::CORNER_SINGLE:
            return L'┴';
        case BorderStyle::DOUBLE:
        case BorderStyle::CORNER_DOUBLE:
            return L'╩';
        case BorderStyle::VERTICAL_DOUBLE:
            return L'╨';
        case BorderStyle::HORIZONTAL_DOUBLE:
            return L'╧';
        default:
            return L'\0';
    }
}
wchar_t box::Border::bottom_right(BorderStyle _style) {
    switch (_style) {
        case BorderStyle::SINGLE:
        case BorderStyle::CORNER_SINGLE:
            return L'┘';
        case BorderStyle::DOUBLE:
        case BorderStyle::CORNER_DOUBLE:
            return L'╝';
        case BorderStyle::VERTICAL_DOUBLE:
            return L'╜';
        case BorderStyle::HORIZONTAL_DOUBLE:
            return L'╛';
        default:
            return L'\0';
    }
}

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
