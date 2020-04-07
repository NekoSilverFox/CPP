#pragma once
#include <iostream>
#include <exception>
using namespace std;

class MyException : public exception 
{
public:
	MyException(string errorInfo) 
	{
		this->m_error = errorInfo;
	}
	~MyException() {}

	virtual const char* what() 
	{
		return this->m_error.c_str();
	}

private:
	string m_error;
};
