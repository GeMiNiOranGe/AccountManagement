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
	┌────────────────────────────────────────┐
	│        <Enter your information>        │
	├────────────────────────────────────────┤
	│     Full name:                         │
	├────────────────────────────────────────┤
	│       Address:                         │
	├────────────────────────────────────────┤
	│  Phone number:                         │
	├────────────────────────────────────────┤
	│ Email address:                         │
	└────────────────────────────────────────┘*/
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
	std::wcout << std::setfill(L'─');
	std::wcout << L'─';
	for (int i = 0; i < numberOfFill.size(); i++) {
		std::wcout << L'─' << std::setw(numberOfFill.at(i)) << L'─';
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
	std::wcout << std::setfill(fillType);
	std::wcout << Border::Vertical();
	for (int i = 0; i < maxSizeAndWStringPairs.size(); i++) {
		short sMaxSize = static_cast<short>(maxSizeAndWStringPairs.at(i).first);
		textAndBackgroundColor(textColor, Color::Black);
		std::wcout << fillType << std::setw(sMaxSize) << std::left << maxSizeAndWStringPairs.at(i).second << fillType;
		textAndBackgroundColor(Color::BrightWhite, Color::Black);
		std::wcout << Border::Vertical();
	}
	std::wcout << std::setfill(L' ');
	_setmode(_fileno(stdout), _O_TEXT);
}

void showInfoAccounts() {
	std::string titles[] = {
		"Id",
		"Username",
		"Password",
		"Full name",
		"Address",
		"Phone number",
		"Email address"
	};
	const int titlesSize = sizeof(titles) / sizeof(std::string);
	std::vector<short> vecTitleMaxSizes(titlesSize);

	// Initialize each element in titleMaxSizes with the string size of each element in titles
	for (short i = 0; i < titlesSize; i++)
		vecTitleMaxSizes[i] = titles[i].size();

	std::ifstream fileIn;
	fileIn.open(ACCOUNTS_FILE);

	while (!fileIn.eof()) {
		CUser user;
		file::read::account(user, fileIn);
		std::ifstream fileUserInfoTemp = openFile(user.getUsername());
		file::read::info(user, fileUserInfoTemp);

		// Get all properties in class CUser
		std::string * p_strCUserProperties = user.getProperties();

		// Find the maximum size of each table cell, horizontally
		if (user.getUsername() != "")
			for (short i = 0; i < titlesSize; i++)
				if (vecTitleMaxSizes[i] < p_strCUserProperties[i].size())
					vecTitleMaxSizes[i] = p_strCUserProperties[i].size();

		fileUserInfoTemp.close();
	}

	fileIn.clear();
	fileIn.seekg(0, std::ios::beg);

	std::cout << ' ';
	showBorder(vecTitleMaxSizes, Position::First);
	std::cout << std::endl;

	std::cout << ' ';
	std::vector<std::pair<short, std::wstring>> pairs_titleMaxSizeAndTitle;
	for (short i = 0; i < titlesSize; i++)
		pairs_titleMaxSizeAndTitle.push_back(std::make_pair(vecTitleMaxSizes[i], convertToWString(titles[i])));
	showInfoAccount(pairs_titleMaxSizeAndTitle, Color::LightYellow);
	std::cout << std::endl;

	while (!fileIn.eof()) {
		CUser user;
		//TODO: file::read::account(fileIn, user);
		file::read::account(user, fileIn);
		std::ifstream fileUserInfoTemp = openFile(user.getUsername());
		file::read::info(user, fileUserInfoTemp);

		// Get all properties in class CUser
		std::string * p_strCUserProperties = user.getProperties();

		std::vector<std::pair<short, std::wstring>> pairs_titleMaxSizeAndCUserProperty;
		for (short i = 0; i < titlesSize; i++)
			pairs_titleMaxSizeAndCUserProperty.push_back(std::make_pair(vecTitleMaxSizes[i], convertToWString(p_strCUserProperties[i])));

		// Show all account information
		if (user.getUsername() != "") {
			std::cout << ' ';
			showBorder(vecTitleMaxSizes, Position::Middle);
			std::cout << std::endl;

			std::cout << ' ';
			showInfoAccount(pairs_titleMaxSizeAndCUserProperty, Color::White);
			std::cout << std::endl;
		}
		
		fileUserInfoTemp.close();
	}
	
	std::cout << ' ';
	showBorder(vecTitleMaxSizes, Position::Last);
	
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