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
            std::cout << byellow;
            std::cout << "<Them tai khoan>" << std::endl;
            std::cout << bred;
            std::cout << "Ten tai khoan khong duoc co khoang cach" << std::endl;
            std::cout << bblue;
            std::cout << "    Nhap ten tai khoan: ";
            std::cout << reset_color;
            std::cin >> username;

            if (AccountStorage::has_username(username))
                warning("Ten tai khoan da ton tai!!!");
            else {
                User user;

                AccountStorage::create_account(username);
                user.set_username(username);
                console::read_info(user);
                UserStorage::create_user(user);

                std::cout << bred;
                std::cout << "Them thanh cong!!!" << std::endl;
                system("pause");
            }
            break;
        case 50:
            system("cls");
            std::cout << byellow;
            std::cout << "<Xoa tai khoan>" << std::endl;
            std::cout << bred;
            std::cout << "Ten tai khoan khong duoc co khoang cach" << std::endl;
            std::cout << bblue;
            std::cout << "    Nhap ten tai khoan: ";
            std::cout << reset_color;
            username.clear();
            std::cin >> username;

            if (AccountStorage::has_username(username)) {
                AccountStorage::delete_account(username);
                UserStorage::delete_user(username);

                std::cout << bred;
                std::cout << "Xoa thanh cong!!!" << std::endl;
                system("pause");
            } else
                warning("Khong tim thay \"" + username + "\" de xoa!!!");
            break;
        case 51:
            system("cls");
            std::cout << byellow;
            std::cout << "<Tim tai khoan>" << std::endl;
            std::cout << bred;
            std::cout << "Ten tai khoan khong duoc co khoang cach" << std::endl;
            std::cout << bblue;
            std::cout << "    Nhap ten tai khoan: ";
            std::cout << reset_color;
            username.clear();
            std::cin >> username;

            if (AccountStorage::has_username(username)) {
                std::cout << byellow;
                std::cout << "    Thong tin Employee can tim: " << std::endl;

                User user = UserStorage::read_user(username);
                console::write_info(user);

                system("pause");
            } else
                warning("Khong tim thay \"" + username + "\"!!!");
            break;
        case 52:
            system("cls");
            std::cout << byellow;
            std::cout << "<Cap nhat thong tin tai khoan>" << std::endl;
            std::cout << bred;
            std::cout << "Ten tai khoan khong duoc co khoang cach" << std::endl;
            std::cout << bblue;
            std::cout << "    Nhap ten tai khoan: ";
            std::cout << reset_color;
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
                        std::cout << bblue;
                        std::cout << "Cap nhat thong tin o lua chon: ";
                        std::cout << reset_color;
                        std::cout << event - 48 << std::endl;
                        std::cout << bblue;
                        std::cout << "Thong tin moi se duoc cap nhat: ";
                        std::cout << reset_color;
                        std::cin.ignore();
                        getline(std::cin, info_updated);

                        UserStorage::update_user(username, info_updated, event);

                        std::cout << bred;
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
            std::cout << byellow;
            std::cout << "<Hien thi thong tin toan bo tai khoan>" << std::endl;
            std::cout << reset_color;

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
