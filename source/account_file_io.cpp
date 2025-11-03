#include "account_file_io.hpp"

AccountType AccountFileIO::parse_role_text(const std::string &value) {
    if (value == "AD") {
        return AccountType::ADMINISTRATOR;
    }
    if (value == "EM") {
        return AccountType::EMPLOYEE;
    }
    return AccountType::NONE;
}

std::string AccountFileIO::to_role_text(AccountType value) {
    if (value == AccountType::ADMINISTRATOR) {
        return "AD";
    }
    if (value == AccountType::EMPLOYEE) {
        return "EM";
    }
    return "";
}

void AccountFileIO::read_file(std::ifstream &fin, Account &value) {
    std::string role_text, username, password;

    getline(fin, role_text, CHAR_SEPARATED_VALUES);
    getline(fin, username, CHAR_SEPARATED_VALUES);
    getline(fin, password);

    value.set_account_type(parse_role_text(role_text));
    value.set_username(username);
    value.set_password(password);
}

void AccountFileIO::write_file(std::ofstream &fout, const Account &value) {
    fout << to_role_text(value.get_account_type()) << CHAR_SEPARATED_VALUES;
    fout << value.get_username() << CHAR_SEPARATED_VALUES;
    fout << value.get_password() << std::endl;
}
