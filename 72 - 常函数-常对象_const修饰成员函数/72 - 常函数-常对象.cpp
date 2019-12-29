#include<iostream>
using namespace std;

class Person
{
public:

	Person() : m_Age(0), m_Age2(0)
	{}

	// 常函数 后面加了 一个 const！！！
	void showInfo() const // 常函数修饰的是一个指针 相当于 const Person* const this
	{
		this->m_Age = 14; // 报错，不允许修改的左值
		this->m_Age2 = 14; // 如果要修改，要加一个 mutable 进行修饰！！
		cout << "m_Age = " << this->m_Age << endl;
		cout << "m_Age2 = " << this->m_Age2 << endl;
	}

	// 普通成员函数
	void func()
	{
		m_Age = 41;
	}



	int m_Age;
	mutable int m_Age2;
};

void test01()
{
	Person p1;
	cout << "m_Age = " << p1.m_Age << endl;
	cout << "m_Age2 = " << p1.m_Age2 << endl;


	// 常函数
	p1.showInfo();
	
}


// 常对象
void test02()
{
	// 创建了一个常对象 p1
	//常对象 不允许修改属性!!!!
	const Person p1;

	p1.func(); // 报错，常对象不可以调用普通成员函数, 因为普通成员函数中可能将 对象的值进行修改
	p1.showInfo();
	cout << "m_Age = " << p1.m_Age << endl;
	cout << "m_Age2 = " << p1.m_Age2 << endl;
}

int main()
{
	test01();
	cout << "-----------------------------------------------" << endl;
	test02();
}