#pragma once
#ifndef USER_HPP
#define USER_HPP

#include <string>

class User {
private:
    std::string username_;
    std::string full_name_;
    std::string address_;
    std::string phone_number_;
    std::string email_address_;

public:
    User(std::string username = "", std::string full_name = "", std::string address = "", std::string phone_number = "", std::string email_address = "");
    User(const User &user);
    ~User();

    const std::string &get_username() const;
    const std::string &get_full_name() const;
    const std::string &get_address() const;
    const std::string &get_phone_number() const;
    const std::string &get_email_address() const;

    void set_username(const std::string &value);
    void set_full_name(const std::string &value);
    void set_address(const std::string &value);
    void set_phone_number(const std::string &value);
    void set_email_address(const std::string &value);
};

#endif // end USER_HPP
