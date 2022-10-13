#include <iostream>
#include <string>
#include "CUser.h"
#include "CAdministrator.h"
#include "CEmployee.h"
#include "UIHaveNoUX.h"
#include "HandleMiscellaneous.h"

using namespace std;

void check(CUser & temp) {
	temp.setPassword("hmmmm");
}

int main() {
	//CEmployee tempEmployee("Ng Van A", "280 ADV", "90910290", "ahsdj@mail.com", "", ""), tempAd;
	//tempAd = tempEmployee;
	//check(tempEmployee);
	//textAndBackgroundColor(1, 3);
	//cout << tempEmployee.getPassword() << endl;
	//textAndBackgroundColor(7, 0);
	//tempEmployee.output();

	string strTemp;
	encodePassword(strTemp);
	cout << strTemp;

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
