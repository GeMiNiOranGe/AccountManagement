#pragma once
#ifndef ACCOUNT_SERVICE_HPP
#define ACCOUNT_SERVICE_HPP

#include "account.hpp"
#include "account_storage.hpp"

class AccountService {
public:
    static bool create_account(const std::string &username);
};

#endif // end ACCOUNT_SERVICE_HPP