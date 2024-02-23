#pragma once
#ifndef ACCOUNTMANAGEMENT_HPP
#define ACCOUNTMANAGEMENT_HPP

#include "Account.hpp"
#include "FileManager.hpp"
#include "IReader.hpp"
#include "IWriter.hpp"

class AccountManagement /* :public IReader, public IWriter */ {
private:
	Account account;
public:
	AccountManagement(const Account & _account = Account());

	const Account & get_account() const;
	void set_account(const Account &_account);

	// void read_file(std::ifstream & _fin) override;
	// void write_file(std::ofstream & _fout) override;

	bool is_success_change_pass(
		std::string _username,
		std::string _current_password,
		std::string _new_password,
		std::string _confirm_new_password
	);

	void create_account(std::string _username);
	void delete_account(std::string _username);
};

#endif // end ACCOUNTMANAGEMENT_HPP