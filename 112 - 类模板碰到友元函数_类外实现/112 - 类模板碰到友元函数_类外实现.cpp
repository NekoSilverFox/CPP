#include<iostream>
#include<string>
using namespace std;

// 让编译器看到Person类声明
template<class T1, class T2> class Person;

// 让编译器提前看到printPerson声明
template<class T1, class T2> void printPerson(Person<T1, T2>& p);

template<class T1, class T2>
class Person
{
	// 友元函数类内实现  利用空参数列表 告诉编译器 模板函数的声明<>
	friend void printPerson<>(Person<T1, T2>& p); //普通函数 声明
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


//类外实现
template<class T1, class T2>
void printPerson(Person<T1, T2> &p)
{
	cout << "Name : " << p.m_name << endl << "Age : " << p.m_age << endl;
}

int main()
{
	Person<string, int> p("FoxyFox", 17);
	printPerson(p);
}