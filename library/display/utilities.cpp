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

std::string input_password() {
    std::string password;
    char key;

    do {
        key = _getch();

        // BACKSPACE key
        if (key == 8 && !password.empty()) {
            std::cout << "\b \b";
            password.pop_back();
        }

        // Erase a line with "CTRL + BACKSPACE"
        if (key == 127) {
            for (int i = 0; i < password.size(); i++) {
                std::cout << "\b \b";
            }
            password.clear();
        }

        // Printable characters
        if (isprint(key)) {
            password.push_back(key);
            std::cout << key;
            Sleep(100);
            std::cout << "\b \b*";
        }

        // Not the ENTER key
    } while (key != 13);

    return password;
}

InputResult input_text(bool hide_input, size_t max_length) {
    std::string text;
    char key;

    do {
        key = _getch();

        // BACKSPACE
        if (key == 8 && !text.empty()) {
            std::cout << "\b \b";
            text.pop_back();
            continue;
        }

        // ESC: hủy nhập
        if (key == 27) {
            std::cout << "\n[Cancelled]\n";
            return {true, ""};
        }

        // Printable characters
        if (isprint(key) && text.size() < max_length) {
            text.push_back(key);
            std::cout << (hide_input ? '*' : key);
        }
    } while (key != 13);

    return {false, text};
}

void go_to_xy(short x, short y) {
    COORD pos = {x, y};
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
