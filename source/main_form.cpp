#include "main_form.hpp"

void MainForm::show() {
    SetConsoleTitle(L"Employee management");

    int number_of_login = 3;
    while (true) {
        console::resize(350, 400);
        console::move_to::center();

        auto pair_user_pass = show_login_form();
        auto result = AccountService::try_login(
            pair_user_pass.first, pair_user_pass.second
        );

        if (result.first && pair_user_pass.second == DEFAULT_PASSWORD) {
            system("cls");
            std::cout << byellow;
            std::cout << "<Doi mat khau mac dinh>" << std::endl;
            std::cout << "(Mat khau mac dinh la: " + DEFAULT_PASSWORD + ")"
                      << std::endl;

            std::cout << bblue << "Nhap mat khau moi: " << reset_color;
            std::string new_password = input_password();
            std::cout << std::endl;

            std::cout << bblue << "Nhap lai mat khau moi: " << reset_color;
            std::string confirm_new_password = input_password();
            std::cout << std::endl;

            if (new_password != DEFAULT_PASSWORD
                && new_password == confirm_new_password) {
                AccountService::update_password(
                    pair_user_pass.first, new_password
                );

                success("Cap nhat thanh cong!!!");
            } else {
                warning("Sai thong tin!!!");
            }
        }

        if (result.first) {
            // reset number of login
            number_of_login = 3;
            switch (result.second) {
                case AccountRole::ADMINISTRATOR:
                    AdministratorForm::show();
                    break;
                case AccountRole::EMPLOYEE:
                    EmployeeForm::show(pair_user_pass.first);
                    break;
                default:
                    break;
            }
        } else {
            number_of_login--;
            std::cout << "So lan dang nhap con lai: " << number_of_login
                      << "\n\n";
            warning("Sai tai khoan hoac mat khau!!!");
        }

        if (number_of_login == 0) {
            break;
        }
    }
}
