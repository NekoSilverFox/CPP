#include<string>
#include<iostream>
using namespace std;

template<class T1, class T2>
class Person
{
public:
	Person(T1 name, T2 age);
	void showPerson();

public:
	T1 m_name;
	T2 m_age;
};

template<class L1, class L2>
Person<L1, L2>::Person(L1 name, L2 age)
{
	this->m_name = name;
	this->m_age = age;
}

template<class T1, class T2>
void Person<T1, T2>::showPerson()
{
	cout << "Name : " << this->m_name << endl << "Age : " << this->m_age << endl;
}

int main()
{
	Person<string, int> p("Nick Wilde", 14);
	p.showPerson();
}
