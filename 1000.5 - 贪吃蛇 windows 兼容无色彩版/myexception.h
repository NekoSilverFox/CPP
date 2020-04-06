#pragma once
#include <iostream>
#include <exception>
using namespace std;

class MyException : public exception // !!!!!! 自己编写的异常要继承于 exception 类！！！！
{
public:
	MyException(string errorInfo) // 1. 要重写有参构造函数
	{
		this->m_error = errorInfo;
	}
	~MyException() {}

	virtual const char* what() // 2. 要重写用于打印错误信息的 what() 函数
	{
		//返回 错误信息
		return this->m_error.c_str(); // 将 string 转为 char*        stringxxxx.c_str()
	}

private:
	string m_error;
};
