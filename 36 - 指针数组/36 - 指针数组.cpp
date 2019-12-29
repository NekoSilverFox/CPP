#include<iostream>
using namespace std;


// 通过指针数组修改变量的值
void test01()
{
	int a = 10;
	int b = 20;
	int c = 30;

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl << endl;

	int* arr[] = { &a,&b,&c };

	*arr[1] = 66;  // 通过指针数组修改变量的值

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl << endl;
}

void test02()
{
	// 存储 char* 类型的地址
	char* arr[] = { "Hello", "world","NiHao","ShiJie" }; // 不能用于C++，C++ 会报错
}

int main()
{
	test01(); cout << endl;
}