#pragma once
#ifndef ADMINISTRATOR_FORM_HPP
#define ADMINISTRATOR_FORM_HPP

#include "console_color.hpp"
#include "handle_console.hpp"
#include "ui_have_no_ux.hpp"

class AdministratorForm {
private:
    static std::string prompt_username(const std::string &header);
    static void handle_add();
    static void handle_delete();
    static void handle_search();
    static void handle_edit();
    static void handle_show_information();

public:
    static void show();
};

#endif // end ADMINISTRATOR_FORM_HPP
