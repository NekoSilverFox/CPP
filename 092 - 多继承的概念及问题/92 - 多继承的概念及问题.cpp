#include<iostream>
using namespace std;

class Base1
{
public:
	Base1() :m_A(1) {}
public:
	int m_A;
};

class Base2
{
public:
	Base2() : m_A(2) {}
public:
	int m_A;
};

class Son : public Base1, public Base2
{
public:
	int m_C;
};

// ע�⣺��̳к��������������ԣ�
// ʹ��������������������
int main()
{
	Son s1;
	// cout << s1.m_A << endl; // ������
	cout << s1.Base1::m_A << endl;
	cout << s1.Base2::m_A << endl;
}