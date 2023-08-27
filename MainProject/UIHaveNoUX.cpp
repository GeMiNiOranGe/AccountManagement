#include "UIHaveNoUX.h"

short get_max_size_of_labels(std::vector<std::wstring> _labels) {
	short label_size = 0;
	for (auto & label : _labels)
		if (label_size < label.size())
			label_size = static_cast<short>(label.size());
	return label_size;
}

std::pair<std::string, std::string> form_login(box::BorderStyle _style) {
	typedef box::Border Border;
	std::string username, password;
	std::string title = "Log in";
	std::string username_label = "Username: ";
	std::string password_label = "Password: ";
	wchar_t fill_style = ' ';

	short width = 30;
	short new_width = width + 1;
	if (is_odd(title.size())) width++;
	short align_middle = static_cast<short>(width - title.size()) / 2;

	system("cls");
	_setmode(_fileno(stdout), _O_U16TEXT);
	textAndBackgroundColor(Color::LIGHT_GREEN);
	std::wcout << Border::top_left(_style) << std::setfill(Border::horizontal(_style)) << std::setw(new_width) << Border::top_right(_style) << std::setfill(fill_style) << std::endl;
	for (int i = 0; i < 3; i++)
		std::wcout << Border::vertical(_style) << std::setw(new_width) << Border::vertical(_style) << std::endl;
	std::wcout << Border::left(_style) << std::setfill(Border::horizontal(_style)) << std::setw(new_width) << Border::right(_style) << std::setfill(fill_style) << std::endl;
	for (int i = 0; i < 5; i++)
		std::wcout << Border::vertical(_style) << std::setw(new_width) << Border::vertical(_style) << std::endl;
	std::wcout << Border::bottom_left(_style) << std::setfill(Border::horizontal(_style)) << std::setw(new_width) << Border::bottom_right(_style) << std::setfill(fill_style) << std::endl;
	_setmode(_fileno(stdout), _O_TEXT);

	textAndBackgroundColor(Color::LIGHT_AQUA);
	gotoXY(align_middle + 1, 2);
	std::cout << title;
	gotoXY(2, 6);
	std::cout << username_label;
	gotoXY(2, 8);
	std::cout << password_label;

	textAndBackgroundColor(Color::BRIGHT_WHITE);
	gotoXY(static_cast<short>(username_label.size()) + 2, 6);
	getline(std::cin, username);
	gotoXY(static_cast<short>(password_label.size()) + 2, 8);
	encode_password(password);
	gotoXY(0, 10);

	return std::make_pair(username, password);
}
void form_info(std::wstring _title, std::vector<std::wstring> _labels, box::BorderStyle _style, short fill_size) {
	typedef box::Border Border;
	wchar_t fill_style = ' ';

	// Get max size of label
	short label_size = get_max_size_of_labels(_labels);

	// Make space for label
	label_size++;

	// Calculation to put the header in the center of the table
	if (is_odd(_title.size() + label_size + fill_size)) fill_size++;
	short sum_size = label_size + fill_size;
	short new_sum_size = sum_size + 1;
	short align_middle = static_cast<short>(sum_size - _title.size()) / 2;

	_setmode(_fileno(stdout), _O_U16TEXT);
	// Show form
	std::wcout << Border::top_left(_style) << std::setfill(Border::horizontal(_style)) << std::setw(new_sum_size) << Border::top_right(_style) << std::setfill(fill_style) << std::endl;
	std::wcout << Border::vertical(_style) << std::setw(new_sum_size) << Border::vertical(_style) << std::endl;
	std::wcout << Border::vertical(_style) << std::setw(align_middle + _title.size()) << std::right << _title << std::setw(static_cast<short>(align_middle + 1)) << Border::vertical(_style) << std::endl;
	std::wcout << Border::vertical(_style) << std::setw(new_sum_size) << Border::vertical(_style) << std::endl;

	for (auto & element : _labels) {
		std::wcout << Border::left(_style) << std::setfill(Border::horizontal(_style)) << std::setw(new_sum_size) << Border::right(_style) << std::setfill(fill_style) << std::endl;
		std::wcout << Border::vertical(_style) << std::setw(label_size) << std::right << element << std::setw(static_cast<short>(fill_size + 1)) << Border::vertical(_style) << std::endl;
		std::wcout << Border::vertical(_style) << std::setw(new_sum_size) << Border::vertical(_style) << std::endl;
	}

	std::wcout << Border::bottom_left(_style) << std::setfill(Border::horizontal(_style)) << std::setw(new_sum_size) << Border::bottom_right(_style) << std::setfill(L' ') << std::endl;
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
IDEA 2: make border can change _style*/
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

void show_a_part_border(std::vector<short> number_of_fill, Position _position, box::BorderStyle _style) {
	typedef box::Border Border;

	_setmode(_fileno(stdout), _O_U16TEXT);
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
void show_info_account(std::vector<std::pair<short, std::wstring>> maxSizeAndWStringPairs, Color text_color, wchar_t fill_type, box::BorderStyle _style) {
	//TODO: make enum for fill type
	typedef box::Border Border;
	_setmode(_fileno(stdout), _O_U16TEXT);
	std::wcout << std::setfill(fill_type);
	std::wcout << Border::vertical(_style);
	for (auto & element : maxSizeAndWStringPairs) {
		short max_size = static_cast<short>(element.first);
		textAndBackgroundColor(text_color);
		std::wcout << fill_type << std::setw(max_size) << std::left << element.second << fill_type;
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
	const int titles_size = sizeof(titles) / sizeof(titles[0]);
	std::vector<short> vecTitleMaxSizes;
	std::ifstream file_in;
	std::vector<std::pair<short, std::wstring>> pairs_titleMaxSizeAndTitle;

	// Initialize each element in titleMaxSizes with the string size of each element in titles
	for (auto & title : titles) vecTitleMaxSizes.push_back(static_cast<short>(title.size()));

	file_in.open(ACCOUNTS_FILE);

	while (!file_in.eof()) {
		User user;
		io::File::read_account_from(file_in, user);
		std::ifstream fileUserInfo = open_file(user.get_username());
		io::File::read_info_from(fileUserInfo, user);
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
		io::File::read_account_from(file_in, user);
		std::ifstream fileUserInfo = open_file(user.get_username());
		io::File::read_info_from(fileUserInfo, user);
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

char menu_options(std::wstring _title, std::vector<std::wstring> _options, box::BorderStyle _style) {
	typedef box::Border Border;
	wchar_t fill_style = ' ';
	short index_size = 4;
	short label_size = get_max_size_of_labels(_options) + 1;

	if (_options.size() > 9) index_size++;
	short width = index_size + label_size;

	system("cls");
	_setmode(_fileno(stdout), _O_U16TEXT);
	textAndBackgroundColor(Color::LIGHT_YELLOW);
	std::wcout << Border::top_left(_style) << std::setfill(Border::horizontal(_style)) << _title << std::setw(static_cast<short>(width - _title.size() + 1)) << Border::top_right(_style) << std::setfill(fill_style) << std::endl;
	for (short i = 0; i < _options.size(); i++) {
		std::wstring index = fill_style + std::to_wstring(i + 1) + L'.' + fill_style;
		std::wcout << Border::vertical(_style);
		textAndBackgroundColor(Color::LIGHT_GREEN);
		_options.size() < 10 ? std::wcout << index : std::wcout << std::setw(index_size) << std::right << index;
		textAndBackgroundColor(Color::BRIGHT_WHITE);
		std::wcout << _options[i];
		textAndBackgroundColor(Color::LIGHT_YELLOW);
		std::wcout << std::setw(label_size - _options[i].size() + 1) << Border::vertical(_style) << std::endl;
	}
	textAndBackgroundColor(Color::LIGHT_YELLOW);
	std::wcout << Border::bottom_left(_style) << std::setfill(Border::horizontal(_style)) << std::setw(width + 1) << Border::bottom_right(_style) << std::setfill(fill_style) << std::endl;
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
