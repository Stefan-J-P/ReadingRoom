#include "my_exception.h"


my_exception::my_exception(const std::string& message)
{
	message_ = message;
}

std::string my_exception::error_message() const
{
	return "ERROR MESSAGE: " + message_;
}
