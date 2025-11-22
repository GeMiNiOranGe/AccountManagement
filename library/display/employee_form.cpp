#include "display/employee_form.hpp"

void EmployeeForm::show(const Account & account) {
    std::string header = "Employee menu";
    std::vector<std::string> option = {
        " [1] View your personal information ",
        " [2] Change your password ",
        " [3] Log out "
    };

    while (true) {
        setup_window_layout();
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
    draw_header("Account information");
    std::cout << yellow << "[+] Your username: " << reset_color
              << account.get_username() << std::endl
              << std::endl;

    User user = UserStorage::get_user(account.get_username());
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

void EmployeeForm::handle_change_password(const Account & account) {
    system("cls");
    draw_header("Change password");
    std::cout << "<ESC> to back" << std::endl << std::endl;

    question("Enter current password: ");
    InputResult current_password = input_text(true);
    std::cout << std::endl;
    if (current_password.cancelled) {
        return;
    }

    question("Enter new password    : ");
    InputResult new_password = input_text(true);
    std::cout << std::endl;
    if (new_password.cancelled) {
        return;
    }

    question("Confirm new password  : ");
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
        pause_screen();
        return;
    }

    AccountService::update_password(account.get_username(), new_password.value);

    std::cout << std::endl;
    success("Password updated successfully!");
    pause_screen();
}
