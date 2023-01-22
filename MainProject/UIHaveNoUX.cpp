#include "UIHaveNoUX.h"

void formLogin(string & strUsername, string & strPassword) {
	//if (hasAccount(ADMINISTRATOR_FILE, strUsername, strPassword)) {
	//	return "admin";
	//}
	//return string();
	system("cls");
	textAndBackgroundColor(color::LightYellow, color::Black);
	cout << "\t********************************" << endl;
	cout << "\t*            ";
	textAndBackgroundColor(color::LightGreen, color::Black);
	cout << "LOG IN            ";
	textAndBackgroundColor(color::LightYellow, color::Black);
	cout << "*" << endl;
	cout << "\t********************************" << endl;
	cout << "\tUser: " << endl;
	cout << "\tPass: " << endl;
	textAndBackgroundColor(color::White, color::Black);
	gotoXY(14, 3);
	getline(cin, strUsername);
	gotoXY(14, 4);
	encodePassword(strPassword);
	cout << endl;
}

char chooseAdminOrEmployee() {
	system("cls");
	textAndBackgroundColor(color::LightRed, color::Black);
	cout << "\t+------------------------+" << endl;
	cout << "\t| 1. Dang Nhap ADMIN     |" << endl;
	cout << "\t| 2. Dang Nhap EMPLOYEES |" << endl;
	cout << "\t+------------------------+" << endl;
	textAndBackgroundColor(color::LightAqua, color::Black);
	cout << "\tMoi ban chon" << endl;
	return _getch();
}

/*IDEA 1: make name login can resize
Ex: ADMIN ==> size = 5
for (0 ==> size) cout << '*'
IDEA 2: make border can change style*/
void loginAdmin(string & strUsername, string & strPassword) {
	system("cls");
	textAndBackgroundColor(color::LightYellow, color::Black);
	cout << "\t***************************" << endl;
	cout << "\t*     ";
	textAndBackgroundColor(color::LightGreen, color::Black);
	cout << "DANG NHAP ADMIN     ";
	textAndBackgroundColor(color::LightYellow, color::Black);
	cout << "*" << endl;
	cout << "\t***************************" << endl;
	cout << "\tUser: " << endl;
	cout << "\tPin: " << endl;
	textAndBackgroundColor(color::White, color::Black);
	gotoXY(14, 3);
	getline(cin, strUsername);
	gotoXY(14, 4);
	encodePassword(strPassword);
	cout << endl;
}
void loginEmployees(string & strUsername, string & strPassword, int iMaxLogin) {
	system("cls");
	textAndBackgroundColor(color::LightYellow, color::Black);
	cout << "\t***************************" << endl;
	cout << "\t*   ";
	textAndBackgroundColor(color::LightGreen, color::Black);
	cout << "DANG NHAP EMPLOYEES   ";
	textAndBackgroundColor(color::LightYellow, color::Black);
	cout << "*" << endl;
	cout << "\t***************************" << endl;
	cout << "\tUser: " << endl;
	cout << "\tPass: " << endl;
	cout << "So lan con khi dang nhap sai mat khau: " << iMaxLogin << endl;
	textAndBackgroundColor(color::White, color::Black);
	gotoXY(14, 3);
	getline(cin, strUsername);
	gotoXY(14, 4);
	encodePassword(strPassword);
	cout << endl;
}

void showAnEmployeeInfoElement(color textColor, string strUsername, string strFullName, string strAddress, string strPhoneNumber, string strEmailAddress,
	string endType, char fillType) {
	int usernameSize = 15;
	int fullNameSize = 30;
	int addressSize = 60;
	int phoneNumberSize = 15;
	int emailAddressSize = 25;

	cout << setfill(fillType);
	textAndBackgroundColor(textColor, color::Black);
	cout << setw(usernameSize) << left << strUsername;
	textAndBackgroundColor(color::BrightWhite, color::Black);
	cout << endType;
	textAndBackgroundColor(textColor, color::Black);
	cout << setw(fullNameSize) << left << strFullName;
	textAndBackgroundColor(color::BrightWhite, color::Black);
	cout << endType;
	textAndBackgroundColor(textColor, color::Black);
	cout << setw(addressSize) << left << strAddress;
	textAndBackgroundColor(color::BrightWhite, color::Black);
	cout << endType;
	textAndBackgroundColor(textColor, color::Black);
	cout << setw(phoneNumberSize) << left << strPhoneNumber;
	textAndBackgroundColor(color::BrightWhite, color::Black);
	cout << endType;
	textAndBackgroundColor(textColor, color::Black);
	cout << setw(emailAddressSize) << left << strEmailAddress;
	textAndBackgroundColor(color::BrightWhite, color::Black);
	cout << endType.at(0);
	cout << setfill(' ');
	cout << endl;
}

char menuAdmin() {
	system("cls");
	textAndBackgroundColor(color::LightYellow, color::Black);
	cout << "\t***************MENU***************" << endl;
	cout << "\t  1. Them Employee                " << endl;
	cout << "\t  2. Xoa Employee                 " << endl;
	cout << "\t  3. Tim Employee                 " << endl;
	cout << "\t  4. Cap nhat Employee            " << endl;
	cout << "\t  5. Hien thi thong tin Employee  " << endl;
	cout << "\t  6. Thoat                        " << endl;
	cout << "\t**********************************" << endl;
	textAndBackgroundColor(color::LightAqua, color::Black);
	cout << "\tMoi ban chon chuc nang" << endl;
	return _getch();
}
char menuEmployee() {
	system("cls");
	textAndBackgroundColor(color::LightYellow, color::Black);
	cout << "\t**********MENU EMPLOYEE***********" << endl;
	cout << "\t  1. Xem thong tin tai khoan      " << endl;
	cout << "\t  2. Doi password                 " << endl;
	cout << "\t  3. Thoat                        " << endl;
	cout << "\t**********************************" << endl;
	textAndBackgroundColor(color::LightAqua, color::Black);
	cout << "\tMoi ban chon chuc nang" << endl;
	return _getch();
}

char menuUpdateInfo() {
	system("cls");
	textAndBackgroundColor(color::LightYellow, color::Black);
	cout << "<Chon thong tin can cap nhat>" << endl;
	textAndBackgroundColor(color::LightAqua, color::Black);
	cout << "--------------------" << endl;
	textAndBackgroundColor(color::BrightWhite, color::Black);
	cout << "  1. Ho va ten" << endl;
	cout << "  2. Dia chi" << endl;
	cout << "  3. So dien thoai" << endl;
	cout << "  4. Dia chi email" << endl;
	textAndBackgroundColor(color::LightAqua, color::Black);
	cout << "--------------------" << endl;
	textAndBackgroundColor(color::LightGreen, color::Black);
	cout << "<ESC> de huy bo" << endl;
	return _getch();
}
