#include "User.h"
#include "Administrator.h"
#include "Employee.h"
#include "HandleMain.h"
#include "HandleMiscellaneous.h"
#include "HandleWindow.h"
#include "HandleConsole.h"
#include "UIHaveNoUX.h"
#include "Config.h"
#include <tuple>

char g_cCatchEvent;
std::string strUsernameTemp, strPasswordTemp;

void handleAdmin();
void handleEmployee(std::string strUsername, std::string strPassword);

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
			textAndBackgroundColor(Color::LIGHT_YELLOW);
			std::cout << "<Doi mat khau mac dinh>" << std::endl;
			std::cout << "(Mat khau mac dinh la: " + DEFAULT_PASSWORD + ")" << std::endl;
			textAndBackgroundColor(Color::LIGHT_BLUE);
			std::cout << "Nhap mat khau moi: ";
			textAndBackgroundColor(Color::BRIGHT_WHITE);
			encode_password(new_password);
			std::cout << std::endl;
			textAndBackgroundColor(Color::LIGHT_BLUE);
			std::cout << "Nhap xac nhan mat khau moi: ";
			textAndBackgroundColor(Color::BRIGHT_WHITE);
			encode_password(confirm_new_password);
			std::cout << std::endl;
			if (employee.isSuccessChangePass(account.first, DEFAULT_PASSWORD, new_password, confirm_new_password)) {
				new_password.clear();
				confirm_new_password.clear();
				textAndBackgroundColor(Color::LIGHT_RED);
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
				handleAdmin();
				break;
			case AccountType::EMPLOYEE:
				handleEmployee(account.first, account.second);
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

	while (true) {
		bool is_break = false;
		console::resize(350, 400);
		console::move_to::center();
		g_cCatchEvent = chooseAdminOrEmployee();
		int number_of_login = 3;
		switch (g_cCatchEvent) {
		case 49:
			while (true) {
				console::resize(380, 475);
				strUsernameTemp.clear();
				strPasswordTemp.clear();
				loginAdmin(strUsernameTemp, strPasswordTemp);
				if (has_account(strUsernameTemp, strPasswordTemp)) {
					handleAdmin();
					is_break = true;
				}
				else warning("Sai tai khoan hoac mat khau!!!");
				if (is_break) break;
			}
			break;
		case 50:
			while (true) {
				console::resize(380, 475);
				strUsernameTemp.clear();
				strPasswordTemp.clear();
				loginEmployees(strUsernameTemp, strPasswordTemp, number_of_login);
				std::cout << std::endl;
				if (has_account(strUsernameTemp, strPasswordTemp) && number_of_login != 0) {
					if (strPasswordTemp == DEFAULT_PASSWORD) {
						std::string strNewPass, strConfirmNewPass;
						Employee employee;
						system("cls");
						textAndBackgroundColor(Color::LIGHT_YELLOW);
						std::cout << "<Doi mat khau mac dinh>" << std::endl;
						std::cout << "(Mat khau mac dinh la: " + DEFAULT_PASSWORD + ")" << std::endl;
						textAndBackgroundColor(Color::LIGHT_BLUE);
						std::cout << "Nhap mat khau moi: ";
						textAndBackgroundColor(Color::BRIGHT_WHITE);
						encode_password(strNewPass);
						std::cout << std::endl;
						textAndBackgroundColor(Color::LIGHT_BLUE);
						std::cout << "Nhap xac nhan mat khau moi: ";
						textAndBackgroundColor(Color::BRIGHT_WHITE);
						encode_password(strConfirmNewPass);
						std::cout << std::endl;
						if (employee.isSuccessChangePass(strUsernameTemp, DEFAULT_PASSWORD, strNewPass, strConfirmNewPass)) {
							strNewPass.clear();
							strConfirmNewPass.clear();
							textAndBackgroundColor(Color::LIGHT_RED);
							std::cout << "Cap nhat thanh cong!!!" << std::endl;
							system("pause");
							handleEmployee(strUsernameTemp, strPasswordTemp);
						}
						else
							warning("Sai thong tin!!!");
					}
					else
						handleEmployee(strUsernameTemp, strPasswordTemp);
					is_break = true;
				}
				else {
					number_of_login--;
					warning("Sai tai khoan hoac mat khau!!!");
					if (number_of_login == 0)
						break;
				}
				if (is_break) break;
			}
			break;
		default:
			warning("Lua chon khong hop le!!!");
			break;
		}
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

void handleAdmin() {
	Administrator admin;
	std::string strInfoUpdated;
	while (true) {
		console::resize(500, 500);
		console::move_to::center();
		g_cCatchEvent = menu_options(
			L"< MENU ADMINISTRATOR >",
			{ L"Add employee account",
			  L"Delete employee account",
			  L"Search employee account",
			  L"Edit employee account",
			  L"Display employee account information",
			  L"Log out" }
		);

		switch (g_cCatchEvent) {
		case 49:
			system("cls");
			textAndBackgroundColor(Color::LIGHT_YELLOW);
			std::cout << "<Them Employees>" << std::endl;
			textAndBackgroundColor(Color::LIGHT_RED);
			std::cout << "Ten tai khoan khong duoc co khoang cach" << std::endl;
			textAndBackgroundColor(Color::LIGHT_BLUE);
			std::cout << "    Nhap ten tai khoan muon them: ";
			textAndBackgroundColor(Color::BRIGHT_WHITE);
			std::cin >> strUsernameTemp;
			if (has_username(strUsernameTemp))
				warning("Ten tai khoan da ton tai!!!");
			else {
				admin.add_employee(strUsernameTemp);
				textAndBackgroundColor(Color::LIGHT_RED);
				std::cout << "Them thanh cong!!!" << std::endl;
				system("pause");
			}
			break;
		case 50:
			system("cls");
			textAndBackgroundColor(Color::LIGHT_YELLOW);
			std::cout << "<Xoa Employees>" << std::endl;
			textAndBackgroundColor(Color::LIGHT_RED);
			std::cout << "Ten tai khoan khong duoc co khoang cach" << std::endl;
			textAndBackgroundColor(Color::LIGHT_BLUE);
			std::cout << "    Nhap ten tai khoan muon xoa: ";
			textAndBackgroundColor(Color::BRIGHT_WHITE);
			strUsernameTemp.clear();
			std::cin >> strUsernameTemp;
			if (has_username(strUsernameTemp)) {
				admin.erase_employee(strUsernameTemp);
				textAndBackgroundColor(Color::LIGHT_RED);
				std::cout << "Xoa thanh cong!!!" << std::endl;
				system("pause");
			}
			else
				warning("Khong tim thay \"" + strUsernameTemp + "\" de xoa!!!");
			break;
		case 51:
			system("cls");
			textAndBackgroundColor(Color::LIGHT_YELLOW);
			std::cout << "<Tim Employees>" << std::endl;
			textAndBackgroundColor(Color::LIGHT_RED);
			std::cout << "Ten tai khoan khong duoc co khoang cach" << std::endl;
			textAndBackgroundColor(Color::LIGHT_BLUE);
			std::cout << "    Nhap ten tai khoan muon tim: ";
			textAndBackgroundColor(Color::BRIGHT_WHITE);
			strUsernameTemp.clear();
			std::cin >> strUsernameTemp;
			if (has_username(strUsernameTemp)) {
				textAndBackgroundColor(Color::LIGHT_YELLOW);
				std::cout << "    Thong tin Employee can tim: " << std::endl;
				show_account_info(strUsernameTemp);
				system("pause");
			}
			else
				warning("Khong tim thay \"" + strUsernameTemp + "\"!!!");
			break;
		case 52:
			system("cls");
			textAndBackgroundColor(Color::LIGHT_YELLOW);
			std::cout << "<Cap nhat thong tin Employees>" << std::endl;
			textAndBackgroundColor(Color::LIGHT_BLUE);
			std::cout << "Nhap ten tai khoan can cap nhat: ";
			textAndBackgroundColor(Color::BRIGHT_WHITE);
			strUsernameTemp.clear();
			std::cin >> strUsernameTemp;
			if (has_username(strUsernameTemp)) {
				while (true) {
					g_cCatchEvent = menuUpdateInfo();
					if (48 < g_cCatchEvent && g_cCatchEvent < 53) {
						textAndBackgroundColor(Color::LIGHT_BLUE);
						std::cout << "Cap nhat thong tin o lua chon: ";
						textAndBackgroundColor(Color::BRIGHT_WHITE);
						std::cout << g_cCatchEvent - 48 << std::endl;
						textAndBackgroundColor(Color::LIGHT_BLUE);
						std::cout << "Thong tin moi se duoc cap nhat: ";
						textAndBackgroundColor(Color::BRIGHT_WHITE);
						std::cin.ignore();
						getline(std::cin, strInfoUpdated);
						admin.update_info_employee(strUsernameTemp, strInfoUpdated, g_cCatchEvent);
						textAndBackgroundColor(Color::LIGHT_RED);
						std::cout << "Cap nhat thanh cong!!!" << std::endl;
						system("pause");
					}
					else if (g_cCatchEvent == 27) {
						break;
					}
					else
						warning("Lua chon khong hop le!!!");
				}
			}
			else
				warning("Khong tim thay \"" + strUsernameTemp + "\"!!!");
			break;
		case 53:
			system("cls");
			console::resize(1275, 750);
			console::move_to::center();
			textAndBackgroundColor(Color::LIGHT_YELLOW);
			std::cout << "<Hien thi thong tin toan bo Employees>" << std::endl;
			textAndBackgroundColor(Color::BRIGHT_WHITE);
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

void handleEmployee(std::string strUsername, std::string strPassword) {
	std::string strCurrentPass, strNewPass, strConfirmNewPass;
	Employee employee;
	while (true) {
		console::resize(500, 500);
		console::move_to::center();
		g_cCatchEvent = menu_options(
			L"< MENU EMPLOYEE >",
			{ L"View account information",
			  L"Change password",
			  L"Log out" }
		);

		switch (g_cCatchEvent) {
		case 49:
			system("cls");
			textAndBackgroundColor(Color::LIGHT_YELLOW);
			std::cout << "<Thong tin tai khoan>" << std::endl;
			textAndBackgroundColor(Color::YELLOW);
			std::cout << "    Ten tai khoan: ";
			textAndBackgroundColor(Color::BRIGHT_WHITE);
			std::cout << strUsername << std::endl;
			show_account_info(strUsername);
			system("pause");
			system("cls");
			break;
		case 50:
			system("cls");
			textAndBackgroundColor(Color::LIGHT_YELLOW);
			std::cout << "<Doi mat khau>" << std::endl;
			textAndBackgroundColor(Color::LIGHT_BLUE);
			std::cout << "Nhap mat khau hien tai: ";
			textAndBackgroundColor(Color::BRIGHT_WHITE);
			encode_password(strCurrentPass);
			std::cout << std::endl;
			textAndBackgroundColor(Color::LIGHT_BLUE);
			std::cout << "Nhap mat khau moi: ";
			textAndBackgroundColor(Color::BRIGHT_WHITE);
			encode_password(strNewPass);
			std::cout << std::endl;
			textAndBackgroundColor(Color::LIGHT_BLUE);
			std::cout << "Nhap xac nhan mat khau moi: ";
			textAndBackgroundColor(Color::BRIGHT_WHITE);
			encode_password(strConfirmNewPass);
			std::cout << std::endl;
			if (employee.isSuccessChangePass(strUsername, strCurrentPass, strNewPass, strConfirmNewPass)) {
				strCurrentPass.clear();
				strNewPass.clear();
				strConfirmNewPass.clear();
				textAndBackgroundColor(Color::LIGHT_RED);
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