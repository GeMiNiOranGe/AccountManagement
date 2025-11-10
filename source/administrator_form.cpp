#include "administrator_form.hpp"

void AdministratorForm::show() {
    while (true) {
        console::resize(500, 500);
        console::move_to::center();

        char event = menu_options(
            L"< MENU ADMINISTRATOR >",
            {L"Add employee account",
             L"Delete employee account",
             L"Search employee account",
             L"Edit employee account",
             L"Display employee account information",
             L"Log out"}
        );

        switch (event) {
            case 49:
                handle_add();
                break;
            case 50:
                handle_delete();
                break;
            case 51:
                handle_search();
                break;
            case 52:
                handle_edit();
                break;
            case 53:
                handle_show_information();
                break;
            case 54:
                return;
            default:
                warning("Invalid choice!!!");
                break;
        }
    }
}

std::string AdministratorForm::prompt_username(const std::string & header) {
    system("cls");
    std::cout << byellow << "<" << header << ">" << std::endl;
    std::cout << bred << "Username cannot have spaces" << std::endl;
    std::cout << bblue << "    Enter username: " << reset_color;

    std::string username;
    std::cin >> username;
    return username;
}

void AdministratorForm::handle_add() {
    std::string username = prompt_username("Add account");

    /*
    // TODO: Reimplement this code, allow user enter username until it's valid.
    // Loop until user enter a username that doesn't exist in the storage.
    std::string username = prompt_username("Add employee account");

    bool is_success = UserService::create_user(User(username));
    if (is_success) {
        success("Add success!!!");
        return;
    }

    warning("Username already exists!!!");
    */

    if (AccountStorage::has_username(username)) {
        warning("Username already exists!!!");
        return;
    }

    User user;

    AccountService::create_account(username);
    user.set_username(username);
    console::read_info(user);
    UserStorage::create_user(user);

    success("Add success!!!");
}

void AdministratorForm::handle_delete() {
    std::string username = prompt_username("Delete account");

    if (!AccountStorage::has_username(username)) {
        warning("Can't find \"" + username + "\" to delete!!!");
        return;
    }

    AccountStorage::delete_account(username);
    UserStorage::delete_user(username);

    success("Delete success!!!");
}

void AdministratorForm::handle_search() {
    std::string username = prompt_username("Search account");

    if (!AccountStorage::has_username(username)) {
        warning("Can't find \"" + username + "\" to delete!!!");
        return;
    }

    User user = UserStorage::read_user(username);

    std::cout << byellow << "    Account information to find: " << std::endl;
    console::write_info(user);

    system("pause");
}

void AdministratorForm::handle_edit() {
    std::string username = prompt_username("Edit account");

    if (!AccountStorage::has_username(username)) {
        warning("Can't find \"" + username + "\" to delete!!!");
        return;
    }

    while (true) {
        char event = menu_options(
            L"< Select the information to edit >",
            {L"Full name", L"Address", L"Phone number", L"Email address"},
            {L"<ESC> de huy bo"}
        );

        if (48 < event && event < 53) {
            std::string info_updated;

            std::cout << bblue << "Update information in the selection: ";
            std::cout << reset_color << event - 48 << std::endl;
            std::cout << bblue << "New information will be updated: ";
            std::cout << reset_color;
            std::cin.ignore();
            getline(std::cin, info_updated);

            UserStorage::update_user(username, info_updated, event);

            success("Update success!!!");
        } else if (event == 27) {
            break;
        } else {
            warning("Invalid choice!!!");
        }
    }
}

void AdministratorForm::handle_show_information() {
    system("cls");
    console::resize(1275, 750);
    console::move_to::center();

    std::cout << byellow << "<Show full account information>" << reset_color;
    std::cout << std::endl;

    show_info_accounts();

    system("pause");
}
