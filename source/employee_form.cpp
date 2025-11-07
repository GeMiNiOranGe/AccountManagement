#include "employee_form.hpp"

void EmployeeForm::show(Account _account) {
    char event;
    while (true) {
        std::string current_password, new_password, confirm_new_password;
        User user;

        console::resize(500, 500);
        console::move_to::center();
        event = menu_options(
            L"< MENU EMPLOYEE >",
            {L"View account information",
             L"Change password",
             L"Log out"});

        switch (event) {
        case 49:
            system("cls");
            set_color(Color::LIGHT_YELLOW);
            std::cout << "<Thong tin tai khoan>" << std::endl;
            set_color(Color::YELLOW);
            std::cout << "    Ten tai khoan: ";
            set_color(Color::BRIGHT_WHITE);
            std::cout << _account.get_username() << std::endl;

            user = UserStorage::read_user(_account.get_username());
            console::write_info(user);

            system("pause");
            system("cls");
            break;
        case 50:
            system("cls");
            set_color(Color::LIGHT_YELLOW);
            std::cout << "<Doi mat khau>" << std::endl;
            set_color(Color::LIGHT_BLUE);
            std::cout << "Nhap mat khau hien tai: ";
            set_color(Color::BRIGHT_WHITE);
            encode_password(current_password);
            std::cout << std::endl;
            set_color(Color::LIGHT_BLUE);
            std::cout << "Nhap mat khau moi: ";
            set_color(Color::BRIGHT_WHITE);
            encode_password(new_password);
            std::cout << std::endl;
            set_color(Color::LIGHT_BLUE);
            std::cout << "Nhap lai mat khau moi: ";
            set_color(Color::BRIGHT_WHITE);
            encode_password(confirm_new_password);
            std::cout << std::endl;

            if (new_password != current_password && new_password == confirm_new_password) {
                Account new_account;
                new_account.set_username(_account.get_username());
                new_account.set_password(new_password);

                AccountStorage::update_account(_account, new_account);
                _account.set_password(new_account.get_password());

                set_color(Color::LIGHT_RED);
                std::cout << "Cap nhat thanh cong!!!" << std::endl;
                system("pause");
            } else
                warning("Sai thong tin!!!");
            break;
        case 51:
            return;
        default:
            warning("Lua chon khong hop le!!!");
            break;
        }
    }
}
