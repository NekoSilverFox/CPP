#include<iostream>
#include<string>
using namespace std;

// 注意，这里是类模板！
template<class TypeName, class TypeAge>
class Person
{
public:

	Person(TypeName name, TypeAge age)
	{
		this->m_name = name;
		this->m_age = age;
	}
	
	void printInfo()
	{
		cout << "Name : " << this->m_name << endl;
		cout << "Age : " << this->m_age << endl;
		cout << endl;
	}

	TypeName m_name;
	TypeAge m_age;
};

// 1. 显示指定类型
void showInfo(Person<string, int> &p)
{
	p.printInfo();
}


// 2. 参数模板化
template<class T1, class T2>
void showInfo2(Person<T1, T2> &p)
{
	//如何查看类型
	cout << typeid(T1).name() << endl;
	cout << typeid(T2).name() << endl;
	p.printInfo();
}



// 3. 整体模板化
template<class T>
void showInfo3(T& p)
{
	cout << typeid(T).name() << endl;
	p.printInfo();
}

int main()
{
	// 可以看到，无论采用什么传递方式，初始化的方式都是一样的！！！！
	// 注意，这里是类模板！
	Person<string, int> p1("Nick", 14);

	// 1. 显示指定类型
	showInfo(p1);

	// 2. 参数模板化
	showInfo2(p1);

	// 3. 整体模板化
	showInfo3(p1);
}

