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
        window::resize(500, 500);
        window::move_to_center();

        char event = menu_options(header, option);

        window::resize(640, 500);
        window::move_to_center();

        switch (event) {
            case 49: {
                handle_create();
                break;
            }
            case 50: {
                handle_delete();
                break;
            }
            case 51: {
                handle_search();
                break;
            }
            case 52: {
                handle_update();
                break;
            }
            case 53: {
                handle_show_accounts();
                break;
            }
            case 54: {
                return;
            }
            default: {
                warning("Invalid choice!!!");
                system("pause");
                break;
            }
        }
    }
}

InputResult AdministratorForm::prompt_username(
    const std::string & header,
    bool must_exist
) {
    while (true) {
        system("cls");
        draw_header(header);

        std::cout << white << "<ESC> to back" << std::endl;
        std::cout << bred << "[!] Username cannot have spaces" << std::endl
                  << std::endl;
        std::cout << bblue << "[?] Enter username: " << reset_color;

        InputResult input_result = input_text();
        std::cout << std::endl << std::endl;

        if (input_result.cancelled) {
            return input_result;
        }

        bool exists = AccountStorage::has_username(input_result.value);

        if ((must_exist && exists) || (!must_exist && !exists)) {
            return input_result;
        }

        if (must_exist) {
            warning("Can't find \"" + input_result.value + "\"!!!");
            pause_screen();
        } else {
            warning("Username already exists!!!");
            pause_screen();
        }
    }
}

void AdministratorForm::handle_search() {
    InputResult input_result = prompt_username("Search account", true);
    if (input_result.cancelled) {
        return;
    }

    User user = UserService::get_user(input_result.value);

    write_fields(
        "Account information",
        {
            {" Full name: ", user.get_full_name()},
            {" Address  : ", user.get_address()},
            {" Phone    : ", user.get_phone_number()},
            {" Email    : ", user.get_email_address()},
        }
    );

    pause_screen();
}

void AdministratorForm::handle_create() {
    InputResult input_result = prompt_username("Add account", false);
    if (input_result.cancelled) {
        return;
    }

    std::vector<std::string> values = read_fields(
        "Enter account information",
        {
            " Full name: ",
            " Address  : ",
            " Phone    : ",
            " Email    : ",
        }
    );
    User user(input_result.value, values[0], values[1], values[2], values[3]);

    UserService::create_user(user);
    success("Account created successfully!");
    pause_screen();
}

void AdministratorForm::handle_delete() {
    InputResult input_result = prompt_username("Delete account", true);
    if (input_result.cancelled) {
        return;
    }

    UserService::delete_user(input_result.value);
    success("Account deleted successfully!");
    pause_screen();
}

void AdministratorForm::handle_update() {
    InputResult input_result = prompt_username("Edit account", true);
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
            pause_screen();
            return;
        }

        warning("Invalid choice!!!");
        pause_screen();
    }
}

void AdministratorForm::handle_show_accounts() {
    system("cls");
    window::resize(1275, 750);
    window::move_to_center();

    std::cout << byellow << "<Show full account information>" << reset_color;
    std::cout << std::endl;

    show_info_accounts();

    pause_screen();
}
