#include<iostream>
//#include<stdlib.h>
using namespace std;

class Person
{
public:
	Person()
	{
		// m_A = 0;  // 通过类名访问不会调用构造函数，所以不能用构造函数初始化！
	}

	Person(int a)
	{

	}

	~Person()
	{}
								// 加入 static 就是静态成员变量，会共享数据
	static int m_A;  // 静态成员变量，在类内声明，类外<-进行初始化！	
							// 静态成员变量 也是有权限的

private:
	static int m_B; //私有权限 在类外不能访问，但可以初始化!!
};

//类外初始化实现
// 因为是放在全局区，所以不能放在任何函数中实现初始化！
int Person::m_A = 0; // !!
int Person::m_B = 0; // !!


int main()
{

	// 1. 通过对象访问属性
	Person p1;
	p1.m_A = 10;

	Person p2;
	p2.m_A = 20;

	cout << "p1.m_A = " << p1.m_A << endl; // 共享数据
	cout << "p2.m_A = " << p2.m_A << endl;


	// 2. 通过类名访问属性
	cout << "通过类名访问 Person::m_A ：" << Person::m_A << endl;
	// cout << "通过类名访问 Person::m_B ：" << Person::m_B << endl; //私有权限在类外无法访问

}