#pragma once
#ifndef ADMINISTRATOR_FORM_HPP
#define ADMINISTRATOR_FORM_HPP

#include "display/base_form.hpp"
#include "display/console_color.hpp"
#include "display/position.hpp"
#include "service/account_service.hpp"
#include "service/user_service.hpp"
#include "storage/config.hpp"

class AdministratorForm : public BaseForm {
private:
    /**
     * @param header The header to display in the prompt
     * @param must_exist true: username must exist, false: username must not
     * exist
     * @return InputResult The result of the input prompt
     */
    static InputResult
    prompt_username(const std::string & header, bool must_exist);

    static void handle_search();
    static void handle_create();
    static void handle_update();
    static void handle_delete();
    static void handle_show_accounts();

    static void show_a_part_border_horizontal(
        std::vector<std::pair<std::string, size_t>> number_of_fill,
        std::string middle,
        std::string last
    );
    static void show_a_part_border(
        std::vector<std::pair<std::string, size_t>> number_of_fill,
        Position position
    );
    static void show_info_account(
        std::vector<std::pair<std::string, size_t>> max_size_and_wstring_pairs,
        Color text_color,
        std::string fill_type = " "
    );
    static void show_info_accounts();

public:
    static void show();
};

#endif  // end ADMINISTRATOR_FORM_HPP
