#include "UIHaveNoUX.h"

std::string formLogin(std::string & strUsername, std::string & strPassword) {
	//
	// TODO: add type in list admin and employee to combine frmAdminLogin and frmEmployeeLogin into frmLogin
	// 
	//if (hasAccount(ADMINISTRATOR_FILE, strUsername, strPassword)) {
	//	return "admin";
	//}
	system("cls");
	textAndBackgroundColor(Color::LIGHT_YELLOW);
	std::cout << "\t************************************" << std::endl;
	std::cout << "\t*              ";
	textAndBackgroundColor(Color::LIGHT_GREEN);
	std::cout << "LOG IN              ";
	textAndBackgroundColor(Color::LIGHT_YELLOW);
	std::cout << "*" << std::endl;
	std::cout << "\t************************************" << std::endl;
	std::cout << "\tUsername: " << std::endl;
	std::cout << "\tPassword: " << std::endl;
	textAndBackgroundColor(Color::WHITE);
	gotoXY(18, 3);
	getline(std::cin, strUsername);
	gotoXY(18, 4);
	encodePassword(strPassword);

	return std::string();
}
void form_info(std::wstring title, std::vector<std::wstring> labels, box::BorderStyle _style, short fill_size) {
	_setmode(_fileno(stdout), _O_U16TEXT);
	typedef box::Border Border;
	short label_size = 0;
	wchar_t fill_style = ' ';

	// Get max size of label
	for (auto & element : labels)
		if (element.size() > label_size)
			label_size = static_cast<short>(element.size());

	// Make space for label
	label_size++;

	// Calculation to put the header in the center of the table
	if ((title.size() + label_size + fill_size) % 2 == 1) fill_size++;
	short sum_size = label_size + fill_size;
	short align_middle = static_cast<short>(sum_size + title.size()) / 2;

	// Show form
	std::wcout << Border::top_left(_style) << std::setfill(Border::horizontal(_style)) << std::setw(sum_size) << Border::horizontal(_style) << Border::top_right(_style) << std::setfill(fill_style) << std::endl;
	std::wcout << Border::vertical(_style) << std::setw(align_middle) << std::right << title << std::setw(align_middle - title.size()) << fill_style << Border::vertical(_style) << std::endl;

	for (auto & element : labels) {
		std::wcout << Border::left(_style) << std::setfill(Border::horizontal(_style)) << std::setw(sum_size) << Border::horizontal(_style) << Border::right(_style) << std::setfill(fill_style) << std::endl;
		std::wcout << Border::vertical(_style) << std::setw(label_size) << std::right << element << std::setw(fill_size) << fill_style << Border::vertical(_style) << std::endl;
	}

	std::wcout << Border::bottom_left(_style) << std::setfill(Border::horizontal(_style)) << std::setw(sum_size) << Border::horizontal(_style) << Border::bottom_right(_style) << std::setfill(L' ') << std::endl;
	_setmode(_fileno(stdout), _O_TEXT);
}

char chooseAdminOrEmployee() {
	system("cls");
	textAndBackgroundColor(Color::LIGHT_RED);
	std::cout << "\t+------------------------+" << std::endl;
	std::cout << "\t| 1. Dang Nhap ADMIN     |" << std::endl;
	std::cout << "\t| 2. Dang Nhap EMPLOYEES |" << std::endl;
	std::cout << "\t+------------------------+" << std::endl;
	textAndBackgroundColor(Color::LIGHT_AQUA);
	std::cout << "\tMoi ban chon" << std::endl;
	return _getch();
}

/*IDEA 1: make name login can resize
Ex: ADMIN ==> size = 5
for (0 ==> size) cout << '*'
IDEA 2: make border can change style*/
void loginAdmin(std::string & strUsername, std::string & strPassword) {
	system("cls");
	textAndBackgroundColor(Color::LIGHT_YELLOW);
	std::cout << "\t***************************" << std::endl;
	std::cout << "\t*     ";
	textAndBackgroundColor(Color::LIGHT_GREEN);
	std::cout << "DANG NHAP ADMIN     ";
	textAndBackgroundColor(Color::LIGHT_YELLOW);
	std::cout << "*" << std::endl;
	std::cout << "\t***************************" << std::endl;
	std::cout << "\tUser: " << std::endl;
	std::cout << "\tPin: " << std::endl;
	textAndBackgroundColor(Color::WHITE);
	gotoXY(14, 3);
	getline(std::cin, strUsername);
	gotoXY(14, 4);
	encodePassword(strPassword);
	std::cout << std::endl;
}
void loginEmployees(std::string & strUsername, std::string & strPassword, int iMaxLogin) {
	system("cls");
	textAndBackgroundColor(Color::LIGHT_YELLOW);
	std::cout << "\t***************************" << std::endl;
	std::cout << "\t*   ";
	textAndBackgroundColor(Color::LIGHT_GREEN);
	std::cout << "DANG NHAP EMPLOYEES   ";
	textAndBackgroundColor(Color::LIGHT_YELLOW);
	std::cout << "*" << std::endl;
	std::cout << "\t***************************" << std::endl;
	std::cout << "\tUser: " << std::endl;
	std::cout << "\tPass: " << std::endl;
	std::cout << "So lan con khi dang nhap sai mat khau: " << iMaxLogin << std::endl;
	textAndBackgroundColor(Color::WHITE);
	gotoXY(14, 3);
	getline(std::cin, strUsername);
	gotoXY(14, 4);
	encodePassword(strPassword);
	std::cout << std::endl;
}

//void showInfoAnAccount(Color textColor, wchar_t fillType, std::tuple<short, std::string> arg) {
//	short ArgSize = static_cast<short>(std::get<0>(arg));
//
//	typedef BoxBorder<BorderStyle::SINGLE> Border;
//
//	std::wstring wStrArg = convert_to_wstring(std::get<1>(arg));
//	_setmode(_fileno(stdout), _O_U16TEXT);
//
//	std::wcout << std::setfill(fillType);
//
//	std::wcout << fillType;
//	textAndBackgroundColor(textColor, Color::Black);
//	std::wcout << std::setw(ArgSize) << std::left << wStrArg;
//	textAndBackgroundColor(Color::BrightWhite, Color::Black);
//	std::wcout << fillType << Border::vertical(_style);
//
//	std::wcout << std::setfill(L' ');
//	_setmode(_fileno(stdout), _O_TEXT);
//}

void show_a_part_border(std::vector<short> number_of_fill, Position _position, box::BorderStyle _style) {
	typedef box::Border Border;

	_setmode(_fileno(stdout), _O_U16TEXT);
	// ─│┌┐└┘├┤┬┴┼
	// ═║╔╗╚╝╠╣╦╩╬
	if (_position == Position::FIRST) std::wcout << Border::top_left(_style);
	if (_position == Position::MIDDLE) std::wcout << Border::left(_style);
	if (_position == Position::LAST) std::wcout << Border::bottom_left(_style);

	std::wcout << std::setfill(Border::horizontal(_style));
	std::wcout << Border::horizontal(_style);

	for (auto & element : number_of_fill) {
		std::wcout << Border::horizontal(_style) << std::setw(element) << Border::horizontal(_style);
		if (element != *(number_of_fill.end() - 1)) {
			if (_position == Position::FIRST) std::wcout << Border::top(_style);
			if (_position == Position::MIDDLE) std::wcout << Border::center(_style);
			if (_position == Position::LAST) std::wcout << Border::bottom(_style);
			std::wcout << Border::horizontal(_style);
		}
	}

	if (_position == Position::FIRST) std::wcout << Border::top_right(_style);
	if (_position == Position::MIDDLE) std::wcout << Border::right(_style);
	if (_position == Position::LAST) std::wcout << Border::bottom_right(_style);
	_setmode(_fileno(stdout), _O_TEXT);
}

// Output to console in given format: 
// Pair (maxSize: maximum cell size, wString: One sentence), BorderStyle: Single(customizable)
void show_info_account(std::vector<std::pair<short, std::wstring>> maxSizeAndWStringPairs, Color textColor, wchar_t fillType, box::BorderStyle _style) {
	//TODO: make enum for fill type
	typedef box::Border Border;
	_setmode(_fileno(stdout), _O_U16TEXT);
	std::wcout << std::setfill(fillType);
	std::wcout << Border::vertical(_style);
	for (auto & element : maxSizeAndWStringPairs) {
		short sMaxSize = static_cast<short>(element.first);
		textAndBackgroundColor(textColor);
		std::wcout << fillType << std::setw(sMaxSize) << std::left << element.second << fillType;
		textAndBackgroundColor(Color::BRIGHT_WHITE);
		std::wcout << Border::vertical(_style);
	}
	std::wcout << std::setfill(L' ');
	_setmode(_fileno(stdout), _O_TEXT);
}

void show_info_accounts() {
	std::string titles[] = {
		"Id",
		"Username",
		"Password",
		"Full name",
		"Address",
		"Phone number",
		"Email address"
	};
	const int titlesSize = sizeof(titles) / sizeof(titles[0]);
	std::vector<short> vecTitleMaxSizes;
	std::ifstream fileIn;
	std::vector<std::pair<short, std::wstring>> pairs_titleMaxSizeAndTitle;

	// Initialize each element in titleMaxSizes with the string size of each element in titles
	for (auto & title : titles) vecTitleMaxSizes.push_back(title.size());

	fileIn.open(ACCOUNTS_FILE);

	while (!fileIn.eof()) {
		User user;
		file::read::account(fileIn, user);
		std::ifstream fileUserInfo = openFile(user.get_username());
		file::read::info(fileUserInfo, user);

		// Get all properties in class User
		std::string * p_strCUserProperties = user.get_properties();

		// Find the maximum size of each table cell, horizontally
		if (user.get_username() != "")
			for (short i = 0; i < titlesSize; i++)
				if (vecTitleMaxSizes[i] < p_strCUserProperties[i].size())
					vecTitleMaxSizes[i] = p_strCUserProperties[i].size();

		fileUserInfo.close();
	}

	// Reset file pointer
	fileIn.clear();
	fileIn.seekg(0, std::ios::beg);

	show_a_part_border(vecTitleMaxSizes, Position::FIRST);
	std::cout << std::endl;

	// Show titles
	for (short i = 0; i < titlesSize; i++)
		pairs_titleMaxSizeAndTitle.push_back(std::make_pair(vecTitleMaxSizes[i], Convert::to_wstring(titles[i])));
	show_info_account(pairs_titleMaxSizeAndTitle, Color::LIGHT_YELLOW);
	std::cout << std::endl;

	// Show all account information
	while (!fileIn.eof()) {
		User user;
		file::read::account(fileIn, user);
		std::ifstream fileUserInfo = openFile(user.get_username());
		file::read::info(fileUserInfo, user);

		// Get all properties in class User
		std::string * p_strCUserProperties = user.get_properties();

		std::vector<std::pair<short, std::wstring>> title_max_size_user_property;
		for (short i = 0; i < titlesSize; i++)
			title_max_size_user_property.push_back(std::make_pair(vecTitleMaxSizes[i], Convert::to_wstring(p_strCUserProperties[i])));

		// Show current account information
		if (user.get_username() != "") {
			show_a_part_border(vecTitleMaxSizes, Position::MIDDLE);
			std::cout << std::endl;

			show_info_account(title_max_size_user_property, Color::WHITE);
			std::cout << std::endl;
		}

		fileUserInfo.close();
	}

	show_a_part_border(vecTitleMaxSizes, Position::LAST);

	fileIn.close();
}

char menuAdmin() {
	system("cls");
	_setmode(_fileno(stdout), _O_U16TEXT);
	textAndBackgroundColor(Color::LIGHT_YELLOW);
	/*ͰΤ⫟⫞⊦⊢⊤⌜⌌⌍⌏⌎◜◞⌊⌈|⨽⨼⫠⫥⫭⫪⫬Τ—−––--−−——⌈‖Τ*/
	std::wcout << "┌─────────────<MENU>─────────────┐" << std::endl;
	std::wcout << "│ 1. Them Employee               │" << std::endl;
	std::wcout << "│ 2. Xoa Employee                │" << std::endl;
	std::wcout << "│ 3. Tim Employee                │" << std::endl;
	std::wcout << "│ 4. Cap nhat Employee           │" << std::endl;
	std::wcout << "│ 5. Hien thi thong tin Employee │" << std::endl;
	std::wcout << "│ 6. Thoat                       │" << std::endl;
	std::wcout << "└────────────────────────────────┘" << std::endl;
	textAndBackgroundColor(Color::LIGHT_AQUA);
	std::wcout << "\tMoi ban chon chuc nang" << std::endl;
	_setmode(_fileno(stdout), _O_TEXT);
	return _getch();
}
char menuEmployee() {
	system("cls");
	_setmode(_fileno(stdout), _O_U16TEXT);
	textAndBackgroundColor(Color::LIGHT_YELLOW);
	std::wcout << "┌───────<MENU EMPLOYEE>───────┐" << std::endl;
	std::wcout << "│ 1. Xem thong tin tai khoan  │" << std::endl;
	std::wcout << "│ 2. Doi password             │" << std::endl;
	std::wcout << "│ 3. Thoat                    │" << std::endl;
	std::wcout << "└─────────────────────────────┘" << std::endl;
	textAndBackgroundColor(Color::LIGHT_AQUA);
	std::wcout << "\tMoi ban chon chuc nang" << std::endl;
	_setmode(_fileno(stdout), _O_TEXT);
	return _getch();
}

char menuUpdateInfo() {
	system("cls");
	textAndBackgroundColor(Color::LIGHT_YELLOW);
	std::cout << "<Chon thong tin can cap nhat>" << std::endl;
	textAndBackgroundColor(Color::LIGHT_AQUA);
	std::cout << "--------------------" << std::endl;
	textAndBackgroundColor(Color::BRIGHT_WHITE);
	std::cout << "  1. Ho va ten" << std::endl;
	std::cout << "  2. Dia chi" << std::endl;
	std::cout << "  3. So dien thoai" << std::endl;
	std::cout << "  4. Dia chi email" << std::endl;
	textAndBackgroundColor(Color::LIGHT_AQUA);
	std::cout << "--------------------" << std::endl;
	textAndBackgroundColor(Color::LIGHT_GREEN);
	std::cout << "<ESC> de huy bo" << std::endl;
	return _getch();
}
