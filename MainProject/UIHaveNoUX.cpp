#include "UIHaveNoUX.hpp"

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
	set_color(Color::LIGHT_GREEN);
	std::wcout << Border::top_left(_style) << std::setfill(Border::horizontal(_style)) << std::setw(new_width) << Border::top_right(_style) << std::setfill(fill_style) << std::endl;
	for (int i = 0; i < 3; i++)
		std::wcout << Border::vertical(_style) << std::setw(new_width) << Border::vertical(_style) << std::endl;
	std::wcout << Border::left(_style) << std::setfill(Border::horizontal(_style)) << std::setw(new_width) << Border::right(_style) << std::setfill(fill_style) << std::endl;
	for (int i = 0; i < 5; i++)
		std::wcout << Border::vertical(_style) << std::setw(new_width) << Border::vertical(_style) << std::endl;
	std::wcout << Border::bottom_left(_style) << std::setfill(Border::horizontal(_style)) << std::setw(new_width) << Border::bottom_right(_style) << std::setfill(fill_style) << std::endl;
	_setmode(_fileno(stdout), _O_TEXT);

	set_color(Color::LIGHT_AQUA);
	go_to_xy(align_middle + 1, 2);
	std::cout << title;
	go_to_xy(2, 6);
	std::cout << username_label;
	go_to_xy(2, 8);
	std::cout << password_label;

	set_color(Color::BRIGHT_WHITE);
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

void show_a_part_border(std::vector<short> number_of_fill, Position _position, box::BorderStyle _style) {
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
		short string_with_space = element + 2;
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
void show_info_account(std::vector<std::pair<short, std::wstring>> _max_size_and_wstring_pairs, Color _text_color, wchar_t _fill_type, box::BorderStyle _style) {
	//TODO: make enum for fill type
	typedef box::Border Border;
	_setmode(_fileno(stdout), _O_U16TEXT);
	std::wcout << Border::vertical(_style);
	std::wcout << std::setfill(_fill_type) << std::left;
	for (auto & element : _max_size_and_wstring_pairs) {
		short max_size = static_cast<short>(element.first);
		set_color(_text_color);
		std::wcout << _fill_type << std::setw(max_size) << element.second << _fill_type;
		set_color(Color::BRIGHT_WHITE);
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
	std::vector<short> title_max_sizes;
	std::vector<std::pair<short, std::wstring>> vec_title_max_size_and_title;
	std::ifstream fin;

	// Initialize each element in title_max_sizes with the string size of each element in titles
	for (auto & title : titles) title_max_sizes.push_back(static_cast<short>(title.size()));

	fin.open(ACCOUNTS_FILE);

	while (!fin.eof()) {
		User user;
		Account account;

		FileManager::read_file(fin, account);
		std::ifstream file_info = FileManager::open_file(account.get_username());
		FileManager::read_file(file_info, user);

		// Get all properties in class User
		// TODO: convert to vector
		std::string * ptr_user_properties = user.get_properties();

		// Find the maximum size of each table cell, horizontally
		if (account.get_username() != "")
			for (short i = 0; i < titles_size; i++)
				if (title_max_sizes[i] < ptr_user_properties[i].size())
					title_max_sizes[i] = static_cast<short>(ptr_user_properties[i].size());

		file_info.close();
	}

	// Reset file pointer
	fin.clear();
	fin.seekg(0, std::ios::beg);

	show_a_part_border(title_max_sizes, Position::FIRST);
	std::cout << std::endl;

	// Show titles
	for (short i = 0; i < titles_size; i++)
		vec_title_max_size_and_title.push_back(std::make_pair(title_max_sizes[i], Convert::to_wstring(titles[i])));
	show_info_account(vec_title_max_size_and_title, Color::LIGHT_YELLOW);
	std::cout << std::endl;

	// Show all account information
	while (!fin.eof()) {
		User user;
		Account account;

		FileManager::read_file(fin, account);
		std::ifstream file_info = FileManager::open_file(account.get_username());
		FileManager::read_file(file_info, user);

		// Get all properties in class User
		std::string * ptr_user_properties = user.get_properties();

		std::vector<std::pair<short, std::wstring>> title_max_size_user_property;
		for (short i = 0; i < titles_size; i++)
			title_max_size_user_property.push_back(std::make_pair(title_max_sizes[i], Convert::to_wstring(ptr_user_properties[i])));

		// Show current account information
		if (account.get_username() != "") {
			show_a_part_border(title_max_sizes, Position::MIDDLE);
			std::cout << std::endl;

			show_info_account(title_max_size_user_property, Color::WHITE);
			std::cout << std::endl;
		}

		file_info.close();
	}

	show_a_part_border(title_max_sizes, Position::LAST);

	fin.close();
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
	set_color(Color::LIGHT_YELLOW);
	std::wcout << Border::top_left(_style) << std::setfill(Border::horizontal(_style)) << _title << std::setw(static_cast<short>(width - _title.size() + 1)) << Border::top_right(_style) << std::setfill(fill_style) << std::endl;
	for (short i = 0; i < _options.size(); i++) {
		std::wstring index = fill_style + std::to_wstring(i + 1) + L'.' + fill_style;
		std::wcout << Border::vertical(_style);
		set_color(Color::LIGHT_GREEN);
		_options.size() < 10 ? std::wcout << index : std::wcout << std::right << std::setw(index_size) << index;
		set_color(Color::BRIGHT_WHITE);
		std::wcout << _options[i];
		set_color(Color::LIGHT_YELLOW);
		std::wcout << std::right << std::setw(label_size - _options[i].size() + 1) << Border::vertical(_style) << std::endl;
	}
	set_color(Color::LIGHT_YELLOW);
	std::wcout << Border::bottom_left(_style) << std::setfill(Border::horizontal(_style)) << std::setw(width + static_cast<short>(1)) << Border::bottom_right(_style) << std::setfill(fill_style) << std::endl;

	set_color(Color::LIGHT_GREEN);
	if (!_sub_options.empty())
		for (auto & element : _sub_options)
			std::wcout << element << std::endl;

	set_color(Color::LIGHT_AQUA);
	std::wcout << "Moi ban chon chuc nang" << std::endl;
	_setmode(_fileno(stdout), _O_TEXT);

	return _getch();
}
