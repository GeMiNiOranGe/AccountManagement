#pragma once
#ifndef CONSOLEIO_HPP
#define CONSOLEIO_HPP

#include <string>
#include "User.h"
#include "AccountType.h"
#include "HandleMiscellaneous.h"

namespace console {
	namespace read {
		void account(User & user);
		void info(User & user);
		void all(User & user);
	} // namespace read
	namespace write {
		void account(User user);
		void info(User user);
		void all(User user);
	} // namespace write
} // namespace console

#endif // end CONSOLEIO_HPP