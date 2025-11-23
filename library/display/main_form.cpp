#include "display/main_form.hpp"

void MainForm::show() {
    SetConsoleTitle(L"Acsyra");

    int number_of_login = 3;
    while (true) {
        window::resize(320, 400);
        window::move_to_center();

        // TODO: use `auto [cancelled, creds] = show_login_form();` when C++17
        auto login_result = show_login_form();
        if (login_result.first) {
            break;
        }

        auto creds = login_result.second;
        std::string username = creds.first;
        std::string password = creds.second;

        auto result = AccountService::try_login(username, password);
        std::cout << std::endl << std::endl << std::endl;

        if (result.first && password == DEFAULT_PASSWORD) {
            system("cls");
            setup_window_layout();
            draw_header("Change default password");
            std::cout << "<ESC> to back" << std::endl << std::endl;

            section("The default password is \"" + DEFAULT_PASSWORD + "\".");

            question("Enter new password  : ");
            InputResult new_password = input_text(true);
            std::cout << std::endl;
            if (new_password.cancelled) {
                continue;
            }

            question("Confirm new password: ");
            InputResult confirm_new_password = input_text(true);
            std::cout << std::endl;
            if (confirm_new_password.cancelled) {
                continue;
            }

            std::cout << std::endl;

            if (new_password.value != DEFAULT_PASSWORD
                && new_password.value == confirm_new_password.value) {
                AccountService::update_password(username, new_password.value);

                success("Password updated successfully!");
                pause_screen();
            } else {
                warning("Wrong information!!!");
                pause_screen();
                // prevent login with default password
                continue;
            }
        }

        if (result.first) {
            // reset number of login
            number_of_login = 3;
            switch (result.second) {
                case AccountRole::ADMINISTRATOR: {
                    AdministratorForm::show();
                    break;
                }
                case AccountRole::EMPLOYEE: {
                    EmployeeForm::show(Account(username));
                    break;
                }
                default: {
                    break;
                }
            }
        } else {
            number_of_login--;
            std::cout << "Number of remaining logins: " << number_of_login
                      << "\n\n";
            warning("Incorrect username or password!");
            system("pause");
        }

        if (number_of_login == 0) {
            break;
        }
    }
}

std::pair<bool, std::pair<std::string, std::string>>
MainForm::show_login_form() {
    std::string title = "Log in";
    std::string username_label = "Username: ";
    std::string password_label = "Password: ";

    size_t width = width_ / 2 - 2;
    size_t align_middle = (width - title.size()) / 2;

    system("cls");
    std::cout << border_.top_left()
              << box::utf8_setw(width, border_.horizontal())
              << border_.top_right() << std::endl;
    for (int i = 0; i < 3; i++) {
        std::cout << border_.vertical() << box::utf8_setw(width)
                  << border_.vertical() << std::endl;
    }
    std::cout << border_.left() << box::utf8_setw(width, border_.horizontal())
              << border_.right() << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << border_.vertical() << box::utf8_setw(width)
                  << border_.vertical() << std::endl;
    }
    std::cout << border_.bottom_left()
              << box::utf8_setw(width, border_.horizontal())
              << border_.bottom_right() << std::endl;
    std::cout << "<ESC> to quit" << std::endl;

    std::cout << byellow;
    go_to_xy(static_cast<short>(align_middle) + 1, 2);
    std::cout << title;
    go_to_xy(2, 6);
    std::cout << username_label;
    go_to_xy(2, 8);
    std::cout << password_label;
    std::cout << reset_color;

    go_to_xy(static_cast<short>(username_label.size()) + 2, 6);
    InputResult username = input_text();
    if (username.cancelled) {
        return {true, {"", ""}};
    }

    go_to_xy(static_cast<short>(password_label.size()) + 2, 8);
    InputResult password = input_text(true);
    if (password.cancelled) {
        return {true, {"", ""}};
    }

    return {false, {username.value, password.value}};
}
