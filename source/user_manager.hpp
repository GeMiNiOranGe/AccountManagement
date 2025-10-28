#pragma once
#ifndef USER_MANAGER_HPP
#define USER_MANAGER_HPP

#include <functional>

#include "user_file_manager.hpp"
#include "config.hpp"
#include "utilities.hpp"

class UserManager {
private:
    static void process_users_file(
        const std::function<void(User &, std::ofstream &)> &processor
    );

public:
    static void for_each_user(
        const std::function<bool(const User &)> &callback
    );

    static void create_user(const User &user);
    static void delete_user(const std::string &username);
    static void update_user(const std::string &username, std::string info_updated, char option);
    static User read_user(const std::string &username);
};

#endif // end USER_MANAGER_HPP