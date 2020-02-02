// 128 - C++11新增标准
#include<iostream>
using namespace std;

int main()
{
	// 统一的初始化
	int x = 5;
	int y = { 6 };
	double z{ 123.4 };

	short arr[]{ 1,24,56,6 };
	short arr2[5]{ 1,24,56,6 };
}

// 创建对象的时候也可以使用新的标准
class Temp
{
public:
	int int_;
	double double_;

public:
	Temp(int i, double d) :int_(i), double_(d) {}
};

Temp t1(1, 0.6); // old type
Temp t2{ 2,56.04 };// new type in C++11
Temp t3 = { 4,0.7 }; // new type in C++11
