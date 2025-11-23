#include "display/administrator_form.hpp"

void AdministratorForm::show() {
    std::string header = "Administrator menu";
    std::vector<std::string> option = {
        " [1] Search for an employee account ",
        " [2] Create a new employee account ",
        " [3] Update an employee's account information ",
        " [4] Delete an employee account ",
        " [5] Display the employee account information list ",
        " [6] Log out ",
    };

    while (true) {
        setup_window_layout();

        system("cls");
        draw_header(header);
        char event = menu_options(option);
        std::cout << std::endl;

        switch (event) {
            case 49: {
                handle_search();
                break;
            }
            case 50: {
                handle_create();
                break;
            }
            case 51: {
                handle_update();
                break;
            }
            case 52: {
                handle_delete();
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
                std::cout << std::endl;
                warning("Invalid choice!!!");
                pause_screen();
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
    InputResult input_result = prompt_username("Search for an account", true);
    if (input_result.cancelled) {
        return;
    }

    // TODO: Consider allowing relative searches
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
    InputResult input_result = prompt_username("Create a new account", false);
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
    InputResult input_result = prompt_username("Delete an account", true);
    if (input_result.cancelled) {
        return;
    }

    UserService::delete_user(input_result.value);
    success("Account deleted successfully!");
    pause_screen();
}

void AdministratorForm::handle_update() {
    InputResult input_result = prompt_username("Update an account", true);
    if (input_result.cancelled) {
        return;
    }

    std::string header = "Choose the field to edit: " + input_result.value;
    std::vector<std::string> option = {
        " [1] Full name ",
        " [2] Address ",
        " [3] Phone number ",
        " [4] Email address ",
    };
    std::vector<std::string> sub_option = {"<ESC> to back"};
    User user = UserService::get_user(input_result.value);

    while (true) {
        system("cls");
        draw_header(header);
        std::cout << "<ESC> to back" << std::endl;
        std::cout << std::endl;

        write_fields(
            "Account information",
            {
                {" Full name: ", user.get_full_name()},
                {" Address  : ", user.get_address()},
                {" Phone    : ", user.get_phone_number()},
                {" Email    : ", user.get_email_address()},
            }
        );
        char event = menu_options(option);
        std::cout << std::endl << std::endl;

        if (event == 27) {
            return;
        }

        if (48 < event && event < 53) {
            std::string new_value;

            question("Updating field       : ");
            std::cout << event - 48 << std::endl;
            question("Enter new information: ");
            getline(std::cin, new_value);

            UserService::update_user(input_result.value, event, new_value);

            std::cout << std::endl;
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

    std::cout << byellow << "<The employee account information list>"
              << reset_color;
    std::cout << std::endl;

    show_info_accounts();

    pause_screen();
}

void AdministratorForm::show_a_part_border_horizontal(
    std::vector<std::pair<std::string, size_t>> number_of_fill,
    std::string middle,
    std::string last
) {
    size_t size = number_of_fill.size();
    for (int i = 0; i < size; i++) {
        std::cout << box::utf8_setw(
            number_of_fill[i].second + 2, border_.horizontal()
        );
        std::cout << (i != size - 1 ? middle : last);
    }
};

void AdministratorForm::show_a_part_border(
    std::vector<std::pair<std::string, size_t>> number_of_fill,
    Position position
) {
    if (position == Position::FIRST) {
        std::cout << border_.top_left();
        show_a_part_border_horizontal(
            number_of_fill, border_.top(), border_.top_right()
        );
        return;
    }
    if (position == Position::MIDDLE) {
        std::cout << border_.left();
        show_a_part_border_horizontal(
            number_of_fill, border_.center(), border_.right()
        );
        return;
    }
    if (position == Position::LAST) {
        std::cout << border_.bottom_left();
        show_a_part_border_horizontal(
            number_of_fill, border_.bottom(), border_.bottom_right()
        );
        return;
    }
}

// Output to console in given format:
// Pair (maxSize: maximum cell size, wString: One sentence), BorderStyle:
// Single(customizable)
void AdministratorForm::show_info_account(
    std::vector<std::pair<std::string, size_t>> max_size_and_wstring_pairs,
    Color text_color,
    std::string fill_type
) {
    std::cout << border_.vertical();
    for (auto & element : max_size_and_wstring_pairs) {
        size_t max_size = element.second;
        set_color(text_color);
        std::cout << fill_type;
        std::cout << box::utf8_setw(max_size, fill_type, element.first);
        std::cout << fill_type;
        std::cout << reset_color << border_.vertical();
    }
}

void AdministratorForm::show_info_accounts() {
    std::vector<std::pair<std::string, size_t>> titles = {
        std::make_pair("No.", 3),
        std::make_pair("Username", 8),
        std::make_pair("Password", 8),
        std::make_pair("Full name", 9),
        std::make_pair("Address", 7),
        std::make_pair("Phone number", 12),
        std::make_pair("Email address", 13)
    };
    std::vector<std::vector<std::string>> rows;
    std::ifstream fin;

    std::unordered_map<std::string, User> user_map =
        UserStorage::get_users_map();

    fin.open(ACCOUNTS_FILE);
    for (int index = 1; !fin.eof(); index++) {
        User user;
        Account account;

        AccountFileIO::read_file(fin, account);
        user = user_map[account.get_username()];

        std::vector<std::string> properties = {
            std::to_string(index),
            account.get_username(),
            account.get_password(),
            user.get_full_name(),
            user.get_address(),
            user.get_phone_number(),
            user.get_email_address()
        };

        // Find the maximum size of each table cell, horizontally
        if (account.get_username() != "") {
            rows.push_back(properties);
            for (size_t i = 0; i < properties.size(); i++) {
                if (titles.at(i).second < properties.at(i).size()) {
                    titles.at(i).second = properties.at(i).size();
                }
            }
        }
    }
    fin.close();

    show_a_part_border(titles, Position::FIRST);
    std::cout << std::endl;

    // Show titles
    show_info_account(titles, Color::BRIGHT_YELLOW);
    std::cout << std::endl;

    show_a_part_border(titles, Position::MIDDLE);
    std::cout << std::endl;

    // Show all account information
    for (int i = 0; i < rows.size(); i++) {
        std::vector<std::string> row = rows.at(i);

        std::vector<std::pair<std::string, size_t>> vec_title_and_max_size_temp;
        for (size_t j = 0; j < titles.size(); j++) {
            vec_title_and_max_size_temp.push_back(
                std::make_pair(row.at(j), titles.at(j).second)
            );
        }

        show_info_account(vec_title_and_max_size_temp, Color::BRIGHT_YELLOW);
        std::cout << std::endl;

        if (i != rows.size() - 1) {
            show_a_part_border(titles, Position::MIDDLE);
            std::cout << std::endl;
        }
    }
    show_a_part_border(titles, Position::LAST);
}
