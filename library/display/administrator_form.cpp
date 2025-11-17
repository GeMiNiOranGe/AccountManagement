#include "display/administrator_form.hpp"

void AdministratorForm::show() {
    std::string header = "< ADMINISTRATOR MENU >";
    std::vector<std::string> option = {
        " 1. Add employee account ",
        " 2. Delete employee account ",
        " 3. Search employee account ",
        " 4. Edit employee account ",
        " 5. Display employee account information ",
        " 6. Log out ",
    };

    while (true) {
        console::resize(500, 500);
        console::move_to::center();

        char event = menu_options(header, option);

        switch (event) {
            case 49:
                handle_create();
                break;
            case 50:
                handle_delete();
                break;
            case 51:
                handle_search();
                break;
            case 52:
                handle_update();
                break;
            case 53:
                handle_show_accounts();
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

    InputResult input_result = input_text();
    std::cout << std::endl;

    return input_result;
}

InputResult AdministratorForm::prompt_username_until(
    const std::string & header,
    bool must_exist
) {
    while (true) {
        InputResult input_result = prompt_username(header);

        if (input_result.cancelled) {
            return input_result;
        }

        bool exists = AccountStorage::has_username(input_result.value);

        if ((must_exist && exists) || (!must_exist && !exists)) {
            return input_result;
        }

        if (must_exist) {
            warning("Can't find \"" + input_result.value + "\"!!!");
        } else {
            warning("Username already exists!!!");
        }
    }
}

void AdministratorForm::handle_search() {
    InputResult input_result = prompt_username_until("Search account", true);
    if (input_result.cancelled) {
        return;
    }

    User user = UserService::get_user(input_result.value);
    std::cout << byellow << "    Account information: " << std::endl;
    console::write_info(user);
    system("pause");
}

void AdministratorForm::handle_create() {
    InputResult input_result = prompt_username_until("Add account", false);
    if (input_result.cancelled) {
        return;
    }

    User user(input_result.value);
    console::read_info(user);

    UserService::create_user(user);
    success("Account created successfully!");
}

void AdministratorForm::handle_delete() {
    InputResult input_result = prompt_username_until("Delete account", true);
    if (input_result.cancelled) {
        return;
    }

    UserService::delete_user(input_result.value);
    success("Account deleted successfully!");
}

void AdministratorForm::handle_update() {
    InputResult input_result = prompt_username_until("Edit account", true);
    if (input_result.cancelled) {
        return;
    }

    std::string header = "< Select the information to edit >";
    std::vector<std::string> option = {
        " 1. Full name ",
        " 2. Address ",
        " 3. Phone number ",
        " 4. Email address ",
    };
    std::vector<std::string> sub_option = {"<ESC> to back"};

    while (true) {
        char event = menu_options(header, option, sub_option);

        if (event == 27) {
            return;
        }

        if (48 < event && event < 53) {
            std::string new_value;

            std::cout << bblue << "Updating field: " << reset_color;
            std::cout << event - 48 << std::endl;
            std::cout << bblue << "Enter new information: " << reset_color;
            getline(std::cin, new_value);

            UserService::update_user(input_result.value, event, new_value);

            success("Account updated successfully!");
            return;
        }

        warning("Invalid choice!!!");
    }
}

void AdministratorForm::handle_show_accounts() {
    system("cls");
    console::resize(1275, 750);
    console::move_to::center();

    std::cout << byellow << "<Show full account information>" << reset_color;
    std::cout << std::endl;

    show_info_accounts();

    system("pause");
}
