#include<string>
#include<iostream>
using namespace std;

class Person1
{
public:
	void print_1()
	{
		cout << "Person 1 的调用" << endl;
	}
};

class Person2
{
public:
	void print_2()
	{
		cout << "Person 2 的调用" << endl;
	}
};

// 类模板
template<class T>
class myClass
{
public:
	T obj;

	//void showWay()
	//{
	//	obj.print_1();
	//	obj.print_2();
	//}
	
	void func1()
	{
		obj.print_1(); 
	}
	void func2() // 如果 没有调用，是不会提前编译的，当然也不会报错
	{
		obj.print_2();
	}

};

int main()
{
	myClass<Person1> mc;
	mc.func1();
	// mc.func2();
}

// 结论 ：类模板中成员函数 一开始不会创建出来，而是在    -----> 运行时才去创建 <------ ！！！！