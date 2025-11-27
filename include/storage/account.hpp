#pragma once
#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <string>

#include "service/account_role.hpp"

class Account {
private:
    std::string password_;
    std::string username_;
    AccountRole role_;

public:
    explicit Account(
        const std::string & username = "",
        const std::string & password = "",
        AccountRole role = AccountRole::NONE
    );
    ~Account();

    const std::string & get_username() const;
    const std::string & get_password() const;
    AccountRole get_role() const;

    void set_username(const std::string & value);
    void set_password(const std::string & value);
    void set_role(AccountRole value);
};

inline Account::Account(
    const std::string & username,
    const std::string & password,
    AccountRole role
) {
    this->username_ = username;
    this->password_ = password;
    this->role_ = role;
}

inline Account::~Account() {}

inline const std::string & Account::get_username() const {
    return this->username_;
}

inline const std::string & Account::get_password() const {
    return this->password_;
}

inline AccountRole Account::get_role() const {
    return this->role_;
}

inline void Account::set_username(const std::string & value) {
    this->username_ = value;
}

inline void Account::set_password(const std::string & value) {
    this->password_ = value;
}

inline void Account::set_role(AccountRole value) {
    this->role_ = value;
}

#endif  // end ACCOUNT_HPP
