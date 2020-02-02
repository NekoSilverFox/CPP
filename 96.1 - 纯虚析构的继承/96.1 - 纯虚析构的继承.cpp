#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Base
{
public:
	Base() { cout << "Base 的 默认构造调用" << endl; } // !!! 默认构造不能作为 虚函数
	// virtual Base() { cout << "Base 的 默认构造调用" << endl; } // !!! 默认构造不能作为 虚函数
	// Base() = 0;

	virtual void speak() = 0;
};

class Dirv : public Base
{
public:
	Dirv() { cout << "Dirv 的 默认构造调用" << endl; }
	virtual void speak()
	{
		cout << "Yiff Yiff !!" << endl;
	}

	virtual void test() = 0;

};

class Dirv2 : public Dirv
{
public:
	virtual void test()
	{
		cout << "Dirv2 的 test 函数调用";
	}
};

int main()
{
	// Base b1;
	Dirv2 d1;
	d1.test();
	d1.speak();
}