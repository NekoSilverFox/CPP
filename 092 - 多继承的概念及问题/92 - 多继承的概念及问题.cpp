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

// 注意：多继承很容易引发二义性！
// 使用作用域运算符解决问题
int main()
{
	Son s1;
	// cout << s1.m_A << endl; // 二义性
	cout << s1.Base1::m_A << endl;
	cout << s1.Base2::m_A << endl;
}