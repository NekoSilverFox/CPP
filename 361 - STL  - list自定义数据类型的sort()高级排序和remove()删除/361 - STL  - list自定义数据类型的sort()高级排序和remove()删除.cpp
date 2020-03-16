#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<list>
#include<string>
using namespace std;

class Person
{
public:
	Person(string name, int age, int height) : age_(age), name_(name), height_(height) {}
	
	// 老版操作，新版编译器不再支持！！！！
	//bool operator==(const Person& p)// #########################注意要加const，因为list内部要防止你修改数据！！！
	//{
	//	if (this->name_ == p.name_ || this->height_ == p.height_ || this->age_ == p.age_) return true;
	//	else return false;
	//}

	int age_;
	string name_;
	int height_;
};

// 新版操作！！！ 老版本的重载==操作对于list中的remove()操作来说，已经失效！
bool operator==(const Person& p1, const Person& p2)// #########################注意要加const，因为list内部要防止你修改数据！！！
{
	if (p1.name_ == p2.name_ || p1.height_ == p2.height_ || p1.age_ == p2.age_) return true;
	else return false;
}

// 排序回调函数
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

	// ####################如果一个容器不支持随机访问，那么系统提供的sort()将不能使用
	// 但是！！！！！！！！！容器本身的算法中包含一个自身的sort！！！！！！！！！！！！！！
	// ！！！！！！！！！！！传入参数的时候需要写一个回调函数！！！！！！！！！！！！！！！
	listPerson.sort(sort_for_Person);// ！！！！！！！！！！！！！！！！！！！！！！！！！！！

	for (list<Person>::iterator it = listPerson.begin(); it != listPerson.end(); it++)
	{
		cout << "Name : " << it->name_ << "   Age : " << it->age_ << "   Height : " << it->height_ << endl;
	}

	cout << endl << "---------------------------------------------------------" << endl << endl;

	// ---------------------------------------删除操作-----------------------------------------------
	// 如果与传入的对象有任意一项，相同就删除！！！
	// 需要重载等于
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