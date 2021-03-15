#include<iostream>
using namespace std;

class Person
{
public:
	int m_A;
	static int m_A_Public_Static;

	//普通成员函数 可以访问普通成员变量，也可以访问静态成员变量
	void funPublic()
	{
		m_A = 10; 
		m_A_Public_Static = 10;
		cout << "普通 成员函数调用" << endl;
	}

	//静态成员函数
	//不可以访问  普通成员变量
	//可以访问 静态成员变量
	static void funStaticPublic()
	{
		m_A = 10; // <- ERROR
		m_A_Public_Static = 10;
		cout << "静态 成员函数调用" << endl;
	}

private:
	int m_B;
	static int m_B_Private_Static;

	//静态成员函数 也是有权限的
	static void fun2_Private_Static()
	{
		cout << "私有 - 静态 成员函数 调用" << endl;
	}
	
};

int main()
{

	Person p1;
	p1.funStaticPublic();
	Person::funStaticPublic();

	//静态成员函数 也是有权限的
	Person::fun2_Private_Static(); // <- 不可访问
}