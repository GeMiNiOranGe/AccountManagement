#include "administrator_form.hpp"

void AdministratorForm::show() {
    std::string info_updated, username;
    char event;

    while (true) {
        console::resize(500, 500);
        console::move_to::center();
        event = menu_options(
            L"< MENU ADMINISTRATOR >",
            {L"Add employee account",
             L"Delete employee account",
             L"Search employee account",
             L"Edit employee account",
             L"Display employee account information",
             L"Log out"});

        switch (event) {
        case 49:
            system("cls");
            set_color(Color::LIGHT_YELLOW);
            std::cout << "<Them Employees>" << std::endl;
            set_color(Color::LIGHT_RED);
            std::cout << "Ten tai khoan khong duoc co khoang cach" << std::endl;
            set_color(Color::LIGHT_BLUE);
            std::cout << "    Nhap ten tai khoan muon them: ";
            set_color(Color::BRIGHT_WHITE);
            std::cin >> username;

            if (AccountStorage::has_username(username))
                warning("Ten tai khoan da ton tai!!!");
            else {
                User user;

                AccountStorage::create_account(username);
                user.set_username(username);
                console::read_info(user);
                UserStorage::create_user(user);

                set_color(Color::LIGHT_RED);
                std::cout << "Them thanh cong!!!" << std::endl;
                system("pause");
            }
            break;
        case 50:
            system("cls");
            set_color(Color::LIGHT_YELLOW);
            std::cout << "<Xoa Employees>" << std::endl;
            set_color(Color::LIGHT_RED);
            std::cout << "Ten tai khoan khong duoc co khoang cach" << std::endl;
            set_color(Color::LIGHT_BLUE);
            std::cout << "    Nhap ten tai khoan muon xoa: ";
            set_color(Color::BRIGHT_WHITE);
            username.clear();
            std::cin >> username;

            if (AccountStorage::has_username(username)) {
                AccountStorage::delete_account(username);
                UserStorage::delete_user(username);

                set_color(Color::LIGHT_RED);
                std::cout << "Xoa thanh cong!!!" << std::endl;
                system("pause");
            } else
                warning("Khong tim thay \"" + username + "\" de xoa!!!");
            break;
        case 51:
            system("cls");
            set_color(Color::LIGHT_YELLOW);
            std::cout << "<Tim Employees>" << std::endl;
            set_color(Color::LIGHT_RED);
            std::cout << "Ten tai khoan khong duoc co khoang cach" << std::endl;
            set_color(Color::LIGHT_BLUE);
            std::cout << "    Nhap ten tai khoan muon tim: ";
            set_color(Color::BRIGHT_WHITE);
            username.clear();
            std::cin >> username;

            if (AccountStorage::has_username(username)) {
                set_color(Color::LIGHT_YELLOW);
                std::cout << "    Thong tin Employee can tim: " << std::endl;

                User user = UserStorage::read_user(username);
                console::write_info(user);

                system("pause");
            } else
                warning("Khong tim thay \"" + username + "\"!!!");
            break;
        case 52:
            system("cls");
            set_color(Color::LIGHT_YELLOW);
            std::cout << "<Cap nhat thong tin Employees>" << std::endl;
            set_color(Color::LIGHT_BLUE);
            std::cout << "Nhap ten tai khoan can cap nhat: ";
            set_color(Color::BRIGHT_WHITE);
            username.clear();
            std::cin >> username;
            if (AccountStorage::has_username(username)) {
                while (true) {
                    event = menu_options(
                        L"< Select the information to edit >",
                        {L"Full name",
                         L"Address",
                         L"Phone number",
                         L"Email address"},
                        {L"<ESC> de huy bo"});

                    if (48 < event && event < 53) {
                        set_color(Color::LIGHT_BLUE);
                        std::cout << "Cap nhat thong tin o lua chon: ";
                        set_color(Color::BRIGHT_WHITE);
                        std::cout << event - 48 << std::endl;
                        set_color(Color::LIGHT_BLUE);
                        std::cout << "Thong tin moi se duoc cap nhat: ";
                        set_color(Color::BRIGHT_WHITE);
                        std::cin.ignore();
                        getline(std::cin, info_updated);

                        UserStorage::update_user(username, info_updated, event);

                        set_color(Color::LIGHT_RED);
                        std::cout << "Cap nhat thanh cong!!!" << std::endl;
                        system("pause");
                    } else if (event == 27)
                        break;
                    else
                        warning("Lua chon khong hop le!!!");
                }
            } else
                warning("Khong tim thay \"" + username + "\"!!!");
            break;
        case 53:
            system("cls");
            console::resize(1275, 750);
            console::move_to::center();
            set_color(Color::LIGHT_YELLOW);
            std::cout << "<Hien thi thong tin toan bo Employees>" << std::endl;
            set_color(Color::BRIGHT_WHITE);

            show_info_accounts();

            system("pause");
            system("cls");
            break;
        case 54:
            return;
        default:
            warning("Lua chon khong hop le!!!");
            break;
        }
    }
}
