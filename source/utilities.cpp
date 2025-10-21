#include "utilities.hpp"

bool is_open_file(std::ifstream &fin, const std::string &path) {
    fin.open(path);
    if (!fin.is_open()) {
        std::cerr << "[Error] Cannot open file: " << path << std::endl;
        return false;
    }
    return true;
}
