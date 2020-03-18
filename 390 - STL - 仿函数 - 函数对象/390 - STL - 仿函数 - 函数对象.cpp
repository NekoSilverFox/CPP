#include<iostream>
using namespace std;

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