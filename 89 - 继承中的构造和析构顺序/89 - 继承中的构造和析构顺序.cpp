#include<iostream>
using namespace std;

class Base
{
public:
	Base()
	{
		cout << "Base 的无参构造" << endl;
	}
	~Base()
	{
		cout << "Base 的析构" << endl;
	}
};

class Son : public Base
{
public:
	Son()
	{
		cout << "Son 的无参构造" << endl;
	}
	~Son()
	{
		cout << "Son 的析构" << endl;
	}
};
// ==============================================
class Base2
{
public:
	Base2(int a)
	{
		this->m_A = a;
		cout << "Base2 的无参构造" << endl;
	}
	~Base2()
	{
		cout << "Base2 的析构" << endl;
	}

	int m_A;
};

class Son2 : public Base2
{
public:
	//Son() // 利用初始化列表，显示调用 有参构造
	//{
	//	cout << "Son 的无参构造" << endl;
	//}

	// 1.
	Son2() : Base2(10)// 利用初始化列表，显示调用 有参构造
	{
		cout << "Son2 的无参构造" << endl;
	}


	// 2.
	Son2(int a) : Base2(a)// 顺便初始化 Base2中的a
	{
		cout << "Son2 的无参构造" << endl;
	}

	~Son2()
	{
		cout << "Son2 的析构" << endl;
	}
};

int main()
{
	Son2 s1(1000);
}