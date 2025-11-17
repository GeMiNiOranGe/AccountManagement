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
            case 49:
                handle_view_personal_information(account);
                break;
            case 50:
                handle_change_password(account);
                break;
            case 51:
                return;
            default:
                warning("Invalid choice!!!");
                break;
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

    std::cout << bblue << "Enter current password: " << reset_color;
    std::string current_password = input_password();
    std::cout << std::endl;

    std::cout << bblue << "Enter new password: " << reset_color;
    std::string new_password = input_password();
    std::cout << std::endl;

    std::cout << bblue << "Confirm new password: " << reset_color;
    std::string confirm_new_password = input_password();
    std::cout << std::endl;

    bool is_valid_password = new_password != current_password
                             && new_password == confirm_new_password;

    if (!is_valid_password) {
        warning("Wrong information!!!");
        return;
    }

    AccountService::update_password(account.get_username(), new_password);
    success("Password updated successfully!");
}
