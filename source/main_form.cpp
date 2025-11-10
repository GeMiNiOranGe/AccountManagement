#include "main_form.hpp"

void MainForm::show() {
    SetConsoleTitle(L"Employee management");
    // console::resize(1920, 1080);// 377
    // console::move_to::center();

    // form_info(
    // 	L"Enter your information",
    // 	{ L"Full name:",
    // 	  L"Address:",
    // 	  L"Phone number:",
    // 	  L"Email address:" },
    // 	box::BorderStyle::CORNER_DOUBLE
    // );

    // show_info_accounts();

    int number_of_login = 3;
    while (true) {
        console::resize(350, 400);
        console::move_to::center();

        bool is_logged_in = true;

        auto pair_user_pass = show_login_form();
        Account account = AccountStorage::get_account_details(
            pair_user_pass.first, pair_user_pass.second
        );

        if (AccountStorage::has_account(account)
            && account.get_password() == DEFAULT_PASSWORD) {
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
                Account new_account;
                new_account.set_username(account.get_username());
                new_account.set_password(new_password);

                AccountStorage::update_account(account, new_account);

                std::cout << bred;
                std::cout << "Cap nhat thanh cong!!!" << std::endl;
                system("pause");
            } else {
                warning("Sai thong tin!!!");
                is_logged_in = false;
            }
        }

        if (is_logged_in)
            switch (account.get_role()) {
                case AccountRole::ADMINISTRATOR:
                    AdministratorForm::show();
                    break;
                case AccountRole::EMPLOYEE:
                    EmployeeForm::show(account);
                    break;
                default:
                    number_of_login--;
                    std::cout << "So lan dang nhap con lai: " << number_of_login
                              << std::endl;
                    std::cout << std::endl;
                    warning("Sai tai khoan hoac mat khau!!!");
                    break;
            }

        if (number_of_login == 0)
            break;
    }

    // char key_press;
    // int ascii_value;
    // cout << "\n\t\tNhap phim bat ky de kiem tra ma ASCII\n\t\t\An ESC de
    // thoat\n\n\n"; while (1) {
    //	key_press = _getch();
    //	ascii_value = key_press;
    //	if (ascii_value == 27) // For ESC
    //		break;
    //	cout << "Ban nhap phim-> \" " << key_press << " \" Gia tri ASCII =  " <<
    // ascii_value << "\n";
    // }
}
