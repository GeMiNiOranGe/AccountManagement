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
    Account(
        std::string username = "",
        std::string password = "",
        AccountRole role = AccountRole::NONE
    );

    const AccountRole & get_role() const;
    const std::string & get_username() const;
    const std::string & get_password() const;

    void set_role(const AccountRole & value);
    void set_username(const std::string & value);
    void set_password(const std::string & value);
};

#endif  // end ACCOUNT_HPP
