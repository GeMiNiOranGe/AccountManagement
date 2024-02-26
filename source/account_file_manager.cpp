#include "account_file_manager.hpp"

void AccountFileManager::read_file(std::ifstream &_fin, Account &_account) {
    std::string account_type, username, password;
    getline(_fin, account_type, ',');
    getline(_fin, username, ',');
    getline(_fin, password);

    AccountType type = [](const std::string &_account_type) -> AccountType {
        if (_account_type == "AD")
            return AccountType::ADMINISTRATOR;
        if (_account_type == "EM")
            return AccountType::EMPLOYEE;
        return AccountType::NONE;
    }(account_type);

    _account.set_account_type(type);
    _account.set_username(username);
    _account.set_password(password);
}
void AccountFileManager::write_file(const Account &_account, std::ofstream &_fout) {
    std::string type = [](const AccountType &_type) -> std::string {
        switch (_type) {
        case AccountType::ADMINISTRATOR:
            return "AD";
        case AccountType::EMPLOYEE:
            return "EM";
        default:
            return std::string();
        }
    }(_account.get_account_type());

    _fout << type << ',' << _account.get_username() << ',' << _account.get_password() << std::endl;
}
