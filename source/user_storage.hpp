#pragma once
#ifndef USER_STORAGE_HPP
#define USER_STORAGE_HPP

#include <unordered_map>

#include "base_storage.hpp"
#include "config.hpp"
#include "user_file_io.hpp"

class UserStorage : public BaseStorage<User, UserFileIO, USERS_FILE> {
public:
    static std::unordered_map<std::string, User> get_users_map();

    static void create_user(const User & user);
    static void delete_user(const std::string & username);
    static void update_user(
        const std::string & username,
        std::string info_updated,
        char option
    );
    static User read_user(const std::string & username);
};

#endif  // end USER_STORAGE_HPP
