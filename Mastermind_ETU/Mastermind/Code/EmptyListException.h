#pragma once
#include <iostream>

class EmptyListException : public std::exception
{
public:
	EmptyListException(std::string msg = "");
	~EmptyListException();

	virtual const char * what() const;

private:
	std::string _msg;
};

