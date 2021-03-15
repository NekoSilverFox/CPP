#include<iostream>
using namespace std;

class Base
{
public:
	static int m_A;

	static void func()
	{
		cout << "Base - func()" << endl;
	}
	static void func(int a)
	{
		cout << "Base - func(int a)" << endl;
	}
		
};
int Base::m_A = 2;

class Son : public Base
{
public:
	static int m_A;

	static void func()
	{
		cout << "Son - func()" << endl;
	}
	static void func(int a)
	{
		cout << "Son - func(int a)" << endl;
	}

};
int Son::m_A = 6;


int main()
{
	Son s1;
	cout << s1.m_A << endl; // �ͽ�ԭ����������
	
	cout << s1.Base::m_A << endl;

	Son::func();
	Base::func();
	Son::Base::func(); // ���ʸ����е�ͬ������
	Base::func(1);
	Son::Base::func(1);
}