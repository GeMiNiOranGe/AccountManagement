#include "storage/account_file_io.hpp"

AccountRole AccountFileIO::parse_role_text(const std::string & value) {
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

bool AccountFileIO::read_file(std::ifstream & fin, Account & value) {
    std::string line;

    if (!getline(fin, line) || line.empty()) {
        return false;
    }

    std::stringstream ss(line);
    std::string username, password, role_text;

    getline(ss, username, CHAR_SEPARATED_VALUES);
    getline(ss, password, CHAR_SEPARATED_VALUES);
    getline(ss, role_text);

    value.set_username(username);
    value.set_password(password);
    value.set_role(parse_role_text(role_text));

    return true;
}

void AccountFileIO::write_file(std::ofstream & fout, const Account & value) {
    fout << value.get_username() << CHAR_SEPARATED_VALUES;
    fout << value.get_password() << CHAR_SEPARATED_VALUES;
    fout << to_role_text(value.get_role()) << std::endl;
}
