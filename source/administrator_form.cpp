#include "administrator_form.hpp"

void AdministratorForm::show() {
    std::wstring header = L"< ADMINISTRATOR MENU >";
    std::vector<std::wstring> option = {
        L"Add employee account",
        L"Delete employee account",
        L"Search employee account",
        L"Edit employee account",
        L"Display employee account information",
        L"Log out"
    };

    while (true) {
        console::resize(500, 500);
        console::move_to::center();

        char event = menu_options(header, option);

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

InputResult AdministratorForm::prompt_username(const std::string & header) {
    system("cls");
    std::cout << byellow << "<" << header << ">" << std::endl;
    std::cout << bred << "Username cannot have spaces" << std::endl;
    std::cout << white << "<ESC> to back" << std::endl;
    std::cout << bblue << "    Enter username: " << reset_color;

    return input_text();
}

void AdministratorForm::handle_add() {
    while (true) {
        InputResult input_result = prompt_username("Add account");

        if (input_result.cancelled) {
            return;
        }

        if (!AccountStorage::has_username(input_result.value)) {
            User user(input_result.value);
            console::read_info(user);

            UserService::create_user(user);
            success("Account added successfully!");
            return;
        }

        warning("Username already exists!!!");
    }
}

void AdministratorForm::handle_delete() {
    while (true) {
        InputResult input_result = prompt_username("Delete account");

        if (input_result.cancelled) {
            return;
        }

        if (AccountStorage::has_username(input_result.value)) {
            UserService::delete_user(input_result.value);
            success("Delete success!!!");
            return;
        }

        warning("Can't find \"" + input_result.value + "\"!!!");
    }
}

void AdministratorForm::handle_search() {
    while (true) {
        InputResult input_result = prompt_username("Search account");

        if (input_result.cancelled) {
            return;
        }

        if (AccountStorage::has_username(input_result.value)) {
            User user = UserService::get_user(input_result.value);
            std::cout << byellow << "    Account information: " << std::endl;
            console::write_info(user);
            system("pause");
            return;
        }

        warning("Can't find \"" + input_result.value + "\"!!!");
    }
}

void AdministratorForm::handle_edit() {
    InputResult input_result;

    while (true) {
        input_result = prompt_username("Edit account");

        if (input_result.cancelled) {
            return;
        }

        if (AccountStorage::has_username(input_result.value)) {
            break;
        }

        warning("Can't find \"" + input_result.value + "\"!!!");
    }

    std::wstring header = L"< Select the information to edit >";
    std::vector<std::wstring> option = {
        L"Full name", L"Address", L"Phone number", L"Email address"
    };
    std::vector<std::wstring> sub_option = {L"<ESC> to back"};

    while (true) {
        char event = menu_options(header, option, sub_option);

        if (48 < event && event < 53) {
            std::string info_updated;

            std::cout << bblue << "Update information in the selection: ";
            std::cout << reset_color << event - 48 << std::endl;
            std::cout << bblue << "New information will be updated: ";
            std::cout << reset_color;
            std::cin.ignore();
            getline(std::cin, info_updated);

            UserStorage::update_user(input_result.value, info_updated, event);

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
