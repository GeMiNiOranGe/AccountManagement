#include "storage/user_storage.hpp"

std::unordered_map<std::string, User> UserStorage::get_users_map() {
    std::unordered_map<std::string, User> users_map;

    for_each_item([&](const User & item) {
        users_map[item.get_username()] = item;
        return false;
    });

    return users_map;
}

User UserStorage::get_user(const std::string & username) {
    User result;

    for_each_item([&](const User & item) {
        if (item.get_username() == username) {
            result = item;
            return true;
        }
        return false;
    });

    return result;
}

void UserStorage::create_user(const User & user) {
    std::ofstream fout(USERS_FILE, std::ios_base::app);
    UserFileIO::write_file(fout, user);
}

void UserStorage::update_user(const std::string & username, const User & user) {
    process_file([&](User & item, std::ofstream & fout) {
        if (item.get_username() == username) {
            item = user;
        }
        UserFileIO::write_file(fout, item);
    });
}

void UserStorage::delete_user(const std::string & username) {
    process_file([&](User & item, std::ofstream & fout) {
        if (item.get_username() != username) {
            UserFileIO::write_file(fout, item);
        }
    });
}
