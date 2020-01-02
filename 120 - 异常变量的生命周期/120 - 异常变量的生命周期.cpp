#include<iostream>
using namespace std;

// 自定义的异常
class MyException
{
public:
	MyException()
	{
		cout << "MyException 的默认构造调用" << endl;
	}

	MyException(const MyException& e)
	{
		cout << "MyException 的拷贝构造调用" << endl;
	}

	~MyException()
	{
		cout << "MyException 的析构调用" << endl;
	}
};

void test01()
{
	throw MyException();
}

int main()
{
	try
	{
		test01();
	}
	catch (MyException& e) // 这里建议用引用，可以节省开销，并且不易出错！！！！
	{
		cout << "Error ---------------- Error" << endl;
	}
}