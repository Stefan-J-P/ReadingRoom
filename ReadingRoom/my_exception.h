#pragma once

#include "header.h"

class my_exception : public std::exception
{
private:
	std::string message_;
public:
	my_exception() = default;
	explicit my_exception(const std::string& message);
	std::string error_message() const;
	~my_exception() = default;
};

