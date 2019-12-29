#include <iostream>
using namespace std;

//分类
//按照参数进行分类  无参构造函数（默认构造函数）   有参构造函数
//按照类型进行分类  普通构造函数  拷贝构造函数
class Person
{

	//构造和析构必须写在public下才可以调用到
public:
	Person() // 默认，无参 构造函数调用
	{
		cout << "默认 构造函数调用" << endl;
	}

	Person(int a)
	{
		cout << "有参 构造函数调用" << endl;
	}

	Person(const Person& p) // 拷贝构造函数调用
	{
		m_Age = p.m_Age;
		cout << "拷贝 构造函数调用" << endl;

	}

	~Person()
	{ 
		cout << "默认 析构函数调用" << endl; 
	}

	int m_Age;
};

int main()
{
	//构造函数调用方式
	//括号法调用
	Person p1(100);
	p1.m_Age = 16;
	Person p2(p1); // 拷贝
	Person p3; //默认构造函数 不要加 ()   
	Person p3(); //编译器认为这行是函数的声明 ！！！！


	//显示法调用
	Person p4 = Person(100);
	Person p5 = Person(p4);

	//Person(100) 叫匿名对象 ,匿名对象特点，如果编译器发现了对象是匿名的，那么在 ->这行<- 代码结束后就释放这个对象

	//不能用拷贝构造函数 初始化匿名对象
	Person p6 = Person(p5); //如果写成左值，编译器认为你写成 Person p5; 对象的声明，如果写成右值，那么可以


	Person p7 = 100; //相当于调用了 Person p7 = Person(100) ，隐式类型转换
	Person p8 = p7; // 相当于  Person p8 = Person(p7);

}