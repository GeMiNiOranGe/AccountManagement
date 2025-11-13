#include "account_service.hpp"

void AccountService::create_default_account(const std::string & username) {
    Account account(username, DEFAULT_PASSWORD, AccountRole::EMPLOYEE);
    AccountStorage::create_account(account);
}

void AccountService::update_password(
    const std::string & username,
    const std::string & password
) {
    Account current = AccountStorage::get_account(username);

    if (current.get_password() != password) {
        current.set_password(password);
        AccountStorage::update_account(username, current);
    }
}
