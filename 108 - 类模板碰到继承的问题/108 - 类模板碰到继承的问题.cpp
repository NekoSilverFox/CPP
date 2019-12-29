#include<iostream>
#include<string>
using namespace std;

template<class TypeName, class TypeAge>
class Base
{
public:
	void func()
	{
		cout << this->m_age << endl << this->m_name << endl;
	}

public:
	TypeName m_name;
	TypeAge m_age;
};

//child继承与 base必须告诉base中的T的类型，否则T无法分配内存
class Child : public Base<string, int> // 必须为基类分配内存，不然会报错！
{};


//child2 也是模板类
template<class T, class L1, class L2>
class Child2 : public Base<L1, L2>
{
public:

	void func()
	{
		cout << typeid(T).name() << endl;
		cout << typeid(L1).name() << endl;
		cout << typeid(L2).name() << endl;
	}
	
	T m_name;
};

int main()
{

	Child2 <int, string, int>c1;
	c1.func();
}