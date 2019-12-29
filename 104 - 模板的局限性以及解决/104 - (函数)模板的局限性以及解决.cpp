#include <iostream>
using namespace std;

class Person
{
public:
	Person(string name, int age)
	{
		this->m_name = name;
		this->m_age = age;
	}

	string m_name;
	int m_age;
};

// ע�������Ǻ���ģ�壬��������ģ��
template<class T>
string myComplate(T &a, T &b)
{
	if (a == b)
	{
		return "���";
	}
	return "�����";
}

// ͨ�����������廯�Զ����������ͣ������������
// ������廯�ܹ�����ƥ�䣬��ô��ѡ����廯
// �﷨��  template<> ����ֵ  ������<��������>(����) 
template<> string myComplate<Person>(Person &a, Person &c) // ע�������Ǻ���ģ�壬��������ģ��
{
	if (a.m_age == c.m_age) // ������Ҫ���أ�
	{
		return "���";
	}
	return "�����";
}

int main()
{
	int a = 10;
	int b = 20;
	cout << myComplate(a, b) << endl;

	Person p1("Nick", 14);
	Person p2("Judy", 14);
	cout << myComplate(p1, p2) << endl;

	//Person <string, int>p3("Hopps", 20);
	//cout << myComplate(p3) << endl;
}