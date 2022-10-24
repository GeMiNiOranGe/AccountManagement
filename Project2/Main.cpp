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

void handleAdmin();
void handleEmployee();

int main() {
	SetConsoleTitle(L"Employee manager - Group ProCoder");
	resizeConsole(435, 475);
	string strUsernameTemp, strPasswordTemp;
	//CUser *userTemp = new CAdministrator;
	//cin >> strUsernameTemp;
	//deleteFile(strUsernameTemp);
	//ifstream fileOut = openFile(strUsernameTemp);
	//userTemp->readInfo(fileOut);
	//userTemp->output();

	while (true) {
		g_cCatchEvent = chooseAdminOrEmployee();
		switch (g_cCatchEvent) {
		case 49:
			//TODO: should clear strPasswordTemp when re-login
			while (true) {
				strUsernameTemp.clear();
				strPasswordTemp.clear();
				loginAdmin(strUsernameTemp, strPasswordTemp);
				if (hasAccount<CAdministrator>(ADMINISTRATOR_FILE, strUsernameTemp, strPasswordTemp)) {
					handleAdmin();
					g_bBreakLoop = false;
				}
				else warning("Sai tai khoan hoac mat khau!!!");
				if (!g_bBreakLoop) break;
			}
			break;
		case 50:
			while (true) {
				strUsernameTemp.clear();
				strPasswordTemp.clear();
				loginEmployees(strUsernameTemp, strPasswordTemp);
				if (hasAccount<CEmployee>(EMPLOYEES_FILE, strUsernameTemp, strPasswordTemp)) {
					handleEmployee();
					g_bBreakLoop = false;
				}
				else warning("Sai tai khoan hoac mat khau!!!");
				if (!g_bBreakLoop) break;
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
	while (true) {
		g_cCatchEvent = menuAdmin();
		switch (g_cCatchEvent) {
		case 49:
			admin.addEmployee();
			break;
		case 50:
			admin.eraseEmployee();
			break;
		case 51:
			break;
		case 52:
			break;
		case 53:
			break;
		case 54:
			return;
		default:
			warning("Lua chon khong hop le!!!");
			break;
		}
	}
}

void handleEmployee() {
	CEmployee employee;
	while (true) {
		g_cCatchEvent = menuEmployee();
		switch (g_cCatchEvent) {
		case 49:
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