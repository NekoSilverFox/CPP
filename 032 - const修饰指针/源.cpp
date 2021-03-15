#include <iostream>
using namespace std;


// 1. 通过指针修改 const 修饰的常量
void test01()
{
	const int a = 10;
	cout << "a = " << a << endl;
	int* p = NULL;
	//p = &a;  ERROR 不能将 "const int *" 类型的值分配到 "int *" 类型的实体
	*p = a;
	*p = 100;
	
	cout << "*p = a " << endl << "*p = 100" << endl;
	cout << "a = " << a << endl;

}

void test02()
{
	int a = 10;
	int b = 20;
	cout << " a = " << a << endl;
	const int* p;
	p = &a;
	// *p = 100; ERROR const 修饰 int* 不能改变指针变量（p）指向的内存地址的值
	p = &b; // 但可以修改指针指向的地址

}

void test03()
{
	int a = 10, b = 20;
	cout << " a = " << a << endl;

	//int* const p = NULL;   <<<<---------- 不能折磨定义,  空指针指向的内存地址经过 const 的修饰也是无法更改的！@！
	//p = &a;

	int* const p = &a;
	//*p = a;  没意义
	//cout << " *p = a " << endl << "*p = 100" << endl;
	*p = 100;
	cout << " a = " << a << endl;

	// p = &20; ERROR const 修饰指针变量，能改变指针变量指向的地址的值， 但不能改变成其他地址!!!!!

}

void test04()
{
	int b = 20;
	int a = 10;
	const int* const p = &a;  // 一定要设置初始值!!!!!!

	p = &b;
	*p = 100;
	// 既无法修改地址，也无法修改值！
	// const 即修饰指针类型，也修饰指针变量，那么不能改变指针指向的地址，也不能改变指针指向的值！
}


int main()
{
	test03();

}