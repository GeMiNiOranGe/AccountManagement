#include "user_file_manager.hpp"

std::ifstream UserFileManager::open_file(const std::string &username) {
    const std::string PATH = USERS_DIRECTORY + username + ".txt";
    std::ifstream fin;
    fin.open(PATH);
    return fin;
}

void UserFileManager::read_file(std::ifstream &fin, User &user) {
    std::string username, full_name, address, phone_number, email_address;

    getline(fin, username, CHAR_SEPARATED_VALUES);
    getline(fin, full_name, CHAR_SEPARATED_VALUES);
    getline(fin, address, CHAR_SEPARATED_VALUES);
    getline(fin, phone_number, CHAR_SEPARATED_VALUES);
    getline(fin, email_address);

    user.set_username(username);
    user.set_full_name(full_name);
    user.set_address(address);
    user.set_phone_number(phone_number);
    user.set_email_address(email_address);
}

void UserFileManager::write_file(std::ofstream &fout, const User &user) {
    fout << user.get_username() << CHAR_SEPARATED_VALUES;
    fout << user.get_full_name() << CHAR_SEPARATED_VALUES;
    fout << user.get_address() << CHAR_SEPARATED_VALUES;
    fout << user.get_phone_number() << CHAR_SEPARATED_VALUES;
    fout << user.get_email_address() << std::endl;
}
