// 69 - 成员变量和成员函数分开存储
// this 指针是一种隐含指针，他隐含与每个   --非静态--  的  ---成员函数--- 中
#include<iostream>
using namespace std;

class NoThing
{
public:

};

class TestFunc
{
	void func() {
		cout << "啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊";
	};
};

class TestStatic
{

	int a;  //非静态成员变量，属于对象身上

							// 编译器会偷偷加上一个 this 指针，TestStatic* this   或者 void fun( TestStatic* this ) {}
	void fun() {}; // 非静态成员函数，不属于对象身上

	// 静态成员函数 内部没有 this 指针，静态成员函数不能操作非静态成员变量
	static int b; // 静态成员变量，不属于对象身上
	static int fun2() {}; // 静态成员函数，不属于对象身上
};

// 结论：非静态成员变量才属于对象身上
// 所有函数，无论静态还是非静态，都不在对象身上，虽然C++进行了封装处理，但是还是将函数进行了分开存储

int main()
{
	cout << "空类的大小为：" << sizeof(NoThing) << endl;
	cout << "原因：空类的大小为 1 ，每个实例化的对象 都有独一无二的地址，char 维护这个地址，所以为 1" << endl << endl;

	cout << "只有函数的 类大小：" << sizeof(TestFunc) << endl << endl;

	cout << "TestStatic：" << sizeof(TestStatic) << endl;

}


