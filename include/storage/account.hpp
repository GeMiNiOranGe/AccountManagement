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
        std::string username = "",
        std::string password = "",
        AccountRole role = AccountRole::NONE
    );
    ~Account();

    const AccountRole & get_role() const;
    const std::string & get_username() const;
    const std::string & get_password() const;

    void set_role(const AccountRole & value);
    void set_username(const std::string & value);
    void set_password(const std::string & value);
};

inline Account::Account(
    std::string username,
    std::string password,
    AccountRole role
) {
    this->username_ = username;
    this->password_ = password;
    this->role_ = role;
}

inline Account::~Account() {}

inline const AccountRole & Account::get_role() const {
    return this->role_;
}

inline const std::string & Account::get_username() const {
    return this->username_;
}

inline const std::string & Account::get_password() const {
    return this->password_;
}

inline void Account::set_role(const AccountRole & value) {
    this->role_ = value;
}

inline void Account::set_username(const std::string & value) {
    this->username_ = value;
}

inline void Account::set_password(const std::string & value) {
    this->password_ = value;
}

#endif  // end ACCOUNT_HPP
