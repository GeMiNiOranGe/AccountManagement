#include "service/user_service.hpp"

User UserService::get_user(const std::string & username) {
    return UserStorage::get_user(username);
}

void UserService::create_user(const User & user) {
    UserStorage::create_user(user);
    AccountService::create_default_account(user.get_username());
}

void UserService::update_user(
    const std::string & username,
    const char & option,
    const std::string & new_value
) {
    User current = UserStorage::get_user(username);

    switch (option) {
        case 49:
            current.set_full_name(new_value);
            break;
        case 50:
            current.set_address(new_value);
            break;
        case 51:
            current.set_phone_number(new_value);
            break;
        case 52:
            current.set_email_address(new_value);
            break;
        default:
            return;
    }

    UserStorage::update_user(username, current);
}

void UserService::delete_user(const std::string & username) {
    AccountStorage::delete_account(username);
    UserStorage::delete_user(username);
}
