#include "account_file_io.hpp"

void AccountFileIO::read_file(std::ifstream &fin, Account &account) {
    std::string account_type, username, password;
    getline(fin, account_type, CHAR_SEPARATED_VALUES);
    getline(fin, username, CHAR_SEPARATED_VALUES);
    getline(fin, password);

    AccountType type = [](const std::string &_account_type) -> AccountType {
        if (_account_type == "AD")
            return AccountType::ADMINISTRATOR;
        if (_account_type == "EM")
            return AccountType::EMPLOYEE;
        return AccountType::NONE;
    }(account_type);

    account.set_account_type(type);
    account.set_username(username);
    account.set_password(password);
}

void AccountFileIO::write_file(std::ofstream &fout, const Account &account) {
    std::string type = [](const AccountType &_type) -> std::string {
        switch (_type) {
        case AccountType::ADMINISTRATOR:
            return "AD";
        case AccountType::EMPLOYEE:
            return "EM";
        default:
            return std::string();
        }
    }(account.get_account_type());

    fout << type << CHAR_SEPARATED_VALUES;
    fout << account.get_username() << CHAR_SEPARATED_VALUES;
    fout << account.get_password() << std::endl;
}
