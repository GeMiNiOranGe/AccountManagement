#include "display/ui_have_no_ux.hpp"

size_t get_max_size_of_strings(std::vector<std::string> strings) {
    size_t max_size = 0;

    for (auto & str : strings) {
        if (max_size < str.size()) {
            max_size = str.size();
        }
    }

    return max_size;
}

std::pair<bool, std::pair<std::string, std::string>> show_login_form(
    box::BorderStyle style
) {
    box::Border border(style);
    InputResult username, password;
    std::string title = "Log in";
    std::string username_label = "Username: ";
    std::string password_label = "Password: ";
    wchar_t fill_style = ' ';
    Account account;

    size_t width = 30;
    size_t align_middle = (width - title.size()) / 2;

    system("cls");
    std::cout << bgreen;
    std::cout << border.top_left() << box::utf8_setw(width, border.horizontal())
              << border.top_right() << std::endl;
    for (int i = 0; i < 3; i++) {
        std::cout << border.vertical() << box::utf8_setw(width)
                  << border.vertical() << std::endl;
    }
    std::cout << border.left() << box::utf8_setw(width, border.horizontal())
              << border.right() << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << border.vertical() << box::utf8_setw(width)
                  << border.vertical() << std::endl;
    }
    std::cout << border.bottom_left()
              << box::utf8_setw(width, border.horizontal())
              << border.bottom_right() << std::endl;
    std::cout << "<ESC> to quit" << std::endl;

    std::cout << baqua;
    go_to_xy(static_cast<short>(align_middle) + 1, 2);
    std::cout << title;
    go_to_xy(2, 6);
    std::cout << username_label;
    go_to_xy(2, 8);
    std::cout << password_label;
    std::cout << reset_color;

    go_to_xy(static_cast<short>(username_label.size()) + 2, 6);
    username = input_text();
    if (username.cancelled) {
        return {true, {"", ""}};
    }

    go_to_xy(static_cast<short>(password_label.size()) + 2, 8);
    password = input_text(true);
    if (password.cancelled) {
        return {true, {"", ""}};
    }

    return {false, {username.value, password.value}};
}
void form_info(
    std::string title,
    std::vector<std::string> labels,
    box::BorderStyle style,
    size_t input_size
) {
    box::Border border(style);

    // Get max size of label
    size_t label_max_size = get_max_size_of_strings(labels);
    size_t total_size = label_max_size + input_size;

    // Show form
    std::cout << border.top_left()
              << box::utf8_setw(total_size, border.horizontal())
              << border.top_right() << std::endl;
    std::cout << border.vertical() << box::utf8_setw(total_size, " ")
              << border.vertical() << std::endl;
    std::cout << border.vertical()
              << box::utf8_setw(total_size, " ", title, box::Alignment::CENTER)
              << border.vertical() << std::endl;
    std::cout << border.vertical() << box::utf8_setw(total_size, " ")
              << border.vertical() << std::endl;

    for (auto & element : labels) {
        std::cout << border.left()
                  << box::utf8_setw(total_size, border.horizontal())
                  << border.right() << std::endl;
        std::cout << border.vertical()
                  << box::utf8_setw(
                         total_size, " ", element, box::Alignment::LEFT
                     )
                  << border.vertical() << std::endl;
        std::cout << border.vertical() << box::utf8_setw(total_size, " ")
                  << border.vertical() << std::endl;
    }

    std::cout << border.bottom_left()
              << box::utf8_setw(total_size, border.horizontal())
              << border.bottom_right() << std::endl;
}

void show_a_part_border_horizontal(
    box::Border border,
    std::vector<std::pair<std::string, size_t>> number_of_fill,
    std::string middle,
    std::string last
) {
    size_t size = number_of_fill.size();
    for (int i = 0; i < size - 1; i++) {
        std::cout << box::utf8_setw(
            number_of_fill[i].second + 2, border.horizontal()
        );
        std::cout << middle;
    }
    std::cout << box::utf8_setw(
        number_of_fill[size - 1].second + 2, border.horizontal()
    );
    std::cout << last;
};

void show_a_part_border(
    std::vector<std::pair<std::string, size_t>> number_of_fill,
    Position position,
    box::BorderStyle style
) {
    box::Border border(style);

    if (position == Position::FIRST) {
        std::cout << border.top_left();
        show_a_part_border_horizontal(
            border, number_of_fill, border.top(), border.top_right()
        );
        return;
    }
    if (position == Position::MIDDLE) {
        std::cout << border.left();
        show_a_part_border_horizontal(
            border, number_of_fill, border.center(), border.right()
        );
        return;
    }
    if (position == Position::LAST) {
        std::cout << border.bottom_left();
        show_a_part_border_horizontal(
            border, number_of_fill, border.bottom(), border.bottom_right()
        );
        return;
    }
}

// Output to console in given format:
// Pair (maxSize: maximum cell size, wString: One sentence), BorderStyle:
// Single(customizable)
void show_info_account(
    std::vector<std::pair<std::string, size_t>> max_size_and_wstring_pairs,
    Color text_color,
    std::string fill_type,
    box::BorderStyle style
) {
    box::Border border(style);

    std::cout << border.vertical();
    for (auto & element : max_size_and_wstring_pairs) {
        size_t max_size = element.second;
        set_color(text_color);
        std::cout << fill_type;
        std::cout << box::utf8_setw(max_size, fill_type, element.first);
        std::cout << fill_type;
        std::cout << reset_color << border.vertical();
    }
}

void show_info_accounts() {
    std::vector<std::pair<std::string, size_t>> titles = {
        std::make_pair("No.", 3),
        std::make_pair("Username", 8),
        std::make_pair("Password", 8),
        std::make_pair("Full name", 9),
        std::make_pair("Address", 7),
        std::make_pair("Phone number", 12),
        std::make_pair("Email address", 13)
    };
    std::vector<std::vector<std::string>> rows;
    std::ifstream fin;

    std::unordered_map<std::string, User> user_map =
        UserStorage::get_users_map();

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
            rows.push_back(properties);
            for (size_t i = 0; i < properties.size(); i++) {
                if (titles.at(i).second < properties.at(i).size()) {
                    titles.at(i).second = properties.at(i).size();
                }
            }
        }
    }
    fin.close();

    show_a_part_border(titles, Position::FIRST);
    std::cout << std::endl;

    // Show titles
    show_info_account(titles, Color::BRIGHT_YELLOW);
    std::cout << std::endl;

    show_a_part_border(titles, Position::MIDDLE);
    std::cout << std::endl;

    // Show all account information
    for (int i = 0; i < rows.size(); i++) {
        std::vector<std::string> row = rows.at(i);

        std::vector<std::pair<std::string, size_t>> vec_title_and_max_size_temp;
        for (size_t j = 0; j < titles.size(); j++) {
            vec_title_and_max_size_temp.push_back(
                std::make_pair(row.at(j), titles.at(j).second)
            );
        }

        show_info_account(vec_title_and_max_size_temp, Color::BRIGHT_YELLOW);
        std::cout << std::endl;

        if (i != rows.size() - 1) {
            show_a_part_border(titles, Position::MIDDLE);
            std::cout << std::endl;
        }
    }
    show_a_part_border(titles, Position::LAST);
}

char menu_options(
    std::string title,
    std::vector<std::string> options,
    std::vector<std::string> sub_options,
    box::BorderStyle style
) {
    box::Border border(style);
    std::string fill_style = " ";
    size_t width = get_max_size_of_strings(options);

    if (title.size() > width) {
        width = title.size();
    }

    system("cls");
    std::cout << byellow;
    std::cout << border.top_left()
              << box::utf8_setw(width, border.horizontal(), title)
              << border.top_right() << std::endl;
    for (size_t i = 0; i < options.size(); i++) {
        std::cout << border.vertical() << bwhite
                  << box::utf8_setw(width, fill_style, options[i]) << byellow
                  << border.vertical() << std::endl;
    }
    std::cout << byellow;
    std::cout << border.bottom_left()
              << box::utf8_setw(width, border.horizontal())
              << border.bottom_right() << std::endl;

    if (!sub_options.empty()) {
        std::cout << bgreen;
        for (auto && element : sub_options) {
            std::cout << element << std::endl;
        }
    }

    std::cout << baqua << "Choose an option" << reset_color << std::endl;

    return _getch();
}
