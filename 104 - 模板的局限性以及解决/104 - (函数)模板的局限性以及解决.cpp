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

// 注意这里是函数模板，而不是类模板
template<class T>
string myComplate(T &a, T &b)
{
	if (a == b)
	{
		return "相等";
	}
	return "不相等";
}

// 通过第三代具体化自定义数据类型，解决上述问题
// 如果具体化能够优先匹配，那么就选择具体化
// 语法：  template<> 返回值  函数名<具体类型>(参数) 
template<> string myComplate<Person>(Person &a, Person &c) // 注意这里是函数模板，而不是类模板
{
	if (a.m_age == c.m_age) // 所以需要重载！
	{
		return "相等";
	}
	return "不相等";
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