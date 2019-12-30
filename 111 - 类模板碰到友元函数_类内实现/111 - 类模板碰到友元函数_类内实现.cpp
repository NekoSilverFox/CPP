// 111 - ��ģ��������Ԫ����_����ʵ��
#include<iostream>
#include<string>
using namespace std;

template<class T1, class T2>
class Person
{
	// ��Ԫ��������ʵ�� - �൱��ȫ�ֺ�����
	friend void printPerson(Person<T1, T2> p)
	{
		cout << "Name : " << p.m_name << endl << "Age ��" << p.m_age << endl;
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
	Person<string, int> p("һֻ����", 12);
	
	printPerson(p);
}