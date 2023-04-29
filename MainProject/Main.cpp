#include "CUser.h"
#include "CAdministrator.h"
#include "CEmployee.h"
#include "HandleMain.h"
#include "HandleMiscellaneous.h"
#include "UIHaveNoUX.h"
#include "Config.h"

char g_cCatchEvent;
bool g_bBreakLoop = true;
std::string strUsernameTemp, strPasswordTemp;

void handleAdmin();
void handleEmployee(std::string strUsername, std::string strPassword);

//window-and-screen-buffer-size
//void MoveWindow(int posx, int posy) {
//	RECT rectClient, rectWindow;
//	HWND hWnd = GetConsoleWindow();
//	GetClientRect(hWnd, &rectClient);
//	GetWindowRect(hWnd, &rectWindow);
//	MoveWindow(hWnd, posx, posy, rectClient.right - rectClient.left, rectClient.bottom - rectClient.top, TRUE);
//}
//
//void MoveCenter() {
//	RECT rectClient, rectWindow;
//	HWND hWnd = GetConsoleWindow();
//	GetClientRect(hWnd, &rectClient);
//	GetWindowRect(hWnd, &rectWindow);
//	int posx, posy;
//	posx = GetSystemMetrics(SM_CXSCREEN) / 2 - (rectWindow.right - rectWindow.left) / 2,
//		posy = GetSystemMetrics(SM_CYSCREEN) / 2 - (rectWindow.bottom - rectWindow.top) / 2,
//
//		MoveWindow(hWnd, posx, posy, rectClient.right - rectClient.left, rectClient.bottom - rectClient.top, TRUE);
//}
//
//int main(int argc, char * argv[]) {
//	//MoveWindow(10, 10);
//	MoveCenter();
//	return 0;
//}

int main() {
	SetConsoleTitle(L"Employee manager");

	//resizeConsole(377, 300);// 377
	//formLogin(strUsernameTemp, strPasswordTemp);
	//cout << strUsernameTemp << endl;
	//cout << strPasswordTemp << endl;

	//std::cout << "le, le, chan" << std::endl;
	//formInfo(15, 25, L"<Enter your information>");

	//std::string s2 = "asd";
	//std::string s3 = "hmm";
	//std::string s4 = "nahnah";
	//showInfoAnAccount(
	//	Color::Blue,
	//	L'─',
	//	std::make_tuple(s1.size(), s1),
	//	std::make_tuple(s2.size(), s2),
	//	std::make_tuple(s3.size(), s3),
	//	std::make_tuple(s4.size(), s4)
	//);

	showInfoAccounts();

	//while (true) {
	//	string strTypeAccount = formLogin(strUsernameTemp, strPasswordTemp);
	//	if (strTypeAccount == "admin") {
	//	}
	//}

	//while (true) {
	//	resizeConsole(405, 300);
	//	strUsernameTemp.clear();
	//	strPasswordTemp.clear();
	//	formLogin(strUsernameTemp, strPasswordTemp);
	//	std::string strTypeAccount = checkTypeAccount(strUsernameTemp, strPasswordTemp);
	//	if (strTypeAccount == "admin") {
	//		handleAdmin();
	//	}
	//	if (strTypeAccount == "employee") {
	//		handleEmployee(strUsernameTemp, strPasswordTemp);
	//	}
	//	if (strTypeAccount == "") {
	//		std::cout << std::endl;
	//		warning("Sai tai khoan hoac mat khau!!!");
	//	}
	//}

	//while (true) {
	//	resizeConsole(370, 475);
	//	g_cCatchEvent = chooseAdminOrEmployee();
	//	int iEmployeeMaxLogin = 3;
	//	switch (g_cCatchEvent) {
	//	case 49:
	//		g_bBreakLoop = false;
	//		while (true) {
	//			resizeConsole(380, 475);
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
	//			resizeConsole(380, 475);
	//			strUsernameTemp.clear();
	//			strPasswordTemp.clear();
	//			loginEmployees(strUsernameTemp, strPasswordTemp, iEmployeeMaxLogin);
	//			cout << endl;
	//			if (hasAccount(ACCOUNTS_FILE, strUsernameTemp, strPasswordTemp) && iEmployeeMaxLogin != 0) {
	//				if (strPasswordTemp == "111111") {
	//					string strNewPass, strConfirmNewPass;
	//					CEmployee employee;
	//					system("cls");
	//					textAndBackgroundColor(Color::LightYellow, Color::Black);
	//					cout << "<Doi mat khau mac dinh>" << endl;
	//					cout << "(Mat khau mac dinh la: 111111)" << endl;
	//					textAndBackgroundColor(Color::LightBlue, Color::Black);
	//					cout << "Nhap mat khau moi: ";
	//					textAndBackgroundColor(Color::BrightWhite, Color::Black);
	//					encodePassword(strNewPass);
	//					cout << endl;
	//					textAndBackgroundColor(Color::LightBlue, Color::Black);
	//					cout << "Nhap xac nhan mat khau moi: ";
	//					textAndBackgroundColor(Color::BrightWhite, Color::Black);
	//					encodePassword(strConfirmNewPass);
	//					cout << endl;
	//					if (employee.isSuccessChangePass(strUsernameTemp, "111111", strNewPass, strConfirmNewPass)) {
	//						strNewPass.clear();
	//						strConfirmNewPass.clear();
	//						textAndBackgroundColor(Color::LightRed, Color::Black);
	//						cout << "Cap nhat thanh cong!!!" << endl;
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
	CAdministrator admin;
	std::string strInfoUpdated;
	while (true) {
		resizeConsole(435, 475);
		g_cCatchEvent = menuAdmin();
		switch (g_cCatchEvent) {
		case 49:
			system("cls");
			resizeConsole(650, 475);
			textAndBackgroundColor(Color::LightYellow, Color::Black);
			std::cout << "<Them Employees>" << std::endl;
			textAndBackgroundColor(Color::LightRed, Color::Black);
			std::cout << "Ten tai khoan khong duoc co khoang cach" << std::endl;
			textAndBackgroundColor(Color::LightBlue, Color::Black);
			std::cout << "    Nhap ten tai khoan muon them: ";
			textAndBackgroundColor(Color::BrightWhite, Color::Black);
			std::cin >> strUsernameTemp;
			if (hasUsername(ACCOUNTS_FILE, strUsernameTemp))
				warning("Ten tai khoan da ton tai!!!");
			else {
				admin.addEmployee(strUsernameTemp);
				textAndBackgroundColor(Color::LightRed, Color::Black);
				std::cout << "Them thanh cong!!!" << std::endl;
				system("pause");
			}
			break;
		case 50:
			system("cls");
			textAndBackgroundColor(Color::LightYellow, Color::Black);
			std::cout << "<Xoa Employees>" << std::endl;
			textAndBackgroundColor(Color::LightRed, Color::Black);
			std::cout << "Ten tai khoan khong duoc co khoang cach" << std::endl;
			textAndBackgroundColor(Color::LightBlue, Color::Black);
			std::cout << "    Nhap ten tai khoan muon xoa: ";
			textAndBackgroundColor(Color::BrightWhite, Color::Black);
			strUsernameTemp.clear();
			std::cin >> strUsernameTemp;
			if (hasUsername(ACCOUNTS_FILE, strUsernameTemp)) {
				admin.eraseEmployee(strUsernameTemp);
				textAndBackgroundColor(Color::LightRed, Color::Black);
				std::cout << "Xoa thanh cong!!!" << std::endl;
				system("pause");
			}
			else
				warning("Khong tim thay \"" + strUsernameTemp + "\" de xoa!!!");
			break;
		case 51:
			system("cls");
			resizeConsole(550, 475);
			textAndBackgroundColor(Color::LightYellow, Color::Black);
			std::cout << "<Tim Employees>" << std::endl;
			textAndBackgroundColor(Color::LightRed, Color::Black);
			std::cout << "Ten tai khoan khong duoc co khoang cach" << std::endl;
			textAndBackgroundColor(Color::LightBlue, Color::Black);
			std::cout << "    Nhap ten tai khoan muon tim: ";
			textAndBackgroundColor(Color::BrightWhite, Color::Black);
			strUsernameTemp.clear();
			std::cin >> strUsernameTemp;
			if (hasUsername(ACCOUNTS_FILE, strUsernameTemp)) {
				textAndBackgroundColor(Color::LightYellow, Color::Black);
				std::cout << "    Thong tin Employee can tim: " << std::endl;
				showAccountInfo(strUsernameTemp);
				system("pause");
			}
			else
				warning("Khong tim thay \"" + strUsernameTemp + "\"!!!");
			break;
		case 52:
			system("cls");
			textAndBackgroundColor(Color::LightYellow, Color::Black);
			std::cout << "<Cap nhat thong tin Employees>" << std::endl;
			textAndBackgroundColor(Color::LightBlue, Color::Black);
			std::cout << "Nhap ten tai khoan can cap nhat: ";
			textAndBackgroundColor(Color::BrightWhite, Color::Black);
			strUsernameTemp.clear();
			std::cin >> strUsernameTemp;
			if (hasUsername(ACCOUNTS_FILE, strUsernameTemp)) {
				while (true) {
					g_cCatchEvent = menuUpdateInfo();
					if (48 < g_cCatchEvent && g_cCatchEvent < 53) {
						textAndBackgroundColor(Color::LightBlue, Color::Black);
						std::cout << "Cap nhat thong tin o lua chon: ";
						textAndBackgroundColor(Color::BrightWhite, Color::Black);
						std::cout << g_cCatchEvent - 48 << std::endl;
						textAndBackgroundColor(Color::LightBlue, Color::Black);
						std::cout << "Thong tin moi se duoc cap nhat: ";
						textAndBackgroundColor(Color::BrightWhite, Color::Black);
						std::cin.ignore();
						getline(std::cin, strInfoUpdated);
						admin.updateInfoEmployee(strUsernameTemp, strInfoUpdated, g_cCatchEvent);
						textAndBackgroundColor(Color::LightRed, Color::Black);
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
			resizeConsole(1275, 500);
			textAndBackgroundColor(Color::LightYellow, Color::Black);
			std::cout << "<Hien thi thong tin toan bo Employees>" << std::endl;
			textAndBackgroundColor(Color::BrightWhite, Color::Black);
			admin.showInfoAllEmployee();
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
	CEmployee employee;
	while (true) {
		resizeConsole(435, 475);
		g_cCatchEvent = menuEmployee();
		switch (g_cCatchEvent) {
		case 49:
			resizeConsole(535, 475);
			system("cls");
			textAndBackgroundColor(Color::LightYellow, Color::Black);
			std::cout << "<Thong tin tai khoan>" << std::endl;
			textAndBackgroundColor(Color::Yellow, Color::Black);
			std::cout << "    Ten tai khoan: ";
			textAndBackgroundColor(Color::BrightWhite, Color::Black);
			std::cout << strUsername << std::endl;
			showAccountInfo(strUsername);
			system("pause");
			system("cls");
			break;
		case 50:
			system("cls");
			textAndBackgroundColor(Color::LightYellow, Color::Black);
			std::cout << "<Doi mat khau>" << std::endl;
			textAndBackgroundColor(Color::LightBlue, Color::Black);
			std::cout << "Nhap mat khau hien tai: ";
			textAndBackgroundColor(Color::BrightWhite, Color::Black);
			encodePassword(strCurrentPass);
			std::cout << std::endl;
			textAndBackgroundColor(Color::LightBlue, Color::Black);
			std::cout << "Nhap mat khau moi: ";
			textAndBackgroundColor(Color::BrightWhite, Color::Black);
			encodePassword(strNewPass);
			std::cout << std::endl;
			textAndBackgroundColor(Color::LightBlue, Color::Black);
			std::cout << "Nhap xac nhan mat khau moi: ";
			textAndBackgroundColor(Color::BrightWhite, Color::Black);
			encodePassword(strConfirmNewPass);
			std::cout << std::endl;
			if (employee.isSuccessChangePass(strUsername, strCurrentPass, strNewPass, strConfirmNewPass)) {
				strCurrentPass.clear();
				strNewPass.clear();
				strConfirmNewPass.clear();
				textAndBackgroundColor(Color::LightRed, Color::Black);
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