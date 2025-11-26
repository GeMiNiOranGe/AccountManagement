#pragma once
#ifndef EMPLOYEE_FORM_HPP
#define EMPLOYEE_FORM_HPP

#include "display/base_form.hpp"
#include "service/account_service.hpp"
#include "storage/user_storage.hpp"

class EmployeeForm : public BaseForm {
private:
    static void handle_change_password(const std::string & username);
    static void handle_view_personal_information(const std::string & username);

public:
    static void show(const std::string & username);
};

#endif  // end EMPLOYEE_FORM_HPP
