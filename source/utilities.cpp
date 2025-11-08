#include "utilities.hpp"

bool is_open_file(std::ifstream &fin, const std::string &path) {
    fin.open(path);
    if (!fin.is_open()) {
        std::cerr << "[Error] Cannot open file: " << path << std::endl;
        return false;
    }
    return true;
}

bool is_open_file(std::ofstream &fout, const std::string &path) {
    fout.open(path);
    if (!fout.is_open()) {
        std::cerr << "[Error] Cannot open file: " << path << std::endl;
        return false;
    }
    return true;
}

void encode_password(std::string &_password) {
    char event_key;
    do {
        event_key = _getch();
        // ESC key
        if (event_key == 27)
            exit(0);
        // BACKSPACE key
        if (event_key == 8 && !_password.empty()) {
            std::cout << "\b \b";
            _password.pop_back();
        }
        // Erase a line with "CTRL + BACKSPACE"
        if (event_key == 127) {
            for (int i = 0; i < _password.size(); i++)
                std::cout << "\b \b";
            _password.clear();
        }
        // Printable characters
        if (isprint(event_key)) {
            _password.push_back(event_key);
            std::cout << event_key;
            Sleep(100);
            std::cout << "\b \b*";
        }
        // Not the ENTER key
    } while (event_key != 13);
}

void go_to_xy(short x, short y) {
    COORD pos = {x, y};
    HANDLE handle_std_out = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(handle_std_out, pos);
}

void warning(std::string _message) {
    std::cout << white_on_red << "\a" << _message << std::endl
              << reset_color;
    system("pause");
}
