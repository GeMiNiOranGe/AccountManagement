#include "display/employee_form.hpp"

void EmployeeForm::show(const Account & account) {
    std::string header = "< EMPLOYEE MENU >";
    std::vector<std::string> option = {
        " 1. View account information ", " 2. Change password ", " 3. Log out "
    };

    while (true) {
        window::resize(500, 500);
        window::move_to_center();

        char event = menu_options(header, option);

        switch (event) {
            case 49: {
                handle_view_personal_information(account);
                break;
            }
            case 50: {
                handle_change_password(account);
                break;
            }
            case 51: {
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

void EmployeeForm::handle_view_personal_information(const Account & account) {
    system("cls");
    std::cout << byellow << "<Account information>" << std::endl;
    std::cout << yellow << "    Username: " << reset_color;
    std::cout << account.get_username() << std::endl;

    User user = UserStorage::get_user(account.get_username());
    console::write_info(user);

    system("pause");
}

void EmployeeForm::handle_change_password(const Account & account) {
    system("cls");
    std::cout << byellow << "<Change password>" << std::endl;
    std::cout << "<ESC> to back" << std::endl;

    std::cout << bblue << "Enter current password: " << reset_color;
    InputResult current_password = input_text(true);
    std::cout << std::endl;
    if (current_password.cancelled) {
        return;
    }

    std::cout << bblue << "Enter new password: " << reset_color;
    InputResult new_password = input_text(true);
    std::cout << std::endl;
    if (new_password.cancelled) {
        return;
    }

    std::cout << bblue << "Confirm new password: " << reset_color;
    InputResult confirm_new_password = input_text(true);
    std::cout << std::endl;
    if (confirm_new_password.cancelled) {
        return;
    }

    bool is_valid_password =
        new_password.value != current_password.value
        && new_password.value == confirm_new_password.value;

    if (!is_valid_password) {
        warning("Wrong information!!!");
        system("pause");
        return;
    }

    AccountService::update_password(account.get_username(), new_password.value);
    success("Password updated successfully!");
    system("pause");
}
