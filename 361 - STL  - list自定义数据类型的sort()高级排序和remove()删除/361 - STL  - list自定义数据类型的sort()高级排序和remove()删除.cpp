#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<list>
#include<string>
using namespace std;

class Person
{
public:
	Person(string name, int age, int height) : age_(age), name_(name), height_(height) {}
	
	// �ϰ�������°����������֧�֣�������
	//bool operator==(const Person& p)// #########################ע��Ҫ��const����Ϊlist�ڲ�Ҫ��ֹ���޸����ݣ�����
	//{
	//	if (this->name_ == p.name_ || this->height_ == p.height_ || this->age_ == p.age_) return true;
	//	else return false;
	//}

	int age_;
	string name_;
	int height_;
};

// �°���������� �ϰ汾������==��������list�е�remove()������˵���Ѿ�ʧЧ��
bool operator==(const Person& p1, const Person& p2)// #########################ע��Ҫ��const����Ϊlist�ڲ�Ҫ��ֹ���޸����ݣ�����
{
	if (p1.name_ == p2.name_ || p1.height_ == p2.height_ || p1.age_ == p2.age_) return true;
	else return false;
}

// ����ص�����
bool sort_for_Person(const Person& p1, const Person& p2)
{
	if (p1.age_ == p2.age_) return p1.height_ < p2.height_;
	else return p1.age_ < p2.age_;
}


void list_remove_sort()
{
	list<Person>listPerson;

	Person p1("AAA",14 , 156);
	Person p2("BBB", 14, 170);
	Person p3("CCC", 12, 140);
	Person p4("DDD", 13, 160);
	Person p5("EEE", 16, 120);
	Person p6("FFF", 18, 130);
	Person p7("GGG", 14, 160);

	listPerson.push_back(p1);
	listPerson.push_back(p2);
	listPerson.push_back(p3);
	listPerson.push_back(p4);
	listPerson.push_back(p5);
	listPerson.push_back(p6);
	listPerson.push_back(p7);

	for (list<Person>::iterator it = listPerson.begin(); it != listPerson.end(); it++)
	{
		cout << "Name : " << it->name_ << "   Age : " << it->age_ << "   Height : " << it->height_ << endl;
	}
	
	cout << endl << "---------------------------------------------------------" << endl << endl;

	// ####################���һ��������֧��������ʣ���ôϵͳ�ṩ��sort()������ʹ��
	// ���ǣ���������������������������㷨�а���һ�������sort����������������������������
	// �������������������������������ʱ����Ҫдһ���ص�����������������������������������
	listPerson.sort(sort_for_Person);// ������������������������������������������������������

	for (list<Person>::iterator it = listPerson.begin(); it != listPerson.end(); it++)
	{
		cout << "Name : " << it->name_ << "   Age : " << it->age_ << "   Height : " << it->height_ << endl;
	}

	cout << endl << "---------------------------------------------------------" << endl << endl;

	// ---------------------------------------ɾ������-----------------------------------------------
	// ����봫��Ķ���������һ���ͬ��ɾ��������
	// ��Ҫ���ص���
	listPerson.remove(p7);
	for (list<Person>::iterator it = listPerson.begin(); it != listPerson.end(); it++)
	{
		cout << "Name : " << it->name_ << "   Age : " << it->age_ << "   Height : " << it->height_ << endl;
	}
}

int main()
{
	list_remove_sort();
}