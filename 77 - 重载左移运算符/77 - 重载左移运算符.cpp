#include<iostream>
using namespace std;

class Number
{
	// 如果成员为私有，要使用友元提供访问权限
	friend ostream& operator<<(ostream& cout, Number num); 

public:
	Number() : m_A(0), m_B(0)
	{}
	Number(int a, int b);
private:
	int m_A;
	int m_B;
};
Number::Number(int a, int b)
{
	this->m_A = a;
	this->m_B = b;
}


// 重载左移运算符不可以写到成员函数中
// ↓ 输出流类型
ostream& operator<<(ostream& cout, Number num)
{
	cout << "m_A = " << num.m_A << endl;
	cout << "m_B = " << num.m_B << endl;
	return cout; // 注意，返回一个 cout
}



int main()
{
	Number n1(10, 66);
	cout << n1 << endl;
}