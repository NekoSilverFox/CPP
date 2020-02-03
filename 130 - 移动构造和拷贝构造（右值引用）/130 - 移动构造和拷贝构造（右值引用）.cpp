// 130 - 移动构造和拷贝构造（右值引用）

#include <iostream>
using namespace std;
const int NUMBER = 17;

class Person
{
private:
	int age_;
	char* name_;
	static int num_;

private:
	void showObject() const;

public:
	Person();
	explicit Person(int age); // explicit - 禁止  单-参数构造函数导致的自动转换
	Person(int age, char name);
	Person(const Person& p); // 拷贝构造
	Person(Person&& p); // 移动构造
	Person operator+(const Person& p) const;
	void showDate() const;
};
int Person::num_ = 0; // 注意静态成员的 类外初始化 ！！！ 注意初始化语法！！！1

void Person::showObject() const
{
	cout << "Num = " << num_ << endl << endl;
	cout << "Age = " << age_ << endl;
	cout << "地址 Name = " << (void*) name_ << endl;

}

void Person::showDate() const
{
	if (age_ == NULL)
	{
		cout << "Object empty" << endl;
 	}
	else
	{
		for (int i = 0; i < age_; ++i)
		{
			cout << name_[i] << " ";
		}
	}
}

Person::Person()
{
	++num_;
	age_ = NUMBER;
	name_ = nullptr;

	showObject();
}

Person::Person(int age) : age_(age)
{
	++num_;
	name_ = new char[age];

	showObject();
}

Person::Person(int age, char ch) : age_(age)
{
	++num_;
	name_ = new char[age];

	for (int i = 0; i < age; ++i)
	{
		name_[i] = ch;
	}

	showObject();
}

Person::Person(const Person& p) : age_(p.age_) // 拷贝构造
{
	++num_;
	name_ = new char[p.age_];

	for (int i = 0; i < p.age_ ; ++i)
	{
		name_[i] = p.name_[i];
	}

	showObject();
}


Person::Person(Person&& p) : age_(p.age_) // 移动构造
{
	++num_;
	name_ = p.name_;
	p.name_ = nullptr;
	p.age_ = NULL;
	showObject();
}

Person Person::operator+(const Person& p) const
{
	cout << "-------------The operator+() have been used------" << endl;
	Person temp(age_ + p.age_);
	for (int i = 0; i < age_; ++i)
	{
		temp.name_[i] = name_[i];
	}
	for (int i = age_; i < temp.age_; ++i)
	{
		temp.name_[i] = p.name_[i - age_];
	}

	return temp;

}

int main()
{
	Person p1(10, 'n');
	Person p2 = p1; // calls copy constructor
	Person p3(20, 'o');
	Person p4(p1 + p3);
	cout << "p1 :  "; p1.showDate();
	cout << "p2 :  "; p2.showDate();
	cout << "p3 :  "; p3.showDate();
	cout << "p4 :  "; p4.showDate();
}