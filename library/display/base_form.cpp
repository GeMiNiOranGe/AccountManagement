#include "display/base_form.hpp"

const int BaseForm::width_ = 80;
const box::Border BaseForm::border_;

void BaseForm::setup_window_layout() {
    window::resize(640, 500);
    window::move_to_center();
}

void BaseForm::draw_header(std::string header) {
    std::cout << border_.top_left()
              << box::utf8_setw(width_ - 2, border_.horizontal())
              << border_.top_right() << std::endl;

    std::cout << border_.vertical() << byellow
              << box::utf8_setw(width_ - 2, " ", " > " + header) << reset_color
              << border_.vertical() << std::endl;

    std::cout << border_.bottom_left()
              << box::utf8_setw(width_ - 2, border_.horizontal())
              << border_.bottom_right() << std::endl;
}

void BaseForm::pause_screen() {
    std::cout << std::endl;
    std::cout << box::utf8_setw(width_, border_.horizontal()) << std::endl;
    system("pause");
}

void BaseForm::write_fields(
    std::string header,
    std::vector<std::pair<std::string, std::string>> fields
) {
    std::cout << byellow << "[+] " + header << reset_color << std::endl;

    size_t size = fields.size();
    for (size_t i = 0; i < size - 1; i++) {
        std::cout << "    " << border_.left() << border_.horizontal() << baqua
                  << fields[i].first << reset_color << fields[i].second
                  << std::endl;
    }
    std::cout << "    " << border_.bottom_left() << border_.horizontal()
              << baqua << fields[size - 1].first << reset_color
              << fields[size - 1].second << std::endl;
}

std::vector<std::string>
BaseForm::read_fields(std::string header, std::vector<std::string> fields) {
    std::vector<std::string> values;

    std::cout << border_.top_left()
              << box::utf8_setw(width_ - 2, border_.horizontal())
              << border_.top_right() << std::endl;
    std::cout << border_.vertical() << byellow
              << box::utf8_setw(width_ - 2, " ", " > " + header) << reset_color
              << border_.vertical() << std::endl;
    std::cout << border_.left()
              << box::utf8_setw(width_ - 2, border_.horizontal())
              << border_.right() << std::endl;
    for (auto && field : fields) {
        std::cout << border_.vertical() << baqua << field << reset_color;
        // Here, using `std::cin` can display the correct UI. Don't ask me why,
        // I don't know.
        InputResult input_result = input_text();
        values.push_back(input_result.value);
        std::cout << box::utf8_setw(
            width_ - 2 - field.size() - input_result.value.size(), " "
        );
        std::cout << border_.vertical() << reset_color << std::endl;
    }
    std::cout << border_.bottom_left()
              << box::utf8_setw(width_ - 2, border_.horizontal())
              << border_.bottom_right() << std::endl;

    return values;
}

char BaseForm::menu_options(
    std::string header,
    std::vector<std::string> options,
    std::vector<std::string> sub_options
) {
    std::string fill_style = " ";

    system("cls");
    draw_header(header);

    if (!sub_options.empty()) {
        std::cout << bgreen;
        for (auto && element : sub_options) {
            std::cout << element << std::endl;
        }
        std::cout << reset_color;
    }

    std::cout << std::endl;
    std::cout << byellow << "[+] Available actions" << reset_color << std::endl;

    size_t size = options.size();
    for (size_t i = 0; i < size; i++) {
        std::cout << "    "
                  << (i != size - 1 ? border_.left() : border_.bottom_left())
                  << border_.horizontal() << options[i] << std::endl;
    }

    std::cout << std::endl;
    std::cout << baqua << "Choose an option" << reset_color << std::endl;

    return _getch();
}
