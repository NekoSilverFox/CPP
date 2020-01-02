#include<iostream>
#include<stdexcept> // 注意包含头文件
#include<iostream>
using namespace std;

class MyOutofRange : public exception // !!!!!! 自己编写的异常要继承于 exception 类！！！！
{
public:
	MyOutofRange(string errorInfo) // 1. 要重写有参构造函数
	{
		this->m_error = errorInfo;
	}
	~MyOutofRange() {}

	virtual const char* what() // 2. 要重写用于打印错误信息的 what() 函数
	{
		//返回 错误信息
		return this->m_error.c_str(); // 将 string 转为 char*        stringxxxx.c_str()
	}

private:
	string m_error;
};

class Person
{
public:
	Person(string name, int age)
	{
		this->m_name = name;
		this->m_age = age;
		if (age < 0 || age > 120)
		{
			throw MyOutofRange("你是不是憨憨？？？？？");
		}
	}

	string m_name;
	int m_age;
};

int main()
{
	try
	{
		Person p1("Nick", -10);
	}
	catch (MyOutofRange& err)
	{
		cout << err.what() << endl;
	}

}