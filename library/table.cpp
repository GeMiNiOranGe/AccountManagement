#include "table.hpp"

namespace box {
size_t utf8_length(const std::string & s) {
    size_t count = 0;
    for (unsigned char c : s) {
        // not byte continuation
        if ((c & 0b11000000) != 0b10000000) {
            ++count;
        }
    }
    return count;
}

/*
void draw_line(BorderPart where, std::vector<int> widths, BorderStyle style) {
    box::Border2 border(style);

    auto draw_horizontal = [&](std::vector<int> widths,
                               std::string middle,
                               std::string last) -> void {
        int size = widths.size();
        for (int i = 0; i < size - 1; i++) {
            std::cout << box::utf8_setw(widths[i], border.horizontal());
            std::cout << middle;
        }
        std::cout << box::utf8_setw(widths[size - 1], border.horizontal());
        std::cout << last << std::endl;
    };

    if (where == BorderPart::TOP) {
        std::cout << border.top_left();
        draw_horizontal(widths, border.top(), border.top_right());
        return;
    }
    if (where == BorderPart::MIDDLE) {
        std::cout << border.left();
        draw_horizontal(widths, border.center(), border.right());
        return;
    }
    if (where == BorderPart::BOTTOM) {
        std::cout << border.bottom_left();
        draw_horizontal(widths, border.bottom(), border.bottom_right());
        return;
    }
};
*/

std::ostream & operator<<(std::ostream & os, const utf8_setw_t & f) {
    size_t content_len = utf8_length(f.content);
    size_t total_width = f.width;

    if (content_len >= total_width) {
        os << f.content;
        return os;
    }

    size_t pad_total = total_width - content_len;
    size_t pad_left = 0;
    size_t pad_right = 0;

    switch (f.align) {
        case Alignment::LEFT: {
            pad_right = pad_total;
            break;
        }
        case Alignment::RIGHT: {
            pad_left = pad_total;
            break;
        }
        // center
        default: {
            pad_left = pad_total / 2;
            pad_right = pad_total - pad_left;
            break;
        }
    }

    for (size_t i = 0; i < pad_left; ++i) {
        os << f.fill;
    }

    os << f.content;

    for (size_t i = 0; i < pad_right; ++i) {
        os << f.fill;
    }

    return os;
}
}  // namespace box
