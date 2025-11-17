#pragma once
#ifndef CONSOLE_IO_HPP
#define CONSOLE_IO_HPP

#include "display/console_color.hpp"
#include "display/utilities.hpp"
#include "storage/user.hpp"

namespace console {
void read_account(User & _user);
void read_info(User & _user);

void write_account(User _user);
void write_info(User _user);
}  // namespace console

#endif  // end CONSOLE_IO_HPP
