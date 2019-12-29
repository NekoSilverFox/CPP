#include<iostream>
using namespace std;


// 重载（）必须为成员函数

class Adder
{
public:
	int operator()(int a, int b);
};

int Adder::operator()(int a, int b)
{
	return a + b;
}


int main()
{
	Adder a1;
	// cout << a1.test(1, 1) << endl;

	cout << a1(1, 1) << endl; // <-注意用法！！！！（仿函数）
	cout << Adder()(2, 1) << endl; // 匿名对象
}