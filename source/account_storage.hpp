#pragma once
#ifndef ACCOUNT_STORAGE_HPP
#define ACCOUNT_STORAGE_HPP

#include "account_file_io.hpp"
#include "base_storage.hpp"
#include "config.hpp"

class AccountStorage
    : public BaseStorage<Account, AccountFileIO, ACCOUNTS_FILE> {
public:
    static bool has_username(const std::string & username);

    static Account get_account(const std::string & username);

    static void create_account(const Account & account);
    static void delete_account(const std::string & username);
    static void
    update_account(const Account & old_account, const Account & new_account);
    static void
    update_account(const std::string & username, const Account & account);
};

#endif  // end ACCOUNT_STORAGE_HPP
