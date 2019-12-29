#include<iostream>
using namespace std;

class Person
{
public:

	// 默认构造函数
	Person()
	{}
	// 这也是默认构造函数
	Person() :m_A(10), m_B(20), m_C(30)
	{}

	// 有参构造初始化数据
	Person(int a, int b, int c)
	{
		m_A = a;
		m_B = b;
		m_C = c;
	}


	// ★★★★★★ 利用初始化列表 初始化数据 ★★★★★★
	// 构造函数后面 加 ： 属性（参数），属性（参数），。。。。
	Person(int a, int b, int c) :m_A(a), m_B(b), m_C(c)
	{}

	~Person()
	{}

	int m_A;
	int m_B;
	int m_C;

};


void test()
{
	Person p1(10, 20, 30);
	cout << "有参构造初始化数据 : m_A =" << p1.m_A << endl;
	cout << "有参构造初始化数据 : m_B =" << p1.m_B << endl;
	cout << "有参构造初始化数据 : m_C =" << p1.m_C << endl;

	Person p2;
	cout << "利用初始化列表 初始化数据 : m_A =" << p2.m_A << endl;
	cout << "利用初始化列表 初始化数据 : m_B =" << p2.m_B << endl;
	cout << "利用初始化列表 初始化数据 : m_C =" << p2.m_C << endl;
}

int main()
{
	test();
}