#include "UIHaveNoUX.h"

short get_max_size_of_label(std::vector<std::wstring> labels) {
	short label_size = 0;
	for (auto & label : labels)
		if (label_size < label.size())
			label_size = static_cast<short>(label.size());
	return label_size;
}

std::string form_login(std::string & username, std::string & password, box::BorderStyle style) {
	//
	// TODO: add type in list admin and employee to combine frmAdminLogin and frmEmployeeLogin into frmLogin
	// 
	//if (hasAccount(ADMINISTRATOR_FILE, strUsername, strPassword)) {
	//	return "admin";
	//}
	typedef box::Border Border;

	std::string title = "Log in";
	std::string username_title = "Username:";
	std::string password_title = "Password:";
	wchar_t fill_style = ' ';

	short temp = 10;
	short width = title.size() + temp;
	if (is_odd(title.size() + temp)) temp++;
	short sum_size = title.size() + temp;
	short align_middle = static_cast<short>(sum_size + title.size()) / 2;

	system("cls");
	_setmode(_fileno(stdout), _O_U16TEXT);
	textAndBackgroundColor(Color::LIGHT_GREEN);
	std::wcout << Border::top_left(style) << std::setfill(Border::horizontal(style)) << std::setw(width) << Border::top_right(style) << std::setfill(fill_style) << std::endl;
	for (int i = 0; i < 3; i++)
		std::wcout << Border::vertical(style) << std::setw(width) << Border::vertical(style) << std::endl;
	std::wcout << Border::left(style) << std::setfill(Border::horizontal(style)) << std::setw(width) << Border::right(style) << std::setfill(fill_style) << std::endl;
	for (int i = 0; i < 5; i++)
		std::wcout << Border::vertical(style) << std::setw(width) << Border::vertical(style) << std::endl;
	std::wcout << Border::bottom_left(style) << std::setfill(Border::horizontal(style)) << std::setw(width) << Border::bottom_right(style) << std::setfill(fill_style) << std::endl;
	_setmode(_fileno(stdout), _O_TEXT);

	textAndBackgroundColor(Color::LIGHT_AQUA);
	gotoXY(align_middle, 2);
	std::cout << title;
	gotoXY(2, 6);
	std::cout << username_title;
	gotoXY(2, 8);
	std::cout << password_title;

	textAndBackgroundColor(Color::BRIGHT_WHITE);
	gotoXY(12, 6);
	getline(std::cin, username);
	gotoXY(12, 8);
	encode_password(password);

	return std::string();
}
void form_info(std::wstring title, std::vector<std::wstring> labels, box::BorderStyle style, short fill_size) {
	_setmode(_fileno(stdout), _O_U16TEXT);
	typedef box::Border Border;
	wchar_t fill_style = ' ';

	// Get max size of label
	short label_size = get_max_size_of_label(labels);

	// Make space for label
	label_size++;

	// Calculation to put the header in the center of the table
	if ((title.size() + label_size + fill_size) % 2 == 1) fill_size++;
	short sum_size = label_size + fill_size;
	short align_middle = static_cast<short>(sum_size + title.size()) / 2;

	// Show form
	std::wcout << Border::top_left(style) << std::setfill(Border::horizontal(style)) << std::setw(sum_size) << Border::horizontal(style) << Border::top_right(style) << std::setfill(fill_style) << std::endl;
	std::wcout << Border::vertical(style) << std::setw(align_middle) << std::right << title << std::setw(align_middle - title.size()) << fill_style << Border::vertical(style) << std::endl;

	for (auto & element : labels) {
		std::wcout << Border::left(style) << std::setfill(Border::horizontal(style)) << std::setw(sum_size) << Border::horizontal(style) << Border::right(style) << std::setfill(fill_style) << std::endl;
		std::wcout << Border::vertical(style) << std::setw(label_size) << std::right << element << std::setw(fill_size) << fill_style << Border::vertical(style) << std::endl;
	}

	std::wcout << Border::bottom_left(style) << std::setfill(Border::horizontal(style)) << std::setw(sum_size) << Border::horizontal(style) << Border::bottom_right(style) << std::setfill(L' ') << std::endl;
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
	encode_password(strPassword);
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
	encode_password(strPassword);
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
//	std::wcout << fillType << Border::vertical(style);
//
//	std::wcout << std::setfill(L' ');
//	_setmode(_fileno(stdout), _O_TEXT);
//}

void show_a_part_border(std::vector<short> number_of_fill, Position _position, box::BorderStyle style) {
	typedef box::Border Border;

	_setmode(_fileno(stdout), _O_U16TEXT);
	// ─│┌┐└┘├┤┬┴┼
	// ═║╔╗╚╝╠╣╦╩╬
	if (_position == Position::FIRST) std::wcout << Border::top_left(style);
	if (_position == Position::MIDDLE) std::wcout << Border::left(style);
	if (_position == Position::LAST) std::wcout << Border::bottom_left(style);

	std::wcout << std::setfill(Border::horizontal(style));
	std::wcout << Border::horizontal(style);

	for (auto & element : number_of_fill) {
		std::wcout << Border::horizontal(style) << std::setw(element) << Border::horizontal(style);
		if (element != *(number_of_fill.end() - 1)) {
			if (_position == Position::FIRST) std::wcout << Border::top(style);
			if (_position == Position::MIDDLE) std::wcout << Border::center(style);
			if (_position == Position::LAST) std::wcout << Border::bottom(style);
			std::wcout << Border::horizontal(style);
		}
	}

	if (_position == Position::FIRST) std::wcout << Border::top_right(style);
	if (_position == Position::MIDDLE) std::wcout << Border::right(style);
	if (_position == Position::LAST) std::wcout << Border::bottom_right(style);
	_setmode(_fileno(stdout), _O_TEXT);
}

// Output to console in given format: 
// Pair (maxSize: maximum cell size, wString: One sentence), BorderStyle: Single(customizable)
void show_info_account(std::vector<std::pair<short, std::wstring>> maxSizeAndWStringPairs, Color text_color, wchar_t fill_type, box::BorderStyle style) {
	//TODO: make enum for fill type
	typedef box::Border Border;
	_setmode(_fileno(stdout), _O_U16TEXT);
	std::wcout << std::setfill(fill_type);
	std::wcout << Border::vertical(style);
	for (auto & element : maxSizeAndWStringPairs) {
		short max_size = static_cast<short>(element.first);
		textAndBackgroundColor(text_color);
		std::wcout << fill_type << std::setw(max_size) << std::left << element.second << fill_type;
		textAndBackgroundColor(Color::BRIGHT_WHITE);
		std::wcout << Border::vertical(style);
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
	const int titles_size = sizeof(titles) / sizeof(titles[0]);
	std::vector<short> vecTitleMaxSizes;
	std::ifstream file_in;
	std::vector<std::pair<short, std::wstring>> pairs_titleMaxSizeAndTitle;

	// Initialize each element in titleMaxSizes with the string size of each element in titles
	for (auto & title : titles) vecTitleMaxSizes.push_back(static_cast<short>(title.size()));

	file_in.open(ACCOUNTS_FILE);

	while (!file_in.eof()) {
		User user;
		file::read::account(file_in, user);
		std::ifstream fileUserInfo = openFile(user.get_username());
		file::read::info(fileUserInfo, user);

		// Get all properties in class User
		// TODO: convert to vector
		std::string * p_strCUserProperties = user.get_properties();

		// Find the maximum size of each table cell, horizontally
		if (user.get_username() != "")
			for (short i = 0; i < titles_size; i++)
				if (vecTitleMaxSizes[i] < p_strCUserProperties[i].size())
					vecTitleMaxSizes[i] = static_cast<short>(p_strCUserProperties[i].size());

		fileUserInfo.close();
	}

	// Reset file pointer
	file_in.clear();
	file_in.seekg(0, std::ios::beg);

	show_a_part_border(vecTitleMaxSizes, Position::FIRST);
	std::cout << std::endl;

	// Show titles
	for (short i = 0; i < titles_size; i++)
		pairs_titleMaxSizeAndTitle.push_back(std::make_pair(vecTitleMaxSizes[i], Convert::to_wstring(titles[i])));
	show_info_account(pairs_titleMaxSizeAndTitle, Color::LIGHT_YELLOW);
	std::cout << std::endl;

	// Show all account information
	while (!file_in.eof()) {
		User user;
		file::read::account(file_in, user);
		std::ifstream fileUserInfo = openFile(user.get_username());
		file::read::info(fileUserInfo, user);

		// Get all properties in class User
		std::string * p_strCUserProperties = user.get_properties();

		std::vector<std::pair<short, std::wstring>> title_max_size_user_property;
		for (short i = 0; i < titles_size; i++)
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

	file_in.close();
}

char menu_options(std::wstring title, std::vector<std::wstring> options, box::BorderStyle style) {
	short label_size = get_max_size_of_label(options);
	typedef box::Border Border;

	system("cls");
	_setmode(_fileno(stdout), _O_U16TEXT);
	textAndBackgroundColor(Color::LIGHT_YELLOW);
	std::wcout << L"┌─────────────<MENU>─────────────┐" << std::endl;
	std::wcout << L"│ 1. Them Employee               │" << std::endl;
	std::wcout << L"│ 2. Xoa Employee                │" << std::endl;
	std::wcout << L"│ 3. Tim Employee                │" << std::endl;
	std::wcout << L"│ 4. Cap nhat Employee           │" << std::endl;
	std::wcout << L"│ 5. Hien thi thong tin Employee │" << std::endl;
	std::wcout << L"│ 6. Thoat                       │" << std::endl;
	std::wcout << L"└────────────────────────────────┘" << std::endl;
	textAndBackgroundColor(Color::LIGHT_AQUA);
	std::wcout << "Moi ban chon chuc nang" << std::endl;
	_setmode(_fileno(stdout), _O_TEXT);
	return _getch();
}

char menuAdmin() {
	system("cls");
	_setmode(_fileno(stdout), _O_U16TEXT);
	textAndBackgroundColor(Color::LIGHT_YELLOW);
	std::wcout << L"┌─────────────<MENU>─────────────┐" << std::endl;
	std::wcout << L"│ 1. Them Employee               │" << std::endl;
	std::wcout << L"│ 2. Xoa Employee                │" << std::endl;
	std::wcout << L"│ 3. Tim Employee                │" << std::endl;
	std::wcout << L"│ 4. Cap nhat Employee           │" << std::endl;
	std::wcout << L"│ 5. Hien thi thong tin Employee │" << std::endl;
	std::wcout << L"│ 6. Thoat                       │" << std::endl;
	std::wcout << L"└────────────────────────────────┘" << std::endl;
	textAndBackgroundColor(Color::LIGHT_AQUA);
	std::wcout << "Moi ban chon chuc nang" << std::endl;
	_setmode(_fileno(stdout), _O_TEXT);
	return _getch();
}
char menuEmployee() {
	system("cls");
	_setmode(_fileno(stdout), _O_U16TEXT);
	textAndBackgroundColor(Color::LIGHT_YELLOW);
	std::wcout << L"┌───────<MENU EMPLOYEE>───────┐" << std::endl;
	std::wcout << L"│ 1. Xem thong tin tai khoan  │" << std::endl;
	std::wcout << L"│ 2. Doi password             │" << std::endl;
	std::wcout << L"│ 3. Thoat                    │" << std::endl;
	std::wcout << L"└─────────────────────────────┘" << std::endl;
	textAndBackgroundColor(Color::LIGHT_AQUA);
	std::wcout << "Moi ban chon chuc nang" << std::endl;
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
