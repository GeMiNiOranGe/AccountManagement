#include "display/main_form.hpp"

void MainForm::show() {
    SetConsoleTitle(L"Acsyra");

    int number_of_login = 3;
    while (true) {
        window::resize(350, 400);
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
            std::cout << byellow;
            std::cout << "<Change default password>" << std::endl;
            std::cout << "<ESC> to back" << std::endl;
            std::cout << "(The default password is: " + DEFAULT_PASSWORD + ")"
                      << std::endl;

            std::cout << bblue << "Enter new password: " << reset_color;
            InputResult new_password = input_text(true);
            std::cout << std::endl;
            if (new_password.cancelled) {
                continue;
            }

            std::cout << bblue << "Confirm new password: " << reset_color;
            InputResult confirm_new_password = input_text(true);
            std::cout << std::endl;
            if (confirm_new_password.cancelled) {
                continue;
            }

            if (new_password.value != DEFAULT_PASSWORD
                && new_password.value == confirm_new_password.value) {
                AccountService::update_password(username, new_password.value);

                success("Password updated successfully!");
                system("pause");
            } else {
                warning("Wrong information!!!");
                system("pause");
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
                    EmployeeForm::show(username);
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
