#include<iostream>
using namespace std;

#if 0

4.1 函数对象 
重载函数调用操作符的类，其对象常称为函数对象（function object），即它们是行为
类似函数的对象，也叫仿函数(functor),其实就是重载“()”操作符，使得类对象可以像函数
那样调用。 

注意: 
1.函数对象(仿函数)是一个类，不是一个函数。 
2.函数对象(仿函数)重载了”() ”操作符使得它可以像函数一样调用。 

分类:假定某个类有一个重载的operator()，而且重载的operator()要求获取一个参数，
我们就将这个类称为“一元仿函数”（unary functor）；相反，如果重载的operator()要求
获取两个参数，就将这个类称为“二元仿函数”（binary functor） 。 
函数对象的作用主要是什么？STL提供的算法往往都有两个版本，其中一个版本表现出
最常用的某种运算，另一版本则允许用户通过template参数的形式来指定所要采取的策略。
 
#endif


// 函数对象是重载了函数调用符号的类
class MyPrint
{
public:
	int operator()(int num)
	{
		cout << "Number = " << num << endl;
		return ++count_;
	}

	int count_ = 0;
};

// 函数对象
// 函数对象重载了（）操作符的实例化对象，可以像普通函数那样调用，可以有参，也可以有返回值
void test01()
{
	MyPrint print;
	print(100);
	print(100);
	print(100);
	print(100);
	cout << "print 函数，调用了 " << print.count_ << " 次。" << endl; // 函数对象超出了普通函数的概念，可以保存函数的调用状态
}

void doPrint(MyPrint print, int num)
{
	print(num);
}

int main()
{
	test01();

	// 函数对象作为参数
	doPrint(MyPrint(), 10); 	// 参数1：函数的匿名对象
}