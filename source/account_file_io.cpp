#include "account_file_io.hpp"

AccountRole AccountFileIO::parse_role_text(const std::string &value) {
    if (value == "AD") {
        return AccountRole::ADMINISTRATOR;
    }
    if (value == "EM") {
        return AccountRole::EMPLOYEE;
    }
    return AccountRole::NONE;
}

std::string AccountFileIO::to_role_text(AccountRole value) {
    if (value == AccountRole::ADMINISTRATOR) {
        return "AD";
    }
    if (value == AccountRole::EMPLOYEE) {
        return "EM";
    }
    return "";
}

void AccountFileIO::read_file(std::ifstream &fin, Account &value) {
    std::string role_text, username, password;

    getline(fin, role_text, CHAR_SEPARATED_VALUES);
    getline(fin, username, CHAR_SEPARATED_VALUES);
    getline(fin, password);

    value.set_role(parse_role_text(role_text));
    value.set_username(username);
    value.set_password(password);
}

void AccountFileIO::write_file(std::ofstream &fout, const Account &value) {
    fout << to_role_text(value.get_role()) << CHAR_SEPARATED_VALUES;
    fout << value.get_username() << CHAR_SEPARATED_VALUES;
    fout << value.get_password() << std::endl;
}
