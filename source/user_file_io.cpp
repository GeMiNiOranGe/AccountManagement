#include "user_file_io.hpp"

void UserFileIO::read_file(std::ifstream &fin, User &value) {
    std::string username, full_name, address, phone_number, email_address;

    getline(fin, username, CHAR_SEPARATED_VALUES);
    getline(fin, full_name, CHAR_SEPARATED_VALUES);
    getline(fin, address, CHAR_SEPARATED_VALUES);
    getline(fin, phone_number, CHAR_SEPARATED_VALUES);
    getline(fin, email_address);

    value.set_username(username);
    value.set_full_name(full_name);
    value.set_address(address);
    value.set_phone_number(phone_number);
    value.set_email_address(email_address);
}

void UserFileIO::write_file(std::ofstream &fout, const User &value) {
    fout << value.get_username() << CHAR_SEPARATED_VALUES;
    fout << value.get_full_name() << CHAR_SEPARATED_VALUES;
    fout << value.get_address() << CHAR_SEPARATED_VALUES;
    fout << value.get_phone_number() << CHAR_SEPARATED_VALUES;
    fout << value.get_email_address() << std::endl;
}
