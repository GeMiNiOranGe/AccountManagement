#pragma once
#ifndef ADMINISTRATOR_FORM_HPP
#define ADMINISTRATOR_FORM_HPP

#include "display/base_form.hpp"
#include "display/console_color.hpp"
#include "display/sysutils.hpp"
#include "display/ui_have_no_ux.hpp"
#include "service/account_service.hpp"
#include "service/user_service.hpp"
#include "storage/config.hpp"

class AdministratorForm : public BaseForm {
private:
    static InputResult prompt_username(const std::string & header);

    /**
     * @param header The header to display in the prompt
     * @param must_exist true: username must exist, false: username must not
     * exist
     * @return InputResult The result of the input prompt
     */
    static InputResult
    prompt_username_until(const std::string & header, bool must_exist);

    static void handle_search();
    static void handle_create();
    static void handle_delete();
    static void handle_update();
    static void handle_show_accounts();

public:
    static void show();
};

#endif  // end ADMINISTRATOR_FORM_HPP
