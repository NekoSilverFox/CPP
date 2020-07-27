#pragma once
#include<string>
#include<stdexcept>
using namespace std;

// ------------------------------ ERROR INFO ------------------------------
class MyErrorInfo : public exception
{
public:
	MyErrorInfo(string errorInfo)
	{
		this->m_error = errorInfo;
	}
	~MyErrorInfo() {}

	virtual const char* what()
	{
		return this->m_error.c_str();
	}

private:
	string m_error;
};
