#include "ui_have_no_ux.hpp"

short get_max_size_of_labels(std::vector<std::wstring> _labels) {
	short label_size = 0;
	for (auto & label : _labels)
		if (label_size < label.size())
			label_size = static_cast<short>(label.size());
	return label_size;
}

std::pair<std::string, std::string> show_login_form(box::BorderStyle _style) {
	typedef box::Border Border;
	std::string username, password;
	std::string title = "Log in";
	std::string username_label = "Username: ";
	std::string password_label = "Password: ";
	wchar_t fill_style = ' ';
	Account account;

	short width = 30;
	short new_width = width + 1;
	if (is_odd(title.size())) width++;
	short align_middle = static_cast<short>(width - title.size()) / 2;

	system("cls");
	_setmode(_fileno(stdout), _O_U16TEXT);
	std::wcout << bgreen;
	std::wcout << Border::top_left(_style) << std::setfill(Border::horizontal(_style)) << std::setw(new_width) << Border::top_right(_style) << std::setfill(fill_style) << std::endl;
	for (int i = 0; i < 3; i++)
		std::wcout << Border::vertical(_style) << std::setw(new_width) << Border::vertical(_style) << std::endl;
	std::wcout << Border::left(_style) << std::setfill(Border::horizontal(_style)) << std::setw(new_width) << Border::right(_style) << std::setfill(fill_style) << std::endl;
	for (int i = 0; i < 5; i++)
		std::wcout << Border::vertical(_style) << std::setw(new_width) << Border::vertical(_style) << std::endl;
	std::wcout << Border::bottom_left(_style) << std::setfill(Border::horizontal(_style)) << std::setw(new_width) << Border::bottom_right(_style) << std::setfill(fill_style) << std::endl;
	_setmode(_fileno(stdout), _O_TEXT);

	std::cout << baqua;
	go_to_xy(align_middle + 1, 2);
	std::cout << title;
	go_to_xy(2, 6);
	std::cout << username_label;
	go_to_xy(2, 8);
	std::cout << password_label;

	std::cout << bwhite;
	go_to_xy(static_cast<short>(username_label.size()) + 2, 6);
	getline(std::cin, username);
	go_to_xy(static_cast<short>(password_label.size()) + 2, 8);
	encode_password(password);
	go_to_xy(0, 11);

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
	std::wcout << Border::vertical(_style) << std::right << std::setw(align_middle + _title.size()) << _title << std::setw(align_middle + static_cast<short>(1)) << Border::vertical(_style) << std::endl;
	std::wcout << Border::vertical(_style) << std::setw(new_sum_size) << Border::vertical(_style) << std::endl;

	for (auto & element : _labels) {
		std::wcout << Border::left(_style) << std::setfill(Border::horizontal(_style)) << std::setw(new_sum_size) << Border::right(_style) << std::setfill(fill_style) << std::endl;
		std::wcout << Border::vertical(_style) << std::right << std::setw(label_size) << element << std::setw(fill_size + static_cast<short>(1)) << Border::vertical(_style) << std::endl;
		std::wcout << Border::vertical(_style) << std::setw(new_sum_size) << Border::vertical(_style) << std::endl;
	}

	std::wcout << Border::bottom_left(_style) << std::setfill(Border::horizontal(_style)) << std::setw(new_sum_size) << Border::bottom_right(_style) << std::setfill(L' ') << std::endl;
	_setmode(_fileno(stdout), _O_TEXT);
}

void show_a_part_border(std::vector<std::pair<std::string, short>> number_of_fill, Position _position, box::BorderStyle _style) {
	typedef box::Border Border;
	std::wcout << std::setfill(Border::horizontal(_style)) << std::right;

	_setmode(_fileno(stdout), _O_U16TEXT);
	if (_position == Position::FIRST)
		std::wcout << Border::top_left(_style);
	else if (_position == Position::MIDDLE)
		std::wcout << Border::left(_style);
	else if (_position == Position::LAST)
		std::wcout << Border::bottom_left(_style);

	for (auto & element : number_of_fill) {
		short string_with_space = element.second + 2;
		std::wcout << Border::horizontal(_style) << std::setw(string_with_space);
		if (element != *(number_of_fill.end() - 1)) {
			if (_position == Position::FIRST)
				std::wcout << Border::top(_style);
			else if (_position == Position::MIDDLE)
				std::wcout << Border::center(_style);
			else if (_position == Position::LAST)
				std::wcout << Border::bottom(_style);
		}
	}

	if (_position == Position::FIRST)
		std::wcout << Border::top_right(_style);
	else if (_position == Position::MIDDLE)
		std::wcout << Border::right(_style);
	else if (_position == Position::LAST)
		std::wcout << Border::bottom_right(_style);
	_setmode(_fileno(stdout), _O_TEXT);
}

// Output to console in given format: 
// Pair (maxSize: maximum cell size, wString: One sentence), BorderStyle: Single(customizable)
void show_info_account(std::vector<std::pair<std::wstring, short>> _max_size_and_wstring_pairs, Color _text_color, wchar_t _fill_type, box::BorderStyle _style) {
	//TODO: make enum for fill type
	typedef box::Border Border;
	_setmode(_fileno(stdout), _O_U16TEXT);
	std::wcout << Border::vertical(_style);
	std::wcout << std::setfill(_fill_type) << std::left;
	for (auto & element : _max_size_and_wstring_pairs) {
		short max_size = static_cast<short>(element.second);
		set_color(_text_color);
		std::wcout << _fill_type << std::setw(max_size) << element.first << _fill_type;
		std::wcout << bwhite;
		std::wcout << Border::vertical(_style);
	}
	std::wcout << std::setfill(L' ');
	_setmode(_fileno(stdout), _O_TEXT);
}

void show_info_accounts() {
	std::vector<std::pair<std::string, short>> titles = {
		std::make_pair("No.", 3),
		std::make_pair("Username", 8),
		std::make_pair("Password", 8),
		std::make_pair("Full name", 9),
		std::make_pair("Address", 7),
		std::make_pair("Phone number", 12),
		std::make_pair("Email address", 13)
	};
	std::vector<std::vector<std::string>> contents;
	std::vector<std::pair<std::wstring, short>> vec_title_and_max_size;
	std::ifstream fin;

	std::unordered_map<std::string, User> user_map = UserStorage::get_users_map();

	fin.open(ACCOUNTS_FILE);
	for (int index = 1; !fin.eof(); index++) {
		User user;
		Account account;

		AccountFileIO::read_file(fin, account);
		user = user_map[account.get_username()];

		std::vector<std::string> properties = {
			std::to_string(index),
			account.get_username(),
			account.get_password(),
			user.get_full_name(),
			user.get_address(),
			user.get_phone_number(),
			user.get_email_address()
		};

		// Find the maximum size of each table cell, horizontally
		if (account.get_username() != "") {
			contents.push_back(properties);
			for (short i = 0; i < properties.size(); i++)
				if (titles.at(i).second < properties.at(i).size())
					titles.at(i).second = static_cast<short>(properties.at(i).size());
		}
	}
	fin.close();

	show_a_part_border(titles, Position::FIRST);
	std::cout << std::endl;

	// Show titles
	for (short i = 0; i < titles.size(); i++)
		vec_title_and_max_size.push_back(std::make_pair(Convert::to_wstring(titles.at(i).first), titles.at(i).second));
	show_info_account(vec_title_and_max_size, Color::BRIGHT_YELLOW);
	std::cout << std::endl;

	show_a_part_border(titles, Position::MIDDLE);
	std::cout << std::endl;

	// Show all account information
	for (int index = 0; index < contents.size(); index++) {
		auto line = contents.at(index);

		std::vector<std::pair<std::wstring, short>> vec_title_and_max_size_temp;
		for (short i = 0; i < titles.size(); i++)
			vec_title_and_max_size_temp.push_back(std::make_pair(Convert::to_wstring(line.at(i)), titles.at(i).second));
		show_info_account(vec_title_and_max_size_temp, Color::BRIGHT_YELLOW);
		std::cout << std::endl;
		
		if (index != contents.size() - 1) {
			show_a_part_border(titles, Position::MIDDLE);
			std::cout << std::endl;
		}
	}
	show_a_part_border(titles, Position::LAST);
}

char menu_options(std::wstring _title, std::vector<std::wstring> _options, std::vector<std::wstring> _sub_options, box::BorderStyle _style) {
	typedef box::Border Border;
	wchar_t fill_style = ' ';
	short index_size = 4;
	short title_size = static_cast<short>(_title.size());
	short label_size = get_max_size_of_labels(_options) + 1;

	if (title_size > label_size) label_size = title_size;

	if (_options.size() > 9) index_size++;
	short width = index_size + label_size;

	system("cls");
	_setmode(_fileno(stdout), _O_U16TEXT);
	std::wcout << byellow;
	std::wcout << Border::top_left(_style) << std::setfill(Border::horizontal(_style)) << _title << std::setw(static_cast<short>(width - _title.size() + 1)) << Border::top_right(_style) << std::setfill(fill_style) << std::endl;
	for (short i = 0; i < _options.size(); i++) {
		std::wstring index = fill_style + std::to_wstring(i + 1) + L'.' + fill_style;
		std::wcout << Border::vertical(_style);
		std::wcout << bgreen;
		_options.size() < 10 ? std::wcout << index : std::wcout << std::right << std::setw(index_size) << index;
		std::wcout << bwhite;
		std::wcout << _options[i];
		std::wcout << byellow;
		std::wcout << std::right << std::setw(label_size - _options[i].size() + 1) << Border::vertical(_style) << std::endl;
	}
	std::wcout << byellow;
	std::wcout << Border::bottom_left(_style) << std::setfill(Border::horizontal(_style)) << std::setw(width + static_cast<short>(1)) << Border::bottom_right(_style) << std::setfill(fill_style) << std::endl;

	std::wcout << bgreen;
	if (!_sub_options.empty())
		for (auto & element : _sub_options)
			std::wcout << element << std::endl;

	std::wcout << baqua;
	std::wcout << "Moi ban chon chuc nang" << std::endl;
	_setmode(_fileno(stdout), _O_TEXT);

	return _getch();
}
