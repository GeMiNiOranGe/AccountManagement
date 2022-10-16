#include <iostream>
#include "CUser.h"
#include "CAdministrator.h"
#include "CEmployee.h"
#include "UIHaveNoUX.h"
#include "HandleMiscellaneous.h"

using namespace std;

char g_cCatchEvent;

void handleAdmin();
void handleEmployee();

int main() {
	SetConsoleTitle(L"Employee manager - Group ProCoder");
	resizeConsole(435, 475);
	string strPasswordTemp, strUsernameTemp;
	while (true) {
		g_cCatchEvent = chooseAdminOrEmployee();
		switch (g_cCatchEvent) {
		case 49:
			//TODO: should clear strPasswordTemp when re-login
			loginAdmin(strUsernameTemp, strPasswordTemp);
			handleAdmin();
			break;
		case 50:
			handleEmployee();
			break;
		default:
			chooseWrong();
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
	g_cCatchEvent = menuAdmin();
	switch (g_cCatchEvent) {
	case 49:
		break;
	case 50:
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
		chooseWrong();
		break;
	}
}

void handleEmployee() {
	g_cCatchEvent = menuEmployee();
	switch (g_cCatchEvent) {
	case 49:
		break;
	case 50:
		break;
	case 51:
		break;
	default:
		chooseWrong();
		break;
	}
}