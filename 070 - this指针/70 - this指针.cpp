// this 指针是一种隐含指针，他隐含于每个   --非静态--  的  ---成员函数--- 中

#include <iostream>
using namespace std;

class Person
{
public:
	Person() {};

	Person(int age)
	{

		// 1. this 解决命名冲突
		// age = age; 输出错误
		// this->age 当前对象的age, age（右侧）传进来的age
		this->age = age;
	}


	//对比年龄
	void duibiAge(Person& person)
	{
		if (this->age == person.age)
		{
			cout << "年龄相等" << endl;
		}
		else
		{
			cout << "年龄不相等" << endl;
		}
	}

	// 2. 返回对象本身的引用
	// 年龄相加
	Person& plusAge(Person& person)
	{
		this->age += person.age;
		return *this;
	}

	int age;

};

void test01()
{
	Person p1;
	p1.age = 10;
	cout << "p1.age ==" << p1.age << endl;

	//Person p2;
	//p2.duibiAge(p1);
	Person p2(20);
	p1.duibiAge(p2);

	p1.plusAge(p2);

	//链式编程
	p1.plusAge(p2).plusAge(p2).plusAge(p2);
	cout << "年龄和为：" << p1.age;
}

int main() {
	test01();
}