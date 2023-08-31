#pragma once
#ifndef CONSOLEIO_HPP
#define CONSOLEIO_HPP

#include "User.hpp"
#include "HandleMiscellaneous.hpp"

namespace console {
	void read_account(User &_user);
	void read_info(User &_user);
	
	void write_account(User _user);
	void write_info(User _user);
} // namespace console

#endif // end CONSOLEIO_HPP