#include "user_storage.hpp"

std::unordered_map<std::string, User> UserStorage::get_users_map() {
    std::unordered_map<std::string, User> users_map;

    for_each_item([&](const User & item) {
        users_map[item.get_username()] = item;
        return false;
    });

    return users_map;
}

void UserStorage::create_user(const User & user) {
    std::ofstream fout(USERS_FILE, std::ios_base::app);
    UserFileIO::write_file(fout, user);
}

void UserStorage::delete_user(const std::string & username) {
    process_file([&username](User & user, std::ofstream & fout) {
        if (user.get_username() != username) {
            UserFileIO::write_file(fout, user);
        }
    });
}

// TODO: update from new_user to old_user
void UserStorage::update_user(
    const std::string & username,
    std::string info_updated,
    char option
) {
    process_file([&](User & user, std::ofstream & fout) {
        if (user.get_username() == username) {
            // Change the data and overwrite the information from the userTemp
            if (option == 49) {
                user.set_full_name(info_updated);
            }
            if (option == 50) {
                user.set_address(info_updated);
            }
            if (option == 51) {
                user.set_phone_number(info_updated);
            }
            if (option == 52) {
                user.set_email_address(info_updated);
            }
        }
        UserFileIO::write_file(fout, user);
    });
}

User UserStorage::read_user(const std::string & username) {
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
