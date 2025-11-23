#pragma once
#ifndef MAIN_FORM_HPP
#define MAIN_FORM_HPP

#include "display/administrator_form.hpp"
#include "display/employee_form.hpp"

class MainForm : public BaseForm {
private:
    static std::pair<bool, std::pair<std::string, std::string>>
    show_login_form();

public:
    static void show();
};

#endif  // end MAIN_FORM_HPP
