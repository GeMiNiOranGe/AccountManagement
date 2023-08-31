#include "ConsoleIO.h"

void console::read_info(User & _user) {
	std::string full_name, address, phone_number, email_address;
	std::cin.ignore();
	set_color(Color::LIGHT_YELLOW);
	std::cout << "    Nhap thong tin tai khoan" << std::endl;
	set_color(Color::LIGHT_AQUA);
	std::cout << "\tNhap ho ten: ";
	set_color(Color::BRIGHT_WHITE);
	getline(std::cin, full_name);
	set_color(Color::LIGHT_AQUA);
	std::cout << "\tNhap dia chi: ";
	set_color(Color::BRIGHT_WHITE);
	getline(std::cin, address);
	set_color(Color::LIGHT_AQUA);
	std::cout << "\tNhap so dien thoai: ";
	set_color(Color::BRIGHT_WHITE);
	getline(std::cin, phone_number);
	set_color(Color::LIGHT_AQUA);
	std::cout << "\tNhap dia chi email: ";
	set_color(Color::BRIGHT_WHITE);
	getline(std::cin, email_address);
	_user.set_full_name(full_name);
	_user.set_address(address);
	_user.set_phone_number(phone_number);
	_user.set_email_address(email_address);
}

void console::write_info(User _user) {
	set_color(Color::LIGHT_AQUA);
	std::cout << "\tHo ten: ";
	set_color(Color::BRIGHT_WHITE);
	std::cout << _user.get_full_name() << std::endl;
	set_color(Color::LIGHT_AQUA);
	std::cout << "\tDia chi: ";
	set_color(Color::BRIGHT_WHITE);
	std::cout << _user.get_address() << std::endl;
	set_color(Color::LIGHT_AQUA);
	std::cout << "\tSo dien thoai: ";
	set_color(Color::BRIGHT_WHITE);
	std::cout << _user.get_phone_number() << std::endl;
	set_color(Color::LIGHT_AQUA);
	std::cout << "\tDia chi email: ";
	set_color(Color::BRIGHT_WHITE);
	std::cout << _user.get_email_address() << std::endl;
}
