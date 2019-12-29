#include<iostream>
using namespace std;

class MyString
{
public:
	MyString()
	{}

	explicit MyString(int a) // explicit 关键字
	{
		m_A = a;
	}

	~MyString()
	{}

	int m_A;
};

int main()
{
	MyString str;

	// 之所以报错，是因为 第 10 行 使用了， explicit 关键字（防止隐式类型转换）
	 str = 10; // 隐式类型转换  相当于 t = t(10)   忘了看-->《62 - 构造函数及调用时机》

	/*
	不能这么分开写！！
	MyString str2;
	str2(10);   <---- 这里会报错！
	*/

	MyString str3(14);
}