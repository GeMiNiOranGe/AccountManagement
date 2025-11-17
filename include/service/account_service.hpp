#pragma once
#ifndef ACCOUNT_SERVICE_HPP
#define ACCOUNT_SERVICE_HPP

#include "storage/account.hpp"
#include "storage/account_storage.hpp"

class AccountService {
public:
    static std::pair<bool, AccountRole>
    try_login(const std::string & username, const std::string & password);

    static void create_default_account(const std::string & username);
    static void
    update_password(const std::string & username, const std::string & password);
};

#endif  // end ACCOUNT_SERVICE_HPP
