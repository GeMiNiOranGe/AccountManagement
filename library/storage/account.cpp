#include "storage/account.hpp"

Account::Account(std::string username, std::string password, AccountRole role) {
    this->username_ = username;
    this->password_ = password;
    this->role_ = role;
}

const AccountRole & Account::get_role() const {
    return this->role_;
}

const std::string & Account::get_username() const {
    return this->username_;
}

const std::string & Account::get_password() const {
    return this->password_;
}

void Account::set_role(const AccountRole & value) {
    this->role_ = value;
}

void Account::set_username(const std::string & value) {
    this->username_ = value;
}

void Account::set_password(const std::string & value) {
    this->password_ = value;
}
