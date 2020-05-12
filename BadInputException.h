#pragma once
#include <exception>
#include <string>

class BadInputException : public std::exception
{
public:
	 std::string errorMsg;

	BadInputException();
};

