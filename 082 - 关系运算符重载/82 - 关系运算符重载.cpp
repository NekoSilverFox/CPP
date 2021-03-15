#include<iostream>
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


public:
	bool operator==(Person& p)
	{
		if (this->m_name == p.m_name && this->m_age == p.m_age)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator!=(Person& p)
	{
		if (this->m_name != p.m_name && this->m_age != p.m_age)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

void test01()
{
	Person p1("XiaoMing", 10);
	Person p2("XiaoQiang", 15);
	Person p3("XiaoQiang", 15);

	if (p1 == p2)
	{
		cout << "p1 == p2" << endl;
	}
	else
	{
		cout << "p1 != p2" << endl;
	}


	if (p2 != p3)
	{
		cout << "p2 != p3" << endl;
	}
	else
	{
		cout << "p2 == p3 " << endl;
	}
}
int main()
{
	test01();
}