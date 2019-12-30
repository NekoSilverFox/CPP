// 111 - 类模板碰到友元函数_类内实现
#include<iostream>
#include<string>
using namespace std;

template<class T1, class T2>
class Person
{
	// 友元函数类内实现 - 相当于全局函数了
	friend void printPerson(Person<T1, T2> p)
	{
		cout << "Name : " << p.m_name << endl << "Age ：" << p.m_age << endl;
	}

public:
	Person(T1 name, T2 age);

private:
	T1 m_name;
	T2 m_age;
};

template<class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age)
{
	this->m_age = age;
	this->m_name = name;
}

int main()
{
	Person<string, int> p("一只狐狸", 12);
	
	printPerson(p);
}