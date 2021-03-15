#include<iostream>
using namespace std;

class Base
{
public:
	int m_A;

	void func()
	{
		cout << "Base �� func()" << endl;
	}
	void func(int a)
	{
		cout << "Base �� func(int a)" << endl;
	}


public:
	Base() :m_A(0) 
	{
		cout << "Base ���캯��" << endl;
	}
	~Base()
	{
		cout << "Base ��������" << endl;
	}
};

class Son : public Base
{
public:
	int m_A;

	void func()
	{
		cout << "Son �� func()" << endl;
	}
public:
	Son() : m_A(10)
	{
		cout << "Son ���캯��" << endl;
	}
	~Son()
	{
		cout << "Son ��������" << endl;
	}
};

int main()
{
	Son s1;
	cout << s1.m_A << endl; // �ͽ�ԭ�򣬻���� Son �е� m_A
	s1.func();

	// ����� ���� �е�m_A
	cout << s1.Base::m_A << endl;
	s1.Base::func();

	// Base �� func(int a)����
	s1.Base::func(10);
}

// �������͸���ӵ��ͬ���ĺ��� ���ԣ�����Ḳ�Ǹ���ĳ�Ա�𣿲��ᣡ
// ��������븸��ĳ�Ա��������ͬ�������Ѹ��������е�ͬ���汾�����صģ������ص�
// ����ø���İ汾��Ҫ��������