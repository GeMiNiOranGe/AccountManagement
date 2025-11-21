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
