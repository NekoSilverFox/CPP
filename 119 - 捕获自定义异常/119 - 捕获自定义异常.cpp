#include<iostream>
using namespace std;

// 119 - �����Զ����쳣

class MyError
{
public:
	void error_func()
	{
		cout << "�Զ����쳣���" << endl;
	}
};

int chufa(int a, int b)
{
	if (b ==0)
	{
		throw MyError(); // �������� 
	}
	return a / b;
}

int main()
{
	try
	{
		cout << chufa(10, 0) << endl;
	}
	catch (MyError e)  // ע�������ʹ�÷���
	{
		e.error_func();
	}
}