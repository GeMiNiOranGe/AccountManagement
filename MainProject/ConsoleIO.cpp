#include "ConsoleIO.h"

void console::read_info(User & _user) {
	std::string full_name, address, phone_number, email_address;
	std::cin.ignore();
	textAndBackgroundColor(Color::LIGHT_YELLOW);
	std::cout << "    Nhap thong tin tai khoan" << std::endl;
	textAndBackgroundColor(Color::LIGHT_AQUA);
	std::cout << "\tNhap ho ten: ";
	textAndBackgroundColor(Color::BRIGHT_WHITE);
	getline(std::cin, full_name);
	textAndBackgroundColor(Color::LIGHT_AQUA);
	std::cout << "\tNhap dia chi: ";
	textAndBackgroundColor(Color::BRIGHT_WHITE);
	getline(std::cin, address);
	textAndBackgroundColor(Color::LIGHT_AQUA);
	std::cout << "\tNhap so dien thoai: ";
	textAndBackgroundColor(Color::BRIGHT_WHITE);
	getline(std::cin, phone_number);
	textAndBackgroundColor(Color::LIGHT_AQUA);
	std::cout << "\tNhap dia chi email: ";
	textAndBackgroundColor(Color::BRIGHT_WHITE);
	getline(std::cin, email_address);
	_user.set_full_name(full_name);
	_user.set_address(address);
	_user.set_phone_number(phone_number);
	_user.set_email_address(email_address);
}

void console::write_info(User _user) {
	textAndBackgroundColor(Color::LIGHT_AQUA);
	std::cout << "\tHo ten: ";
	textAndBackgroundColor(Color::BRIGHT_WHITE);
	std::cout << _user.get_full_name() << std::endl;
	textAndBackgroundColor(Color::LIGHT_AQUA);
	std::cout << "\tDia chi: ";
	textAndBackgroundColor(Color::BRIGHT_WHITE);
	std::cout << _user.get_address() << std::endl;
	textAndBackgroundColor(Color::LIGHT_AQUA);
	std::cout << "\tSo dien thoai: ";
	textAndBackgroundColor(Color::BRIGHT_WHITE);
	std::cout << _user.get_phone_number() << std::endl;
	textAndBackgroundColor(Color::LIGHT_AQUA);
	std::cout << "\tDia chi email: ";
	textAndBackgroundColor(Color::BRIGHT_WHITE);
	std::cout << _user.get_email_address() << std::endl;
}
