#include "account_service.hpp"

void AccountService::create_default_account(const std::string & username) {
    Account account(username, DEFAULT_PASSWORD, AccountRole::EMPLOYEE);
    AccountStorage::create_account(account);
}
