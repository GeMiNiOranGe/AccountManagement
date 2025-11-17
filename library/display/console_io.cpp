#include "display/console_io.hpp"

void console::read_info(User & _user) {
    std::string full_name, address, phone_number, email_address;
    std::cout << byellow;
    std::cout << "    Nhap thong tin tai khoan" << std::endl;
    std::cout << baqua;
    std::cout << "\tNhap ho ten: ";
    std::cout << bwhite;
    getline(std::cin, full_name);
    std::cout << baqua;
    std::cout << "\tNhap dia chi: ";
    std::cout << bwhite;
    getline(std::cin, address);
    std::cout << baqua;
    std::cout << "\tNhap so dien thoai: ";
    std::cout << bwhite;
    getline(std::cin, phone_number);
    std::cout << baqua;
    std::cout << "\tNhap dia chi email: ";
    std::cout << bwhite;
    getline(std::cin, email_address);
    _user.set_full_name(full_name);
    _user.set_address(address);
    _user.set_phone_number(phone_number);
    _user.set_email_address(email_address);
}

void console::write_info(User _user) {
    std::cout << baqua;
    std::cout << "\tHo ten: ";
    std::cout << bwhite;
    std::cout << _user.get_full_name() << std::endl;
    std::cout << baqua;
    std::cout << "\tDia chi: ";
    std::cout << bwhite;
    std::cout << _user.get_address() << std::endl;
    std::cout << baqua;
    std::cout << "\tSo dien thoai: ";
    std::cout << bwhite;
    std::cout << _user.get_phone_number() << std::endl;
    std::cout << baqua;
    std::cout << "\tDia chi email: ";
    std::cout << bwhite;
    std::cout << _user.get_email_address() << std::endl;
}
