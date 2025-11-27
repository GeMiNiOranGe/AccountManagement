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
    explicit User(
        const std::string & username = "",
        const std::string & full_name = "",
        const std::string & address = "",
        const std::string & phone_number = "",
        const std::string & email_address = ""
    );
    User(const User & user);
    ~User();

    const std::string & get_username() const;
    const std::string & get_full_name() const;
    const std::string & get_address() const;
    const std::string & get_phone_number() const;
    const std::string & get_email_address() const;

    void set_username(const std::string & value);
    void set_full_name(const std::string & value);
    void set_address(const std::string & value);
    void set_phone_number(const std::string & value);
    void set_email_address(const std::string & value);
};

inline User::User(
    const std::string & username,
    const std::string & full_name,
    const std::string & address,
    const std::string & phone_number,
    const std::string & email_address
) {
    this->username_ = username;
    this->full_name_ = full_name;
    this->address_ = address;
    this->phone_number_ = phone_number;
    this->email_address_ = email_address;
}

inline User::User(const User & user) {
    this->username_ = user.username_;
    this->full_name_ = user.full_name_;
    this->address_ = user.address_;
    this->phone_number_ = user.phone_number_;
    this->email_address_ = user.email_address_;
}

inline User::~User() {}

inline const std::string & User::get_username() const {
    return this->username_;
}

inline const std::string & User::get_full_name() const {
    return this->full_name_;
}

inline const std::string & User::get_address() const {
    return this->address_;
}

inline const std::string & User::get_phone_number() const {
    return this->phone_number_;
}

inline const std::string & User::get_email_address() const {
    return this->email_address_;
}

inline void User::set_username(const std::string & value) {
    this->username_ = value;
}

inline void User::set_full_name(const std::string & value) {
    this->full_name_ = value;
}

inline void User::set_address(const std::string & value) {
    this->address_ = value;
}

inline void User::set_phone_number(const std::string & value) {
    this->phone_number_ = value;
}

inline void User::set_email_address(const std::string & value) {
    this->email_address_ = value;
}

#endif  // end USER_HPP
