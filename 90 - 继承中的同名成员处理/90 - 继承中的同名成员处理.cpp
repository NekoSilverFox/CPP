#include<iostream>
using namespace std;

class Base
{
public:
	int m_A;

	void func()
	{
		cout << "Base 的 func()" << endl;
	}
	void func(int a)
	{
		cout << "Base 的 func(int a)" << endl;
	}


public:
	Base() :m_A(0) 
	{
		cout << "Base 构造函数" << endl;
	}
	~Base()
	{
		cout << "Base 析构函数" << endl;
	}
};

class Son : public Base
{
public:
	int m_A;

	void func()
	{
		cout << "Son 的 func()" << endl;
	}
public:
	Son() : m_A(10)
	{
		cout << "Son 构造函数" << endl;
	}
	~Son()
	{
		cout << "Son 析构函数" << endl;
	}
};

int main()
{
	Son s1;
	cout << s1.m_A << endl; // 就近原则，会调用 Son 中的 m_A
	s1.func();

	// 想调用 父类 中的m_A
	cout << s1.Base::m_A << endl;
	s1.Base::func();

	// Base 的 func(int a)调用
	s1.Base::func(10);
}

// 如果子类和父类拥有同名的函数 属性，子类会覆盖父类的成员吗？不会！
// 如果子类与父类的成员函数名相同，子类会把父类中所有的同名版本（重载的）都隐藏掉
// 想调用父类的版本，要加作用域！