#include "CUser.h"
#include "CAdministrator.h"
#include "CEmployee.h"
#include "UIHaveNoUX.h"
#include "HandleMiscellaneous.h"
#include "HandleMain.h"
#include "Config.h"

using namespace std;

char g_cCatchEvent;
bool g_bBreakLoop = true;
string strUsernameTemp, strPasswordTemp;

void handleAdmin();
void handleEmployee(string strUsername, string strPassword);

int main() {
	SetConsoleTitle(L"Employee manager");
	//resizeConsole(377, 300);// 377
	//formLogin(strUsernameTemp, strPasswordTemp);
	//cout << strUsernameTemp << endl;
	//cout << strPasswordTemp << endl;
	while (true) {
		resizeConsole(370, 475);
		g_cCatchEvent = chooseAdminOrEmployee();
		int iEmployeeMaxLogin = 3;
		switch (g_cCatchEvent) {
		case 49:
			g_bBreakLoop = false;
			while (true) {
				resizeConsole(380, 475);
				strUsernameTemp.clear();
				strPasswordTemp.clear();
				loginAdmin(strUsernameTemp, strPasswordTemp);
				if (hasAccount(ADMINISTRATOR_FILE, strUsernameTemp, strPasswordTemp)) {
					handleAdmin();
					g_bBreakLoop = true;
				}
				else warning("Sai tai khoan hoac mat khau!!!");
				if (g_bBreakLoop) break;
			}
			break;
		case 50:
			g_bBreakLoop = false;
			while (true) {
				resizeConsole(380, 475);
				strUsernameTemp.clear();
				strPasswordTemp.clear();
				loginEmployees(strUsernameTemp, strPasswordTemp, iEmployeeMaxLogin);
				cout << endl;
				if (hasAccount(EMPLOYEES_FILE, strUsernameTemp, strPasswordTemp) && iEmployeeMaxLogin != 0) {
					if (strPasswordTemp == "111111") {
						string strNewPass, strConfirmNewPass;
						CEmployee employee;
						system("cls");
						textAndBackgroundColor(color::LightYellow, color::Black);
						cout << "<Doi mat khau mac dinh>" << endl;
						cout << "(Mat khau mac dinh la: 111111)" << endl;
						textAndBackgroundColor(color::LightBlue, color::Black);
						cout << "Nhap mat khau moi: ";
						textAndBackgroundColor(color::BrightWhite, color::Black);
						encodePassword(strNewPass);
						cout << endl;
						textAndBackgroundColor(color::LightBlue, color::Black);
						cout << "Nhap xac nhan mat khau moi: ";
						textAndBackgroundColor(color::BrightWhite, color::Black);
						encodePassword(strConfirmNewPass);
						cout << endl;
						if (employee.isSuccessChangePass(strUsernameTemp, "111111", strNewPass, strConfirmNewPass)) {
							strNewPass.clear();
							strConfirmNewPass.clear();
							textAndBackgroundColor(color::LightRed, color::Black);
							cout << "Cap nhat thanh cong!!!" << endl;
							system("pause");
							handleEmployee(strUsernameTemp, strPasswordTemp);
						}
						else {
							warning("Sai thong tin!!!");
						}
						g_bBreakLoop = true;
					}
					else {
						handleEmployee(strUsernameTemp, strPasswordTemp);
						g_bBreakLoop = true;
					}
				}
				else {
					iEmployeeMaxLogin--;
					warning("Sai tai khoan hoac mat khau!!!");
					if (iEmployeeMaxLogin == 0)
						break;
				}
				if (g_bBreakLoop) break;
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
	CAdministrator admin;
	string strInfoUpdated;
	while (true) {
		resizeConsole(435, 475);
		g_cCatchEvent = menuAdmin();
		switch (g_cCatchEvent) {
		case 49:
			system("cls");
			resizeConsole(650, 475);
			textAndBackgroundColor(color::LightYellow, color::Black);
			cout << "<Them Employees>" << endl;
			textAndBackgroundColor(color::LightRed, color::Black);
			cout << "Ten tai khoan khong duoc co khoang cach" << endl;
			textAndBackgroundColor(color::LightBlue, color::Black);
			cout << "    Nhap ten tai khoan muon them: ";
			textAndBackgroundColor(color::BrightWhite, color::Black);
			cin >> strUsernameTemp;
			if (hasUsername(EMPLOYEES_FILE, strUsernameTemp))
				warning("Ten tai khoan da ton tai!!!");
			else {
				admin.addEmployee(strUsernameTemp);
				textAndBackgroundColor(color::LightRed, color::Black);
				cout << "Them thanh cong!!!" << endl;
				system("pause");
			}
			break;
		case 50:
			system("cls");
			textAndBackgroundColor(color::LightYellow, color::Black);
			cout << "<Xoa Employees>" << endl;
			textAndBackgroundColor(color::LightRed, color::Black);
			cout << "Ten tai khoan khong duoc co khoang cach" << endl;
			textAndBackgroundColor(color::LightBlue, color::Black);
			cout << "    Nhap ten tai khoan muon xoa: ";
			textAndBackgroundColor(color::BrightWhite, color::Black);
			strUsernameTemp.clear();
			cin >> strUsernameTemp;
			if (hasUsername(EMPLOYEES_FILE, strUsernameTemp)) {
				admin.eraseEmployee(strUsernameTemp);
				textAndBackgroundColor(color::LightRed, color::Black);
				cout << "Xoa thanh cong!!!" << endl;
				system("pause");
			}
			else
				warning("Khong tim thay \"" + strUsernameTemp + "\" de xoa!!!");
			break;
		case 51:
			system("cls");
			resizeConsole(550, 475);
			textAndBackgroundColor(color::LightYellow, color::Black);
			cout << "<Tim Employees>" << endl;
			textAndBackgroundColor(color::LightRed, color::Black);
			cout << "Ten tai khoan khong duoc co khoang cach" << endl;
			textAndBackgroundColor(color::LightBlue, color::Black);
			cout << "    Nhap ten tai khoan muon tim: ";
			textAndBackgroundColor(color::BrightWhite, color::Black);
			strUsernameTemp.clear();
			cin >> strUsernameTemp;
			if (hasUsername(EMPLOYEES_FILE, strUsernameTemp)) {
				textAndBackgroundColor(color::LightYellow, color::Black);
				cout << "    Thong tin Employee can tim: " << endl;
				showAccountInfo(strUsernameTemp);
				system("pause");
			}
			else
				warning("Khong tim thay \"" + strUsernameTemp + "\"!!!");
			break;
		case 52:
			system("cls");
			textAndBackgroundColor(color::LightYellow, color::Black);
			cout << "<Cap nhat thong tin Employees>" << endl;
			textAndBackgroundColor(color::LightBlue, color::Black);
			cout << "Nhap ten tai khoan can cap nhat: ";
			textAndBackgroundColor(color::BrightWhite, color::Black);
			strUsernameTemp.clear();
			cin >> strUsernameTemp;
			if (hasUsername(EMPLOYEES_FILE, strUsernameTemp)) {
				while (true) {
					g_cCatchEvent = menuUpdateInfo();
					if (48 < g_cCatchEvent && g_cCatchEvent < 53) {
						textAndBackgroundColor(color::LightBlue, color::Black);
						cout << "Cap nhat thong tin o lua chon: ";
						textAndBackgroundColor(color::BrightWhite, color::Black);
						cout << g_cCatchEvent - 48 << endl;
						textAndBackgroundColor(color::LightBlue, color::Black);
						cout << "Thong tin moi se duoc cap nhat: ";
						textAndBackgroundColor(color::BrightWhite, color::Black);
						cin.ignore();
						getline(cin, strInfoUpdated);
						admin.updateInfoEmployee(strUsernameTemp, strInfoUpdated, g_cCatchEvent);
						textAndBackgroundColor(color::LightRed, color::Black);
						cout << "Cap nhat thanh cong!!!" << endl;
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
			textAndBackgroundColor(color::LightYellow, color::Black);
			cout << "<Hien thi thong tin toan bo Employees>" << endl;
			textAndBackgroundColor(color::BrightWhite, color::Black);
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

void handleEmployee(string strUsername, string strPassword) {
	string strCurrentPass, strNewPass, strConfirmNewPass;
	CEmployee employee;
	while (true) {
		resizeConsole(435, 475);
		g_cCatchEvent = menuEmployee();
		switch (g_cCatchEvent) {
		case 49:
			resizeConsole(535, 475);
			system("cls");
			textAndBackgroundColor(color::LightYellow, color::Black);
			cout << "<Thong tin tai khoan>" << endl;
			textAndBackgroundColor(color::Yellow, color::Black);
			cout << "    Ten tai khoan: ";
			textAndBackgroundColor(color::BrightWhite, color::Black);
			cout << strUsername << endl;
			showAccountInfo(strUsername);
			system("pause");
			system("cls");
			break;
		case 50:
			system("cls");
			textAndBackgroundColor(color::LightYellow, color::Black);
			cout << "<Doi mat khau>" << endl;
			textAndBackgroundColor(color::LightBlue, color::Black);
			cout << "Nhap mat khau hien tai: ";
			textAndBackgroundColor(color::BrightWhite, color::Black);
			encodePassword(strCurrentPass);
			cout << endl;
			textAndBackgroundColor(color::LightBlue, color::Black);
			cout << "Nhap mat khau moi: ";
			textAndBackgroundColor(color::BrightWhite, color::Black);
			encodePassword(strNewPass);
			cout << endl;
			textAndBackgroundColor(color::LightBlue, color::Black);
			cout << "Nhap xac nhan mat khau moi: ";
			textAndBackgroundColor(color::BrightWhite, color::Black);
			encodePassword(strConfirmNewPass);
			cout << endl;
			if (employee.isSuccessChangePass(strUsername, strCurrentPass, strNewPass, strConfirmNewPass)) {
				strCurrentPass.clear();
				strNewPass.clear();
				strConfirmNewPass.clear();
				textAndBackgroundColor(color::LightRed, color::Black);
				cout << "Cap nhat thanh cong!!!" << endl;
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