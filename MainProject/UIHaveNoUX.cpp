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

	typedef BoxBorder<BorderStyle::Single> Border;

	if ((title.size() + labelSize + fillSize) % 2 == 1) fillSize++;
	short sumSize = labelSize + fillSize;
	short alignMiddle = static_cast<short>(sumSize + title.size()) / 2;
	std::wcout << Border::Top::Left() << std::setfill(Border::Horizontal()) << std::setw(sumSize) << Border::Horizontal() << Border::Top::Right() << std::setfill(L' ') << std::endl;
	std::wcout << Border::Vertical() << std::setw(alignMiddle) << std::right << title << std::setw(alignMiddle - title.size()) << ' ' << Border::Vertical() << std::endl;

	std::wcout << Border::Left() << std::setfill(Border::Horizontal()) << std::setw(sumSize) << Border::Horizontal() << Border::Right() << std::setfill(L' ') << std::endl;
	std::wcout << Border::Vertical() << std::setw(labelSize) << std::right << "Full name:" << std::setw(fillSize) << ' ' << Border::Vertical() << std::endl;

	std::wcout << Border::Left() << std::setfill(Border::Horizontal()) << std::setw(sumSize) << Border::Horizontal() << Border::Right() << std::setfill(L' ') << std::endl;
	std::wcout << Border::Vertical() << std::setw(labelSize) << std::right << "Address:" << std::setw(fillSize) << ' ' << Border::Vertical() << std::endl;

	std::wcout << Border::Left() << std::setfill(Border::Horizontal()) << std::setw(sumSize) << Border::Horizontal() << Border::Right() << std::setfill(L' ') << std::endl;
	std::wcout << Border::Vertical() << std::setw(labelSize) << std::right << "Phone number:" << std::setw(fillSize) << ' ' << Border::Vertical() << std::endl;

	std::wcout << Border::Left() << std::setfill(Border::Horizontal()) << std::setw(sumSize) << Border::Horizontal() << Border::Right() << std::setfill(L' ') << std::endl;
	std::wcout << Border::Vertical() << std::setw(labelSize) << std::right << "Email address:" << std::setw(fillSize) << ' ' << Border::Vertical() << std::endl;

	std::wcout << Border::Bottom::Left() << std::setfill(Border::Horizontal()) << std::setw(sumSize) << Border::Horizontal() << Border::Bottom::Right() << std::setfill(L' ') << std::endl;
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

//void showInfoAnAccount(Color textColor, wchar_t fillType, std::tuple<short, std::string> arg) {
//	short ArgSize = static_cast<short>(std::get<0>(arg));
//
//	typedef BoxBorder<BorderStyle::Single> Border;
//
//	std::wstring wStrArg = convertToWString(std::get<1>(arg));
//	_setmode(_fileno(stdout), _O_U16TEXT);
//
//	std::wcout << std::setfill(fillType);
//
//	std::wcout << fillType;
//	textAndBackgroundColor(textColor, Color::Black);
//	std::wcout << std::setw(ArgSize) << std::left << wStrArg;
//	textAndBackgroundColor(Color::BrightWhite, Color::Black);
//	std::wcout << fillType << Border::Vertical();
//
//	std::wcout << std::setfill(L' ');
//	_setmode(_fileno(stdout), _O_TEXT);
//}

void showBorder(std::vector<short> numberOfFill, Position borderPos) {
	typedef BoxBorder<BorderStyle::Single> Border;
	_setmode(_fileno(stdout), _O_U16TEXT);
	// ─│┌┐└┘├┤┬┴┼
	// ═║╔╗╚╝╠╣╦╩╬
	if (borderPos == Position::First) std::wcout << Border::Top::Left();
	if (borderPos == Position::Middle) std::wcout << Border::Left();
	if (borderPos == Position::Last) std::wcout << Border::Bottom::Left();
	std::wcout << L'─';
	for (int i = 0; i < numberOfFill.size(); i++) {
		std::wcout << L'─';
		std::wcout << std::setfill(L'─');
		std::wcout << std::setw(numberOfFill.at(i)) << L'─';
		if (i != numberOfFill.size() - 1) {
			if (borderPos == Position::First) std::wcout << Border::Top();
			if (borderPos == Position::Middle) std::wcout << Border::Middle();
			if (borderPos == Position::Last) std::wcout << Border::Bottom();
			std::wcout << L'─';
		}
	}
	if (borderPos == Position::First) std::wcout << Border::Top::Right();
	if (borderPos == Position::Middle) std::wcout << Border::Right();
	if (borderPos == Position::Last) std::wcout << Border::Bottom::Right();
	_setmode(_fileno(stdout), _O_TEXT);
}

// Output to console in given format: 
// Pair (maxSize: maximum cell size, wString: One sentence), BorderStyle: Single(customizable)
void showInfoAccount(std::vector<std::pair<short, std::wstring>> maxSizeAndWStringPairs, Color textColor, wchar_t fillType) {
	typedef BoxBorder<BorderStyle::Single> Border;
	_setmode(_fileno(stdout), _O_U16TEXT);
	std::wcout << Border::Vertical();
	for (int i = 0; i < maxSizeAndWStringPairs.size(); i++) {
		short ArgSize = static_cast<short>(maxSizeAndWStringPairs.at(i).first);
		std::wcout << std::setfill(fillType) << fillType;
		textAndBackgroundColor(textColor, Color::Black);
		std::wcout << std::setw(ArgSize) << std::left << maxSizeAndWStringPairs.at(i).second;
		textAndBackgroundColor(Color::BrightWhite, Color::Black);
		std::wcout << fillType << Border::Vertical() << std::setfill(L' ');
	}
	_setmode(_fileno(stdout), _O_TEXT);
}

void showInfoAccounts() {
	std::string usernameTitle = "Username";
	std::string fullNameTitle = "Full name";
	std::string addressTitle = "Address";
	std::string phoneNumberTitle = "Phone number";
	std::string emailAddressTitle = "Email address";
	short usernameMaxSize = static_cast<short>(usernameTitle.size());
	short fullNameMaxSize = static_cast<short>(fullNameTitle.size());
	short addressMaxSize = static_cast<short>(addressTitle.size());
	short phoneNumberMaxSize = static_cast<short>(phoneNumberTitle.size());
	short emailAddressMaxSize = static_cast<short>(emailAddressTitle.size());
	std::ifstream fileIn;
	fileIn.open(ACCOUNTS_FILE);
	while (!fileIn.eof()) {
		CUser _user;
		file::read::account(_user, fileIn);
		std::ifstream fileUserInfoTemp = openFile(_user.getUsername());
		file::read::info(_user, fileUserInfoTemp);
		if (_user.getUsername() != "") {
			if (usernameMaxSize < _user.getUsername().size()) usernameMaxSize = static_cast<short>(_user.getUsername().size());
			if (fullNameMaxSize < _user.getFullName().size()) fullNameMaxSize = static_cast<short>(_user.getFullName().size());
			if (addressMaxSize < _user.getAddress().size()) addressMaxSize = static_cast<short>(_user.getAddress().size());
			if (phoneNumberMaxSize < _user.getPhoneNumber().size()) phoneNumberMaxSize = static_cast<short>(_user.getPhoneNumber().size());
			if (emailAddressMaxSize < _user.getEmailAddress().size()) emailAddressMaxSize = static_cast<short>(_user.getEmailAddress().size());
		}
	}
	fileIn.clear();
	fileIn.seekg(0, std::ios::beg);
	//showInfoAnAccount(
	//	Color::LightYellow,
	//	L' ',
	//	std::make_tuple(usernameMaxSize, usernameTitle),
	//	std::make_tuple(fullNameMaxSize, fullNameTitle),
	//	std::make_tuple(addressMaxSize, addressTitle),
	//	std::make_tuple(phoneNumberMaxSize, phoneNumberTitle),
	//	std::make_tuple(emailAddressMaxSize, emailAddressTitle)
	//);
	showBorder({
			usernameMaxSize,
			fullNameMaxSize,
			addressMaxSize,
			phoneNumberMaxSize,
			emailAddressMaxSize
		},
		Position::First
	);
	std::cout << std::endl;
	showInfoAccount({
			std::make_pair(usernameMaxSize, convertToWString(usernameTitle)),
			std::make_pair(fullNameMaxSize, convertToWString(fullNameTitle)),
			std::make_pair(addressMaxSize, convertToWString(addressTitle)),
			std::make_pair(phoneNumberMaxSize, convertToWString(phoneNumberTitle)),
			std::make_pair(emailAddressMaxSize, convertToWString(emailAddressTitle))
		},
		Color::LightYellow
	);
	std::cout << std::endl;
	while (!fileIn.eof()) {
		CUser _user;
		file::read::account(_user, fileIn);
		std::ifstream fileUserInfoTemp = openFile(_user.getUsername());
		file::read::info(_user, fileUserInfoTemp);
		if (_user.getUsername() != "") {
			//showInfoAnAccount(
			//	Color::LightBlue,
			//	L' ',
			//	std::make_tuple(usernameMaxSize, _user.getUsername()),
			//	std::make_tuple(fullNameMaxSize, _user.getFullName()),
			//	std::make_tuple(addressMaxSize, _user.getAddress()),
			//	std::make_tuple(phoneNumberMaxSize, _user.getPhoneNumber()),
			//	std::make_tuple(emailAddressMaxSize, _user.getEmailAddress())
			//);
			showBorder({
					usernameMaxSize,
					fullNameMaxSize,
					addressMaxSize,
					phoneNumberMaxSize,
					emailAddressMaxSize
				},
				Position::Middle
			);
			std::cout << std::endl;
			showInfoAccount({
					std::make_pair(usernameMaxSize, convertToWString(_user.getUsername())),
					std::make_pair(fullNameMaxSize, convertToWString(_user.getFullName())),
					std::make_pair(addressMaxSize, convertToWString(_user.getAddress())),
					std::make_pair(phoneNumberMaxSize, convertToWString(_user.getPhoneNumber())),
					std::make_pair(emailAddressMaxSize, convertToWString(_user.getEmailAddress()))
				},
				Color::White
			);
			std::cout << std::endl;
		}
		fileUserInfoTemp.close();
	}
	showBorder({
		usernameMaxSize,
		fullNameMaxSize,
		addressMaxSize,
		phoneNumberMaxSize,
		emailAddressMaxSize
		},
		Position::Last
	);
	fileIn.close();
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

std::wstring convertToWString(const std::string & _string) {
	return std::wstring(_string.begin(), _string.end());
}