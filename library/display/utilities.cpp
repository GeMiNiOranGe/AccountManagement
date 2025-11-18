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
    system("pause");
}

void success(std::string message) {
    std::cout << bgreen << message << reset_color << std::endl;
    system("pause");
}
