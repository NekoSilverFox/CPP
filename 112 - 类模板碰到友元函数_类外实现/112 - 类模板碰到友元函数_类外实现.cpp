#include<iostream>
#include<string>
using namespace std;

// �ñ���������Person������
template<class T1, class T2> class Person;

// �ñ�������ǰ����printPerson����
template<class T1, class T2> void printPerson(Person<T1, T2>& p);

template<class T1, class T2>
class Person
{
	// ��Ԫ��������ʵ��  ���ÿղ����б� ���߱����� ģ�庯��������<>
	friend void printPerson<>(Person<T1, T2>& p); //��ͨ���� ����
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


//����ʵ��
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