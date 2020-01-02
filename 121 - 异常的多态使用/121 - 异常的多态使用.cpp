#include<iostream>
using namespace std;

//异常基类
class MyException
{
public:
	virtual void printError() = 0;
};

class OutofRangeException : public MyException
{
public:
	virtual void printError()
	{
		cout << "Out of range exception !" << endl;
	}
};

class NullPointerException : public MyException
{
public:
	virtual void printError()
	{
		cout << "Null pointer exception!!" << endl;
	}
};

void test01()
{
	throw NullPointerException();
}

int main()
{
	try
	{
		test01();
	}
	catch (MyException& e)
	{
		e.printError();
	}
}

// 利用多态来实现 printError 同一个借口调用，以后可以增加自定义的错误
// 抛出不同的错误对象，提示不同的错误