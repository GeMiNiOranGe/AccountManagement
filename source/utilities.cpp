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
