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
	SetConsoleTitle(L"Employee manager - Group ProCoder");
	while (true) {
		resizeConsole(370, 475);
		g_cCatchEvent = chooseAdminOrEmployee();
		resizeConsole(380, 475);
		switch (g_cCatchEvent) {
		case 49:
			g_bBreakLoop = false;
			while (true) {
				strUsernameTemp.clear();
				strPasswordTemp.clear();
				loginAdmin(strUsernameTemp, strPasswordTemp);
				if (hasAccount(ADMINISTRATOR_FILE, strUsernameTemp, strPasswordTemp)) {
					resizeConsole(435, 475);
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
				strUsernameTemp.clear();
				strPasswordTemp.clear();
				loginEmployees(strUsernameTemp, strPasswordTemp);
				if (hasAccount(EMPLOYEES_FILE, strUsernameTemp, strPasswordTemp)) {
					resizeConsole(435, 475);
					handleEmployee(strUsernameTemp, strPasswordTemp);
					g_bBreakLoop = true;
				}
				else warning("Sai tai khoan hoac mat khau!!!");
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
		g_cCatchEvent = menuAdmin();
		switch (g_cCatchEvent) {
		case 49:
			textAndBackgroundColor(14, 0);
			cout << endl << "<Them Employees>" << endl;
			textAndBackgroundColor(12, 0);
			cout << "Ten tai khoan khong duoc co khoang cach" << endl;
			textAndBackgroundColor(9, 0);
			cout << "    Nhap ten tai khoan muon them: ";
			textAndBackgroundColor(15, 0);
			cin >> strUsernameTemp;
			//check strUsername in file Employees.txt
			if (hasUsername(EMPLOYEES_FILE, strUsernameTemp))
				warning("Ten tai khoan da ton tai!!!");
			else {
				admin.addEmployee(strUsernameTemp);
				textAndBackgroundColor(12, 0);
				cout << "Them thanh cong!!!" << endl;
				system("pause");
			}
			break;
		case 50:
			textAndBackgroundColor(14, 0);
			cout << endl << "<Xoa Employees>" << endl;
			textAndBackgroundColor(12, 0);
			cout << "Ten tai khoan khong duoc co khoang cach" << endl;
			textAndBackgroundColor(9, 0);
			cout << "    Nhap ten tai khoan muon xoa: ";
			textAndBackgroundColor(15, 0);
			strUsernameTemp.clear();
			cin >> strUsernameTemp;
			if (hasUsername(EMPLOYEES_FILE, strUsernameTemp)) {
				admin.eraseEmployee(strUsernameTemp);
				textAndBackgroundColor(12, 0);
				cout << "Xoa thanh cong!!!" << endl;
				system("pause");
			}
			else
				warning("Khong tim thay \"" + strUsernameTemp + "\" de xoa!!!");
			break;
		case 51:
			textAndBackgroundColor(14, 0);
			cout << endl << "<Tim Employees>" << endl;
			textAndBackgroundColor(12, 0);
			cout << "Ten tai khoan khong duoc co khoang cach" << endl;
			textAndBackgroundColor(9, 0);
			cout << "    Nhap ten tai khoan muon tim: ";
			textAndBackgroundColor(15, 0);
			strUsernameTemp.clear();
			cin >> strUsernameTemp;
			if (hasUsername(EMPLOYEES_FILE, strUsernameTemp)) {
				textAndBackgroundColor(14, 0);
				cout << "    Thong tin Employee can tim: " << endl;
				showAccountInfo(strUsernameTemp);
				system("pause");
			}
			else
				warning("Khong tim thay \"" + strUsernameTemp + "\"!!!");
			break;
		case 52:
			textAndBackgroundColor(14, 0);
			cout << endl << "<Cap nhat thong tin Employees>" << endl;
			textAndBackgroundColor(9, 0);
			cout << "Nhap ten tai khoan can cap nhat: ";
			strUsernameTemp.clear();
			cin >> strUsernameTemp;
			if (hasUsername(EMPLOYEES_FILE, strUsernameTemp)) {
				while (true) {
					g_cCatchEvent = menuUpdateInfo();
					if (48 < g_cCatchEvent && g_cCatchEvent < 53) {
						cout << "Cap nhat thong tin o lua chon: " << g_cCatchEvent - 48 << endl;
						cout << "Thong tin moi se duoc cap nhat: ";
						cin.ignore();
						getline(cin, strInfoUpdated);
						admin.updateInfoEmployee(strUsernameTemp, strInfoUpdated, g_cCatchEvent);
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
			resizeConsole(1200, 500);
			textAndBackgroundColor(14, 0);
			cout << "<Hien thi thong tin toan bo Employees>" << endl;
			textAndBackgroundColor(15, 0);
			admin.showInfoAllEmployee();
			system("pause");
			resizeConsole(380, 475);
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
	CEmployee employee;
	while (true) {
		g_cCatchEvent = menuEmployee();
		switch (g_cCatchEvent) {
		case 49:
			textAndBackgroundColor(14, 0);
			cout << endl << "<Thong tin tai khoan>" << endl;
			textAndBackgroundColor(6, 0);
			cout << "Ten tai khoan: ";
			textAndBackgroundColor(15, 0);
			cout << strUsername << endl;
			showAccountInfo(strUsername);
			system("pause");
			break;
		case 50:
			break;
		case 51:
			return;
		default:
			warning("Lua chon khong hop le!!!");
			break;
		}
	}
}