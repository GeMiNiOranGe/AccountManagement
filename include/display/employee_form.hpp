#pragma once
#ifndef EMPLOYEE_FORM_HPP
#define EMPLOYEE_FORM_HPP

#include "display/handle_console.hpp"
#include "display/ui_have_no_ux.hpp"
#include "service/account_service.hpp"

class EmployeeForm {
private:
    static void handle_change_password(const Account & account);
    static void handle_view_personal_information(const Account & account);

public:
    static void show(const Account & account);
};

#endif  // end EMPLOYEE_FORM_HPP
