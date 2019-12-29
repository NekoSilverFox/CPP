#include<string>
#include<iostream>
using namespace std;


//类模板
template<class TypeName, class TypeAge = int>  //类模板可以有默认类型(后期可更改), 函数模板不可以！！
class Person
{
public:
	
	Person(TypeName name, TypeAge age)
	{
		this->m_age = age;
		this->m_name = name;
	}

	TypeName m_name;
	TypeAge m_age;

	void func()
	{
		cout << "姓名：" << this->m_name << endl;
		cout << "年龄：" << this->m_age << endl;
	}
};


int main()
{
	// 报错， 类模板 - 不允许 - 自动类型推导， 
	//				函数模板 - 允许 - 自动类型推导， 
	// Person p1("Nick", 14);


	//显示指定类型
	Person<string, double> p1("Nick", 14);

	p1.func();

}