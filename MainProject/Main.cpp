#include "User.h"
#include "Administrator.h"
#include "Employee.h"
#include "HandleMain.h"
#include "HandleMiscellaneous.h"
#include "HandleWindow.h"
#include "HandleConsole.h"
#include "UIHaveNoUX.h"
#include "Config.h"

char g_cCatchEvent;
bool g_bBreakLoop = true;
std::string strUsernameTemp, strPasswordTemp;

void handleAdmin();
void handleEmployee(std::string strUsername, std::string strPassword);

int main() {
	SetConsoleTitle(L"Employee management");
	console::resize(1920, 1080);// 377
	console::move_to::center();
	//form_login(strUsernameTemp, strPasswordTemp);
	//std::cout << std::endl;
	//std::cout << strUsernameTemp << std::endl;
	//std::cout << "Password: ";
	//encode_password(strPasswordTemp);
	//std::cout << strPasswordTemp << std::endl;

	//form_info(
	//	L"Enter your information",
	//	{ L"Full name:",
	//	  L"Address:",
	//	  L"Phone number:",
	//	  L"Email address:" },
	//	box::BorderStyle::CORNER_DOUBLE
	//);

	//show_info_accounts();

	//while (true) {
	//	console::resize(450, 550);
	//	console::move_to::center();
	//	strUsernameTemp.clear();
	//	strPasswordTemp.clear();
	//	form_login(strUsernameTemp, strPasswordTemp);
	//	AccountType account_type = check_account_type(strUsernameTemp, strPasswordTemp);
	//	switch (account_type) {
	//	case AccountType::ADMINISTRATOR:
	//		handleAdmin();
	//		break;
	//	case AccountType::EMPLOYEE:
	//		handleEmployee(strUsernameTemp, strPasswordTemp);
	//		break;
	//	default:
	//		std::cout << std::endl;
	//		warning("Sai tai khoan hoac mat khau!!!");
	//		break;
	//	}
	//}

	//while (true) {
	//	console::resize(370, 475);
	//	g_cCatchEvent = chooseAdminOrEmployee();
	//	int iEmployeeMaxLogin = 3;
	//	switch (g_cCatchEvent) {
	//	case 49:
	//		g_bBreakLoop = false;
	//		while (true) {
	//			console::resize(380, 475);
	//			strUsernameTemp.clear();
	//			strPasswordTemp.clear();
	//			loginAdmin(strUsernameTemp, strPasswordTemp);
	//			if (hasAccount(ACCOUNTS_FILE, strUsernameTemp, strPasswordTemp)) {
	//				handleAdmin();
	//				g_bBreakLoop = true;
	//			}
	//			else warning("Sai tai khoan hoac mat khau!!!");
	//			if (g_bBreakLoop) break;
	//		}
	//		break;
	//	case 50:
	//		g_bBreakLoop = false;
	//		while (true) {
	//			console::resize(380, 475);
	//			strUsernameTemp.clear();
	//			strPasswordTemp.clear();
	//			loginEmployees(strUsernameTemp, strPasswordTemp, iEmployeeMaxLogin);
	//			std::cout << std::endl;
	//			if (hasAccount(ACCOUNTS_FILE, strUsernameTemp, strPasswordTemp) && iEmployeeMaxLogin != 0) {
	//				if (strPasswordTemp == "111111") {
	//					std::string strNewPass, strConfirmNewPass;
	//					Employee employee;
	//					system("cls");
	//					textAndBackgroundColor(Color::LIGHT_YELLOW);
	//					std::cout << "<Doi mat khau mac dinh>" << std::endl;
	//					std::cout << "(Mat khau mac dinh la: 111111)" << std::endl;
	//					textAndBackgroundColor(Color::LIGHT_BLUE);
	//					std::cout << "Nhap mat khau moi: ";
	//					textAndBackgroundColor(Color::BRIGHT_WHITE);
	//					encodePassword(strNewPass);
	//					std::cout << std::endl;
	//					textAndBackgroundColor(Color::LIGHT_BLUE);
	//					std::cout << "Nhap xac nhan mat khau moi: ";
	//					textAndBackgroundColor(Color::BRIGHT_WHITE);
	//					encodePassword(strConfirmNewPass);
	//					std::cout << std::endl;
	//					if (employee.isSuccessChangePass(strUsernameTemp, "111111", strNewPass, strConfirmNewPass)) {
	//						strNewPass.clear();
	//						strConfirmNewPass.clear();
	//						textAndBackgroundColor(Color::LIGHT_RED);
	//						std::cout << "Cap nhat thanh cong!!!" << std::endl;
	//						system("pause");
	//						handleEmployee(strUsernameTemp, strPasswordTemp);
	//					}
	//					else {
	//						warning("Sai thong tin!!!");
	//					}
	//					g_bBreakLoop = true;
	//				}
	//				else {
	//					handleEmployee(strUsernameTemp, strPasswordTemp);
	//					g_bBreakLoop = true;
	//				}
	//			}
	//			else {
	//				iEmployeeMaxLogin--;
	//				warning("Sai tai khoan hoac mat khau!!!");
	//				if (iEmployeeMaxLogin == 0)
	//					break;
	//			}
	//			if (g_bBreakLoop) break;
	//		}
	//		break;
	//	default:
	//		warning("Lua chon khong hop le!!!");
	//		break;
	//	}
	//}

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
		console::resize(435, 475);
		g_cCatchEvent = menuAdmin();
		switch (g_cCatchEvent) {
		case 49:
			system("cls");
			console::resize(650, 475);
			textAndBackgroundColor(Color::LIGHT_YELLOW);
			std::cout << "<Them Employees>" << std::endl;
			textAndBackgroundColor(Color::LIGHT_RED);
			std::cout << "Ten tai khoan khong duoc co khoang cach" << std::endl;
			textAndBackgroundColor(Color::LIGHT_BLUE);
			std::cout << "    Nhap ten tai khoan muon them: ";
			textAndBackgroundColor(Color::BRIGHT_WHITE);
			std::cin >> strUsernameTemp;
			if (hasUsername(ACCOUNTS_FILE, strUsernameTemp))
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
			if (hasUsername(ACCOUNTS_FILE, strUsernameTemp)) {
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
			console::resize(550, 475);
			textAndBackgroundColor(Color::LIGHT_YELLOW);
			std::cout << "<Tim Employees>" << std::endl;
			textAndBackgroundColor(Color::LIGHT_RED);
			std::cout << "Ten tai khoan khong duoc co khoang cach" << std::endl;
			textAndBackgroundColor(Color::LIGHT_BLUE);
			std::cout << "    Nhap ten tai khoan muon tim: ";
			textAndBackgroundColor(Color::BRIGHT_WHITE);
			strUsernameTemp.clear();
			std::cin >> strUsernameTemp;
			if (hasUsername(ACCOUNTS_FILE, strUsernameTemp)) {
				textAndBackgroundColor(Color::LIGHT_YELLOW);
				std::cout << "    Thong tin Employee can tim: " << std::endl;
				showAccountInfo(strUsernameTemp);
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
			if (hasUsername(ACCOUNTS_FILE, strUsernameTemp)) {
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
			console::resize(1275, 500);
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
		console::resize(435, 475);
		g_cCatchEvent = menuEmployee();
		switch (g_cCatchEvent) {
		case 49:
			console::resize(535, 475);
			system("cls");
			textAndBackgroundColor(Color::LIGHT_YELLOW);
			std::cout << "<Thong tin tai khoan>" << std::endl;
			textAndBackgroundColor(Color::YELLOW);
			std::cout << "    Ten tai khoan: ";
			textAndBackgroundColor(Color::BRIGHT_WHITE);
			std::cout << strUsername << std::endl;
			showAccountInfo(strUsername);
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