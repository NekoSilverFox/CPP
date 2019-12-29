//  构造和析构函数 的实质其实就是 初始化和清理
#include<iostream>
using namespace std;

class Person {
public:
	// 构造函数（初始化）写法
	// 与类名相同，不写 void ，可以发生重载（可以有参数）
	// 构造函数由编译器自动调用，而不是手动，只会调用一次（就像手机只会初始化一次，而不是每次开机都要初始化一次！）
	Person()
	{
		cout << "默认初始化 - 构造函数调用" << endl;
	}

	// 发生重载
	Person(int a)
	{
		cout << "重载 - 构造函数调用" << endl;
	}

	// 析构函数
	// 与类名相同，类名前加一个 “~”，没有返回值，不写 void，不可以有参数！（不能发生重载（重载与参数有关））
	// 自动调用
	~Person()
	{
		cout << "默认清理 - 析构函数调用" << endl;
	}
};
void test01()
{
	Person p1; // 默认调用了 构造和析构函数 ， 只是系统提供的两个空实现的函数

	Person p2(1); // 重载操作
}	


int main()
{
	 test01();

	// Person p1; // 注意 生命周期

	cin.get();
	return 0;
}