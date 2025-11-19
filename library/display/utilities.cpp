#include "display/utilities.hpp"

bool is_open_file(std::ifstream & fin, const std::string & path) {
    fin.open(path);
    if (!fin.is_open()) {
        std::cerr << "[Error] Cannot open file: " << path << std::endl;
        return false;
    }
    return true;
}

bool is_open_file(std::ofstream & fout, const std::string & path) {
    fout.open(path);
    if (!fout.is_open()) {
        std::cerr << "[Error] Cannot open file: " << path << std::endl;
        return false;
    }
    return true;
}

InputResult input_text(bool hide_input, size_t max_length) {
    std::string text;
    char key;

    do {
        key = _getch();

        // BACKSPACE: Erasing a character
        if (key == 8 && !text.empty()) {
            std::cout << "\b \b";
            text.pop_back();
            continue;
        }

        // ESC: Escaping input
        if (key == 27) {
            return {true, ""};
        }

        // CTRL + BACKSPACE: Erasing entire the line
        if (key == 127) {
            for (int i = 0; i < text.size(); i++) {
                std::cout << "\b \b";
            }
            text.clear();
        }

        // Printable characters
        if (isprint(key) && text.size() < max_length) {
            text.push_back(key);
            std::cout << key;
            if (hide_input) {
                Sleep(100);
                std::cout << "\b \b*";
            }
        }
        // ENTER: Breaking the loop
    } while (key != 13);

    return {false, text};
}

void go_to_xy(SHORT x_coord, SHORT y_coord) {
    COORD pos = {x_coord, y_coord};
    HANDLE handle_std_out = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(handle_std_out, pos);
}

void warning(std::string message) {
    std::cout << white_on_red << "\a" << message << reset_color << std::endl;
}

void success(std::string message) {
    std::cout << bgreen << message << reset_color << std::endl;
}

void write_fields(
    std::string header,
    std::vector<std::pair<std::string, std::string>> fields,
    box::Border border
) {
    std::cout << byellow << "[+] " + header << reset_color << std::endl;

    size_t size = fields.size();
    for (size_t i = 0; i < size - 1; i++) {
        std::cout << "    " << border.left() << border.horizontal() << baqua
                  << fields[i].first << reset_color << fields[i].second
                  << std::endl;
    }
    std::cout << "    " << border.bottom_left() << border.horizontal() << baqua
              << fields[size - 1].first << reset_color
              << fields[size - 1].second << std::endl;
}

std::vector<std::string> read_fields(
    std::string header,
    std::vector<std::string> fields,
    box::Border border,
    size_t width
) {
    std::vector<std::string> values;

    std::cout << border.top_left()
              << box::utf8_setw(width - 2, border.horizontal())
              << border.top_right() << std::endl;
    std::cout << border.vertical() << byellow
              << box::utf8_setw(width - 2, " ", " > " + header) << reset_color
              << border.vertical() << std::endl;
    std::cout << border.left() << box::utf8_setw(width - 2, border.horizontal())
              << border.right() << std::endl;
    for (auto && field : fields) {
        std::cout << border.vertical() << baqua << field << reset_color;
        // Here, using `std::cin` can display the correct UI. Don't ask me why,
        // I don't know.
        InputResult input_result = input_text();
        values.push_back(input_result.value);
        std::cout << box::utf8_setw(
            width - 2 - field.size() - input_result.value.size(), " "
        );
        std::cout << border.vertical() << reset_color << std::endl;
    }
    std::cout << border.bottom_left()
              << box::utf8_setw(width - 2, border.horizontal())
              << border.bottom_right() << std::endl;

    return values;
}
