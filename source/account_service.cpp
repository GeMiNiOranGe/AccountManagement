#include "account_service.hpp"

bool AccountService::create_account(const std::string & username) {
    Account account(username, DEFAULT_PASSWORD, AccountRole::EMPLOYEE);
    AccountStorage::create_account(account);
    return true;
}
