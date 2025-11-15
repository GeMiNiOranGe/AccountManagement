#include "account_service.hpp"

std::pair<bool, AccountRole> AccountService::try_login(
    const std::string & username,
    const std::string & password
) {
    Account account = AccountStorage::get_account(username);

    // TODO: upgrade to C++17 and use `std::optional<Account>` to be like C#'s
    // nullable type, so that this check can be removed
    if (account.get_username().empty() || username.empty()) {
        return std::make_pair(false, AccountRole::NONE);
    }

    return std::make_pair(
        account.get_password() == password, account.get_role()
    );
}

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
