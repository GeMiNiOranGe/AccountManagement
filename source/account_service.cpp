#include "account_service.hpp"

bool AccountService::create_account(const std::string &username) {
    Account account(AccountRole::EMPLOYEE, username, DEFAULT_PASSWORD);
    AccountStorage::create_account(account);
    return true;
}
