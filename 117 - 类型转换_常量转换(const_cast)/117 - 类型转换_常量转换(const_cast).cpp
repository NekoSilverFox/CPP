#include<iostream>
using namespace std;

// 117 - 类型转换_常量转换(const_cast)
void test01()
{
	const int* a = NULL;
	int* b = NULL;

	// 去除 const
	b = const_cast<int*>(a);

	// 加入 const
	a = const_cast<const int*>(b);
}

// 不能对非指针或引用 的变量使用 const_cast 操作去直接一处他的 const！
void test02()
{
	const int a = NULL;
	int b = NULL;

	// 去除 const
	b = const_cast<int>(a);

	// 加入 const
	a = const_cast<const int>(b);
}