#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Base
{
public:
	Base() { cout << "Base �� Ĭ�Ϲ������" << endl; } // !!! Ĭ�Ϲ��첻����Ϊ �麯��
	// virtual Base() { cout << "Base �� Ĭ�Ϲ������" << endl; } // !!! Ĭ�Ϲ��첻����Ϊ �麯��
	// Base() = 0;

	virtual void speak() = 0;
};

class Dirv : public Base
{
public:
	Dirv() { cout << "Dirv �� Ĭ�Ϲ������" << endl; }
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
		cout << "Dirv2 �� test ��������";
	}
};

int main()
{
	// Base b1;
	Dirv2 d1;
	d1.test();
	d1.speak();
}