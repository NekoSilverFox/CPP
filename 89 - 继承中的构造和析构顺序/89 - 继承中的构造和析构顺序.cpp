#include<iostream>
using namespace std;

class Base
{
public:
	Base()
	{
		cout << "Base ���޲ι���" << endl;
	}
	~Base()
	{
		cout << "Base ������" << endl;
	}
};

class Son : public Base
{
public:
	Son()
	{
		cout << "Son ���޲ι���" << endl;
	}
	~Son()
	{
		cout << "Son ������" << endl;
	}
};
// ==============================================
class Base2
{
public:
	Base2(int a)
	{
		this->m_A = a;
		cout << "Base2 ���޲ι���" << endl;
	}
	~Base2()
	{
		cout << "Base2 ������" << endl;
	}

	int m_A;
};

class Son2 : public Base2
{
public:
	//Son() // ���ó�ʼ���б���ʾ���� �вι���
	//{
	//	cout << "Son ���޲ι���" << endl;
	//}

	// 1.
	Son2() : Base2(10)// ���ó�ʼ���б���ʾ���� �вι���
	{
		cout << "Son2 ���޲ι���" << endl;
	}


	// 2.
	Son2(int a) : Base2(a)// ˳���ʼ�� Base2�е�a
	{
		cout << "Son2 ���޲ι���" << endl;
	}

	~Son2()
	{
		cout << "Son2 ������" << endl;
	}
};

int main()
{
	Son2 s1(1000);
}