#include "display/administrator_form.hpp"

const box::Border AdministratorForm::border_;

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
                break;
            }
        }
    }
}

void AdministratorForm::write_fields(
    std::string header,
    std::vector<std::pair<std::string, std::string>> fields
) {
    std::cout << byellow << header << reset_color << std::endl;

    size_t size = fields.size();
    for (size_t i = 0; i < size - 1; i++) {
        std::cout << "    " << border_.left() << border_.horizontal() << " "
                  << baqua << fields[i].first << reset_color << fields[i].second
                  << std::endl;
    }
    std::cout << "    " << border_.bottom_left() << border_.horizontal() << " "
              << baqua << fields[size - 1].first << reset_color
              << fields[size - 1].second << std::endl;
}

void AdministratorForm::pause_screen() {
    std::cout << box::utf8_setw(width_, border_.horizontal()) << std::endl;
    system("pause");
}

InputResult AdministratorForm::prompt_username(const std::string & header) {
    system("cls");
    std::cout << border_.top_left()
              << box::utf8_setw(width_ - 2, border_.horizontal())
              << border_.top_right() << std::endl;
    std::cout << border_.vertical() << byellow
              << box::utf8_setw(width_ - 2, " ", " > " + header) << reset_color
              << border_.vertical() << std::endl;
    std::cout << border_.bottom_left()
              << box::utf8_setw(width_ - 2, border_.horizontal())
              << border_.bottom_right() << std::endl;

    std::cout << white << "<ESC> to back" << std::endl;
    std::cout << bred << "[!] Username cannot have spaces" << std::endl
              << std::endl;
    std::cout << bblue << "[?] Enter username: " << reset_color;

    InputResult input_result = input_text();
    std::cout << std::endl << std::endl;

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

    write_fields(
        "[+] Account information",
        {
            {"Full name: ", user.get_full_name()},
            {"Address  : ", user.get_address()},
            {"Phone    : ", user.get_phone_number()},
            {"Email    : ", user.get_email_address()},
        }
    );

    std::cout << std::endl;

    pause_screen();
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
    window::resize(1275, 750);
    window::move_to_center();

    std::cout << byellow << "<Show full account information>" << reset_color;
    std::cout << std::endl;

    show_info_accounts();

    pause_screen();
}
