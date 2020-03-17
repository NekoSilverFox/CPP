#include<iostream>
#include<set>
#include<string>
using namespace std;

class Person
{
public:
	Person(string name, int age) : name_(name), age_(age) {}

public:
	string name_;
	int age_;
};


// ��Ϊϵͳ��set�޷����Զ����������ͽ��������жϴ�С�����������Ⱦ�Ӧ�����������
class MyComparePerson
{
public:
	bool operator()(const Person& p1, const Person& p2) const // <---ע�⣬�������ҲҪ��const�� �Է�ֹ�޸����ԣ���
	{
		if (p1.age_ > p2.age_) return true;
		else return false;
	}
};

int main()
{
	Person p1("Tom", 15);
	Person p2("Jarry", 17);
	Person p3("Nick", 19);
	Person p4("Juddy", 13);
	Person p5("Funick", 23);

	// ����������� 
	set<Person, MyComparePerson> s;
	s.insert(p1);
	s.insert(p2);
	s.insert(p3);
	s.insert(p4);
	s.insert(p5);

	// ע�⴫������
	for (set<Person, MyComparePerson>::iterator it = s.begin(); it != s.end(); it++)
		cout << "Name : " << (*it).name_ << "  Age : " << it->age_ << endl;

}