#include<iostream>
using namespace std;

// 119 - 捕获自定义异常

class MyError
{
public:
	void error_func()
	{
		cout << "自定义异常输出" << endl;
	}
};

int chufa(int a, int b)
{
	if (b ==0)
	{
		throw MyError(); // 匿名对象 
	}
	return a / b;
}

int main()
{
	try
	{
		cout << chufa(10, 0) << endl;
	}
	catch (MyError e)  // 注意这里的使用方法
	{
		e.error_func();
	}
}