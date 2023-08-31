#include "Administrator.h"
#include "Employee.h"
#include "HandleConsole.h"
#include "UIHaveNoUX.h"

void administrator_interface();
void employee_interface(std::string _username, std::string _password);

int main() {
	SetConsoleTitle(L"Employee management");
	//console::resize(1920, 1080);// 377
	//console::move_to::center();

	// form_info(
	// 	L"Enter your information",
	// 	{ L"Full name:",
	// 	  L"Address:",
	// 	  L"Phone number:",
	// 	  L"Email address:" },
	// 	box::BorderStyle::CORNER_DOUBLE
	// );

	//show_info_accounts();

	int number_of_login = 3;
	while (true) {
		console::resize(350, 400);
		console::move_to::center();
		bool is_logged_in = true;

		auto account = form_login();
		AccountType account_type = get_account_type(account.first, account.second);

		if (is_default_password(account.first, account.second)) {
			std::string new_password, confirm_new_password;
			Employee employee;
			system("cls");
			set_color(Color::LIGHT_YELLOW);
			std::cout << "<Doi mat khau mac dinh>" << std::endl;
			std::cout << "(Mat khau mac dinh la: " + DEFAULT_PASSWORD + ")" << std::endl;
			set_color(Color::LIGHT_BLUE);
			std::cout << "Nhap mat khau moi: ";
			set_color(Color::BRIGHT_WHITE);
			encode_password(new_password);
			std::cout << std::endl;
			set_color(Color::LIGHT_BLUE);
			std::cout << "Nhap xac nhan mat khau moi: ";
			set_color(Color::BRIGHT_WHITE);
			encode_password(confirm_new_password);
			std::cout << std::endl;
			if (employee.is_success_change_pass(account.first, DEFAULT_PASSWORD, new_password, confirm_new_password)) {
				new_password.clear();
				confirm_new_password.clear();
				set_color(Color::LIGHT_RED);
				std::cout << "Cap nhat thanh cong!!!" << std::endl;
				system("pause");
			}
			else {
				warning("Sai thong tin!!!");
				is_logged_in = false;
			}
		}

		if (is_logged_in)
			switch (account_type) {
			case AccountType::ADMINISTRATOR:
				administrator_interface();
				break;
			case AccountType::EMPLOYEE:
				employee_interface(account.first, account.second);
				break;
			default:
				number_of_login--;
				std::cout << "So lan dang nhap con lai: " << number_of_login << std::endl;
				std::cout << std::endl;
				warning("Sai tai khoan hoac mat khau!!!");
				break;
			}

		if (number_of_login == 0)
			break;
	}

	//char key_press;
	//int ascii_value;
	//cout << "\n\t\tNhap phim bat ky de kiem tra ma ASCII\n\t\t\An ESC de thoat\n\n\n";
	//while (1) {
	//	key_press = _getch();
	//	ascii_value = key_press;
	//	if (ascii_value == 27) // For ESC
	//		break;
	//	cout << "Ban nhap phim-> \" " << key_press << " \" Gia tri ASCII =  " << ascii_value << "\n";
	//}
	return 0;
}

void administrator_interface() {
	Administrator admin;
	std::string strInfoUpdated, username;
	char event;
	while (true) {
		console::resize(500, 500);
		console::move_to::center();
		event = menu_options(
			L"< MENU ADMINISTRATOR >",
			{ L"Add employee account",
			  L"Delete employee account",
			  L"Search employee account",
			  L"Edit employee account",
			  L"Display employee account information",
			  L"Log out" }
		);

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
			if (has_username(username))
				warning("Ten tai khoan da ton tai!!!");
			else {
				admin.add_employee(username);
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
			if (has_username(username)) {
				admin.erase_employee(username);
				set_color(Color::LIGHT_RED);
				std::cout << "Xoa thanh cong!!!" << std::endl;
				system("pause");
			}
			else
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
			if (has_username(username)) {
				set_color(Color::LIGHT_YELLOW);
				std::cout << "    Thong tin Employee can tim: " << std::endl;
				show_account_info(username);
				system("pause");
			}
			else
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
			if (has_username(username)) {
				while (true) {
					event = menu_options(
						L"< Select the information to edit >",
						{ L"Full name",
						  L"Address",
						  L"Phone number",
						  L"Email address" },
						{ L"<ESC> de huy bo" }
					);

					if (48 < event && event < 53) {
						set_color(Color::LIGHT_BLUE);
						std::cout << "Cap nhat thong tin o lua chon: ";
						set_color(Color::BRIGHT_WHITE);
						std::cout << event - 48 << std::endl;
						set_color(Color::LIGHT_BLUE);
						std::cout << "Thong tin moi se duoc cap nhat: ";
						set_color(Color::BRIGHT_WHITE);
						std::cin.ignore();
						getline(std::cin, strInfoUpdated);
						admin.update_info_employee(username, strInfoUpdated, event);
						set_color(Color::LIGHT_RED);
						std::cout << "Cap nhat thanh cong!!!" << std::endl;
						system("pause");
					}
					else if (event == 27)
						break;
					else
						warning("Lua chon khong hop le!!!");
				}
			}
			else
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

void employee_interface(std::string _username, std::string _password) {
	std::string current_password, new_password, current_new_password;
	Employee employee;
	char event;
	while (true) {
		console::resize(500, 500);
		console::move_to::center();
		event = menu_options(
			L"< MENU EMPLOYEE >",
			{ L"View account information",
			  L"Change password",
			  L"Log out" }
		);

		switch (event) {
		case 49:
			system("cls");
			set_color(Color::LIGHT_YELLOW);
			std::cout << "<Thong tin tai khoan>" << std::endl;
			set_color(Color::YELLOW);
			std::cout << "    Ten tai khoan: ";
			set_color(Color::BRIGHT_WHITE);
			std::cout << _username << std::endl;
			show_account_info(_username);
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
			std::cout << "Nhap xac nhan mat khau moi: ";
			set_color(Color::BRIGHT_WHITE);
			encode_password(current_new_password);
			std::cout << std::endl;
			if (employee.is_success_change_pass(_username, current_password, new_password, current_new_password)) {
				current_password.clear();
				new_password.clear();
				current_new_password.clear();
				set_color(Color::LIGHT_RED);
				std::cout << "Cap nhat thanh cong!!!" << std::endl;
				system("pause");
			}
			else
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