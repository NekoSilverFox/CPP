#include<iostream>
using namespace std;

class BigBase
{
public:
	int m_x;
public:
	BigBase(int x)
	{
		this->m_x = x;
		cout << this->m_x << endl;
	}
	void func()
	{
		cout << "Base::func()" << endl;
	}
};

class Base1 : virtual public BigBase
{
public:
	Base1() :BigBase(1) {}
};

class Base2 : virtual public BigBase
{
public:
	Base2() : BigBase(2) {}
};

class Derived : public Base1, public Base2
{
public:
	Derived() : BigBase(3) {}
};

int main()
{
	// BigBase 是被共享的
	cout << "sizeof(BigBase)" << sizeof(BigBase) << endl;
	cout << "sizeof(Base1)" << sizeof(Base1) << endl; // 为什么大小是16？？
	cout << "sizeof(Base2)" << sizeof(Base2) << endl;
	cout << "sizeof(Derived)" << sizeof(Derived) << endl;
	Derived d1;
	Base1 b1;
	Base2 b2;
}