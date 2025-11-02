#include "user_storage.hpp"

void UserStorage::process_users_file(
    const std::function<void(User &, std::ofstream &)> &processor
) {
    const std::string original_file = USERS_FILE;
    std::string backup_file = USERS_FILE;
    backup_file.insert(backup_file.size() - 4, "_new");

    // Rename Users.txt into UsersTemp.txt
    if (rename(original_file.c_str(), backup_file.c_str()) != 0) {
        std::cerr << "Error renaming file" << std::endl;
        return;
    }

    std::ifstream fin;
    std::ofstream fout;

    // Re-create the old Users.txt file without content
    if (!is_open_file(fin, backup_file) || !is_open_file(fout, original_file)) {
        return;
    }

    // Write from the file is renamed (UsersNew.txt) to Users.txt,
    // and don't write the employee want to delete
    while (!fin.eof()) {
        User user;
        UserFileIO::read_file(fin, user);
        if (!user.get_username().empty()) {
            processor(user, fout);
        }
    }

    fin.close();
    fout.close();
    remove(backup_file.c_str());
}

void UserStorage::for_each_user(
    const std::function<bool(const User &)> &callback
) {
    std::ifstream fin;

    if (!is_open_file(fin, USERS_FILE.c_str())) {
        return;
    }

    while (!fin.eof()) {
        User user;
        UserFileIO::read_file(fin, user);
        if (callback(user)) {
            break;
        }
    }
}

void UserStorage::create_user(const User &user) {
    std::ofstream fout(USERS_FILE, std::ios_base::app);
    UserFileIO::write_file(fout, user);
}

void UserStorage::delete_user(const std::string &username) {
    process_users_file([&username](User &user, std::ofstream &fout) {
        if (user.get_username() != username) {
            UserFileIO::write_file(fout, user);
        }
    });
}

// TODO: update from new_user to old_user
void UserStorage::update_user(const std::string &username, std::string info_updated, char option) {
    process_users_file(
        [&username, &info_updated, &option](User &user, std::ofstream &fout) {
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
        }
    );
}

User UserStorage::read_user(const std::string &username) {
    User result;

    for_each_user(
        [&](const User &item) {
            if (item.get_username() == username) {
                result = item;
                return true;
            }
            return false;
        }
    );

    return result;
}
