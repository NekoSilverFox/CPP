#include<iostream>
using namespace std;

// �Զ�����쳣
class MyException
{
public:
	MyException()
	{
		cout << "MyException ��Ĭ�Ϲ������" << endl;
	}

	MyException(const MyException& e)
	{
		cout << "MyException �Ŀ����������" << endl;
	}

	~MyException()
	{
		cout << "MyException ����������" << endl;
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
	catch (MyException& e) // ���ｨ�������ã����Խ�ʡ���������Ҳ��׳���������
	{
		cout << "Error ---------------- Error" << endl;
	}
}