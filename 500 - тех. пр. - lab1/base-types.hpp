#pragma once
#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP
#include<iostream>
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

// ----------------------------------------------------------------------------

struct point_t
{
	double x, y;
};

struct rectangle_t
{
	double width, height;
	point_t pos;
};

#endif