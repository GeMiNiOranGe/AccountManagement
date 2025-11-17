#include "display/console_color.hpp"

void set_color(Color foreground, Color background) {
    short fore_color = static_cast<short>(foreground);
    short back_color = static_cast<short>(background);
    short color_code = fore_color + back_color * 16;

    HANDLE std_output_handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(std_output_handle, color_code);
}
