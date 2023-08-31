#pragma once
#ifndef LOGINSTATUS_HPP
#define LOGINSTATUS_HPP

enum class LoginStatus {
	SUCCESS,
	INVALID_INPUT,
	INVALID_ACCOUNT,
	OTHER_ERROR
};

#endif // end LOGINSTATUS_HPP