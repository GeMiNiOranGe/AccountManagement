#include "user.hpp"

User::User(std::string username, std::string full_name, std::string address, std::string phone_number, std::string email_address) {
	this->username_ = username;
	this->full_name_ = full_name;
	this->address_ = address;
	this->phone_number_ = phone_number;
	this->email_address_ = email_address;
}

User::User(const User & user) {
	this->username_ = user.username_;
	this->full_name_ = user.full_name_;
	this->address_ = user.address_;
	this->phone_number_ = user.phone_number_;
	this->email_address_ = user.email_address_;
}

User::~User() {
}

const std::string & User::get_username() const {
	return this->username_;
}

const std::string & User::get_full_name() const {
	return this->full_name_;
}

const std::string & User::get_address() const {
	return this->address_;
}

const std::string & User::get_phone_number() const {
	return this->phone_number_;
}

const std::string & User::get_email_address() const {
	return this->email_address_;
}

void User::set_username(const std::string & value) {
	this->username_ = value;
}

void User::set_full_name(const std::string & value) {
	this->full_name_ = value;
}

void User::set_address(const std::string & value) {
	this->address_ = value;
}

void User::set_phone_number(const std::string & value) {
	this->phone_number_ = value;
}

void User::set_email_address(const std::string & value) {
	this->email_address_ = value;
}
