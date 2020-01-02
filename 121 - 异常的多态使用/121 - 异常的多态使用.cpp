#include<iostream>
using namespace std;

//�쳣����
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

// ���ö�̬��ʵ�� printError ͬһ����ڵ��ã��Ժ���������Զ���Ĵ���
// �׳���ͬ�Ĵ��������ʾ��ͬ�Ĵ���