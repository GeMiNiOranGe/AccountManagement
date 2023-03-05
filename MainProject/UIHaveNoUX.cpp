#include "UIHaveNoUX.h"

std::string formLogin(std::string & strUsername, std::string & strPassword) {
	//
	// TODO: add type in list admin and employee to combine frmAdminLogin and frmEmployeeLogin into frmLogin
	// 
	//if (hasAccount(ADMINISTRATOR_FILE, strUsername, strPassword)) {
	//	return "admin";
	//}
	system("cls");
	textAndBackgroundColor(Color::LightYellow, Color::Black);
	std::cout << "\t************************************" << std::endl;
	std::cout << "\t*              ";
	textAndBackgroundColor(Color::LightGreen, Color::Black);
	std::cout << "LOG IN              ";
	textAndBackgroundColor(Color::LightYellow, Color::Black);
	std::cout << "*" << std::endl;
	std::cout << "\t************************************" << std::endl;
	std::cout << "\tUsername: " << std::endl;
	std::cout << "\tPassword: " << std::endl;
	textAndBackgroundColor(Color::White, Color::Black);
	gotoXY(18, 3);
	getline(std::cin, strUsername);
	gotoXY(18, 4);
	encodePassword(strPassword);

	return std::string();
}
void formInfo(short labelSize, short fillSize, std::wstring title) {
	_setmode(_fileno(stdout), _O_U16TEXT);
	//std::wstring title = L"<Enter your information>"; //le
	//short labelSize = 15;
	//short fillSize = 25;//le
	wchar_t horizontal = L'─'; //│┌─┐└┘├┤┬┴┼
	wchar_t vertical = L'│';// ⩴⫬═≕≔≖

	wchar_t topLeft = L'┌';
	wchar_t topMiddle = L'┬';
	wchar_t topRight = L'┐';

	wchar_t middleLeft = L'├';
	wchar_t moddle = L'┼';
	wchar_t middleRight = L'┤';

	wchar_t bottomLeft = L'└';
	wchar_t bottomMiddle = L'┴';
	wchar_t bottomRight = L'┘';

	if ((title.size() + labelSize + fillSize) % 2 == 1) fillSize++;
	short sumSize = labelSize + fillSize;
	short alignMiddle = (sumSize + title.size()) / 2;
	std::wcout << topLeft << std::setfill(horizontal) << std::setw(sumSize) << horizontal << topRight << std::setfill(L' ') << std::endl;
	std::wcout << vertical << std::setw(alignMiddle) << std::right << title << std::setw(alignMiddle - title.size()) << ' ' << vertical << std::endl;
	std::wcout << middleLeft << std::setfill(horizontal) << std::setw(sumSize) << horizontal << middleRight << std::setfill(L' ') << std::endl;
	std::wcout << vertical << std::setw(labelSize) << std::right << "Full name:" << std::setw(fillSize) << ' ' << vertical << std::endl;
	std::wcout << middleLeft << std::setfill(horizontal) << std::setw(sumSize) << horizontal << middleRight << std::setfill(L' ') << std::endl;
	std::wcout << vertical << std::setw(labelSize) << std::right << "Address:" << std::setw(fillSize) << ' ' << vertical << std::endl;
	std::wcout << middleLeft << std::setfill(horizontal) << std::setw(sumSize) << horizontal << middleRight << std::setfill(L' ') << std::endl;
	std::wcout << vertical << std::setw(labelSize) << std::right << "Phone number:" << std::setw(fillSize) << ' ' << vertical << std::endl;
	std::wcout << middleLeft << std::setfill(horizontal) << std::setw(sumSize) << horizontal << middleRight << std::setfill(L' ') << std::endl;
	std::wcout << vertical << std::setw(labelSize) << std::right << "Email address:" << std::setw(fillSize) << ' ' << vertical << std::endl;
	std::wcout << bottomLeft << std::setfill(horizontal) << std::setw(sumSize) << horizontal << bottomRight << std::setfill(L' ') << std::endl;
	_setmode(_fileno(stdout), _O_TEXT);
	/*form info can be like this (DEMO)
	+-------------------------------+
	|             Title             |
	+-------------------------------+
	|    name:                      |
	+-------------------------------+
	|   phone:                      |
	+-------------------------------+
	|    mail:                      |
	+-------------------------------+
	| address:                      |
	+-------------------------------+ */
}

char chooseAdminOrEmployee() {
	system("cls");
	textAndBackgroundColor(Color::LightRed, Color::Black);
	std::cout << "\t+------------------------+" << std::endl;
	std::cout << "\t| 1. Dang Nhap ADMIN     |" << std::endl;
	std::cout << "\t| 2. Dang Nhap EMPLOYEES |" << std::endl;
	std::cout << "\t+------------------------+" << std::endl;
	textAndBackgroundColor(Color::LightAqua, Color::Black);
	std::cout << "\tMoi ban chon" << std::endl;
	return _getch();
}

/*IDEA 1: make name login can resize
Ex: ADMIN ==> size = 5
for (0 ==> size) cout << '*'
IDEA 2: make border can change style*/
void loginAdmin(std::string & strUsername, std::string & strPassword) {
	system("cls");
	textAndBackgroundColor(Color::LightYellow, Color::Black);
	std::cout << "\t***************************" << std::endl;
	std::cout << "\t*     ";
	textAndBackgroundColor(Color::LightGreen, Color::Black);
	std::cout << "DANG NHAP ADMIN     ";
	textAndBackgroundColor(Color::LightYellow, Color::Black);
	std::cout << "*" << std::endl;
	std::cout << "\t***************************" << std::endl;
	std::cout << "\tUser: " << std::endl;
	std::cout << "\tPin: " << std::endl;
	textAndBackgroundColor(Color::White, Color::Black);
	gotoXY(14, 3);
	getline(std::cin, strUsername);
	gotoXY(14, 4);
	encodePassword(strPassword);
	std::cout << std::endl;
}
void loginEmployees(std::string & strUsername, std::string & strPassword, int iMaxLogin) {
	system("cls");
	textAndBackgroundColor(Color::LightYellow, Color::Black);
	std::cout << "\t***************************" << std::endl;
	std::cout << "\t*   ";
	textAndBackgroundColor(Color::LightGreen, Color::Black);
	std::cout << "DANG NHAP EMPLOYEES   ";
	textAndBackgroundColor(Color::LightYellow, Color::Black);
	std::cout << "*" << std::endl;
	std::cout << "\t***************************" << std::endl;
	std::cout << "\tUser: " << std::endl;
	std::cout << "\tPass: " << std::endl;
	std::cout << "So lan con khi dang nhap sai mat khau: " << iMaxLogin << std::endl;
	textAndBackgroundColor(Color::White, Color::Black);
	gotoXY(14, 3);
	getline(std::cin, strUsername);
	gotoXY(14, 4);
	encodePassword(strPassword);
	std::cout << std::endl;
}

void showAnEmployeeInfoElement(Color textColor, std::string strUsername, std::string strFullName, std::string strAddress,
	std::string strPhoneNumber, std::string strEmailAddress, std::string endType, char fillType) {
	short usernameSize = 15;
	short fullNameSize = 30;
	short addressSize = 60;
	short phoneNumberSize = 15;
	short emailAddressSize = 25;

	std::cout << std::setfill(fillType);
	textAndBackgroundColor(textColor, Color::Black);
	std::cout << std::setw(usernameSize) << std::left << strUsername;
	textAndBackgroundColor(Color::BrightWhite, Color::Black);
	std::cout << endType;
	textAndBackgroundColor(textColor, Color::Black);
	std::cout << std::setw(fullNameSize) << std::left << strFullName;
	textAndBackgroundColor(Color::BrightWhite, Color::Black);
	std::cout << endType;
	textAndBackgroundColor(textColor, Color::Black);
	std::cout << std::setw(addressSize) << std::left << strAddress;
	textAndBackgroundColor(Color::BrightWhite, Color::Black);
	std::cout << endType;
	textAndBackgroundColor(textColor, Color::Black);
	std::cout << std::setw(phoneNumberSize) << std::left << strPhoneNumber;
	textAndBackgroundColor(Color::BrightWhite, Color::Black);
	std::cout << endType;
	textAndBackgroundColor(textColor, Color::Black);
	std::cout << std::setw(emailAddressSize) << std::left << strEmailAddress;
	textAndBackgroundColor(Color::BrightWhite, Color::Black);
	std::cout << endType.at(0);
	std::cout << std::setfill(' ');
	std::cout << std::endl;
}

char menuAdmin() {
	system("cls");
	textAndBackgroundColor(Color::LightYellow, Color::Black);
	/*ͰΤ⫟⫞⊦⊢⊤⌜⌌⌍⌏⌎◜◞⌊⌈|⨽⨼⫠⫥⫭⫪⫬Τ—−––--−−——⌈‖Τ*/
	std::cout << "\t——————————————<MENU>——————————————" << std::endl;
	std::cout << "\t  1. Them Employee                " << std::endl;
	std::cout << "\t  2. Xoa Employee                 " << std::endl;
	std::cout << "\t  3. Tim Employee                 " << std::endl;
	std::cout << "\t  4. Cap nhat Employee            " << std::endl;
	std::cout << "\t  5. Hien thi thong tin Employee  " << std::endl;
	std::cout << "\t  6. Thoat                        " << std::endl;
	std::cout << "\t——————————————————————————————————" << std::endl;
	textAndBackgroundColor(Color::LightAqua, Color::Black);
	std::cout << "\tMoi ban chon chuc nang" << std::endl;
	return _getch();
}
char menuEmployee() {
	system("cls");
	textAndBackgroundColor(Color::LightYellow, Color::Black);
	std::cout << "\t**********MENU EMPLOYEE***********" << std::endl;
	std::cout << "\t  1. Xem thong tin tai khoan      " << std::endl;
	std::cout << "\t  2. Doi password                 " << std::endl;
	std::cout << "\t  3. Thoat                        " << std::endl;
	std::cout << "\t**********************************" << std::endl;
	textAndBackgroundColor(Color::LightAqua, Color::Black);
	std::cout << "\tMoi ban chon chuc nang" << std::endl;
	return _getch();
}

char menuUpdateInfo() {
	system("cls");
	textAndBackgroundColor(Color::LightYellow, Color::Black);
	std::cout << "<Chon thong tin can cap nhat>" << std::endl;
	textAndBackgroundColor(Color::LightAqua, Color::Black);
	std::cout << "--------------------" << std::endl;
	textAndBackgroundColor(Color::BrightWhite, Color::Black);
	std::cout << "  1. Ho va ten" << std::endl;
	std::cout << "  2. Dia chi" << std::endl;
	std::cout << "  3. So dien thoai" << std::endl;
	std::cout << "  4. Dia chi email" << std::endl;
	textAndBackgroundColor(Color::LightAqua, Color::Black);
	std::cout << "--------------------" << std::endl;
	textAndBackgroundColor(Color::LightGreen, Color::Black);
	std::cout << "<ESC> de huy bo" << std::endl;
	return _getch();
}
