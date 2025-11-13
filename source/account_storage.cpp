#include "account_storage.hpp"

bool AccountStorage::has_username(const std::string & username) {
    bool found = false;

    for_each_item([&](const Account & item) {
        if (item.get_username() == username) {
            found = true;
            return true;
        }
        return false;
    });

    return found;
}

bool AccountStorage::has_account(const Account & account) {
    bool found = false;

    for_each_item([&](const Account & item) {
        if (item.get_username() == account.get_username()
            && item.get_password() == account.get_password()) {
            found = true;
            return true;
        }
        return false;
    });

    return found;
}

Account AccountStorage::get_account_details(
    const std::string & username,
    const std::string & password
) {
    Account result;

    for_each_item([&](const Account & item) {
        if (item.get_username() == username) {
            result = item;
            return true;
        }
        return false;
    });

    return result;
}

Account AccountStorage::get_account(const std::string & username) {
    Account result;

    for_each_item([&](const Account & item) {
        if (item.get_username() == username) {
            result = item;
            return true;
        }
        return false;
    });

    return result;
}

void AccountStorage::create_account(const Account & account) {
    std::ofstream fout(ACCOUNTS_FILE, std::ios_base::app);
    AccountFileIO::write_file(fout, account);
}

void AccountStorage::delete_account(const std::string & username) {
    process_file([&](Account & item, std::ofstream & fout) {
        if (item.get_username() != username) {
            AccountFileIO::write_file(fout, item);
        }
    });
}

void AccountStorage::update_account(
    const Account & old_account,
    const Account & new_account
) {
    process_file([&](Account & item, std::ofstream & fout) {
        if (item.get_username() == old_account.get_username()
            && item.get_password() == old_account.get_password()) {
            item.set_username(new_account.get_username());
            item.set_password(new_account.get_password());
        }
        AccountFileIO::write_file(fout, item);
    });
}

void AccountStorage::update_account(
    const std::string & username,
    const Account & account
) {
    process_file([&](Account & item, std::ofstream & fout) {
        if (item.get_username() == account.get_username()) {
            item = account;
        }
        AccountFileIO::write_file(fout, item);
    });
}
