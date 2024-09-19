#include "EmptyListException.h"


EmptyListException::EmptyListException(std::string msg)
{
	_msg = msg;
}


EmptyListException::~EmptyListException()
{
}

const char * EmptyListException::what() const
{
	return _msg.c_str();
}