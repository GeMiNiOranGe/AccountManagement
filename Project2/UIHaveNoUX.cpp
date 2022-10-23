#include "UIHaveNoUX.h"

/*IDEA 1: make name login can resize
Ex: ADMIN ==> size = 5
for (0 ==> size) cout << '*'
IDEA 2: make border can change style*/
char chooseAdminOrEmployee() {
	system("cls");
	textAndBackgroundColor(12, 0);
	cout << "\t+------------------------+" << endl;
	cout << "\t| 1. Dang Nhap ADMIN     |" << endl;
	cout << "\t| 2. Dang Nhap EMPLOYEES |" << endl;
	cout << "\t+------------------------+" << endl;
	textAndBackgroundColor(11, 0);
	cout << "\tMoi ban chon" << endl;
	return _getch();
}

void loginAdmin(string & strUsername, string & strPassword) {
	system("cls");
	textAndBackgroundColor(14, 0);
	cout << "\t***************************" << endl;
	cout << "\t*     ";
	textAndBackgroundColor(10, 0);
	cout << "DANG NHAP ADMIN     ";
	textAndBackgroundColor(14, 0);
	cout << "*" << endl;
	cout << "\t***************************" << endl;
	cout << "\tUser: " << endl;
	cout << "\tPin: " << endl;
	textAndBackgroundColor(7, 0);
	gotoXY(14, 3);
	getline(cin , strUsername);
	gotoXY(14, 4);
	encodePassword(strPassword);
	cout << endl;
}
void loginEmployees(string & strUsername, string & strPassword) {
	system("cls");
	textAndBackgroundColor(14, 0);
	cout << "\t***************************" << endl;
	cout << "\t*   ";
	textAndBackgroundColor(10, 0);
	cout << "DANG NHAP EMPLOYEES   ";
	textAndBackgroundColor(14, 0);
	cout << "*" << endl;
	cout << "\t***************************" << endl;
	cout << "\tUser: " << endl;
	cout << "\tPass: " << endl;
	textAndBackgroundColor(7, 0);
	gotoXY(14, 3);
	getline(cin, strUsername);
	gotoXY(14, 4);
	encodePassword(strPassword);
	cout << endl;
}

char menuAdmin() {
	system("cls");
	textAndBackgroundColor(14, 0);
	cout << "\t***************MENU***************" << endl;
	cout << "\t  1. Them Employee                " << endl;
	cout << "\t  2. Xoa Employee                 " << endl;
	cout << "\t  3. Tim Employee                 " << endl;
	cout << "\t  4. Cap nhat Employee            " << endl;
	cout << "\t  5. Hien thi thong tin Employee  " << endl;
	cout << "\t  6. Thoat                        " << endl;
	cout << "\t**********************************" << endl;
	textAndBackgroundColor(11, 0);
	cout << "\tMoi ban chon chuc nang" << endl;
	return _getch();
}
char menuEmployee() {
	system("cls");
	textAndBackgroundColor(14, 0);
	cout << "\t**********MENU EMPLOYEE***********" << endl;
	cout << "\t  1. Xem thong tin tai khoan      " << endl;
	cout << "\t  2. Doi password                 " << endl;
	cout << "\t  3. Thoat                        " << endl;
	cout << "\t**********************************" << endl;
	textAndBackgroundColor(11, 0);
	cout << "\tMoi ban chon chuc nang" << endl;
	return _getch();
}
