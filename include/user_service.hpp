#pragma once
#ifndef USER_SERVICE_HPP
#define USER_SERVICE_HPP

#include "account_service.hpp"
#include "user.hpp"
#include "user_storage.hpp"

class UserService {
public:
    static User get_user(const std::string & username);
    static void create_user(const User & user);
    static void update_user(
        const std::string & username,
        const char & option,
        const std::string & new_value
    );
    static void delete_user(const std::string & username);
};

#endif  // end USER_SERVICE_HPP
