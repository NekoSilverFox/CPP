#include<iostream>
using namespace std;

void test01()
{
	int a = 1;
	int b = 5;
	cout << "a = " << a <<endl;
	cout << --a * b << endl;
	cout << "a = " << a << endl;
}

void test02()
{
	int a = 1;
	int b = 5;
	cout << "a = " << a << endl;
	cout << a-- * b << endl;
	cout << "a = " << a << endl;
}

class Complex
{

	friend ostream& operator<<(ostream& _cout, Complex complex); // 左移运算符不可以写在成员函数中！！！

public:
	Complex()
	{
		this->m_a = 0;
		this->m_b = 0;
	}

	Complex(int a, int b) : m_a(a), m_b(b) {}

	// 重置前置++
	Complex& operator++() // 前置++返回引用
	{
		this->m_a++;
		this->m_b++;
		return *this;
	}

	// 重置后置++
	Complex operator++(int) // 后置++返回值
	{
		Complex temp = *this;
		this->m_a++;
		this->m_b++;
		return temp;
	}

private:
	int m_a;
	int m_b;
};

ostream& operator<<(ostream& _cout, Complex complex) // 左移运算符不可以写在成员函数中！！！
{
	cout << "m_a = " << complex.m_a << endl << "m_b = " << complex.m_b; // 注意，这里是 complex 不是 this-> !!
	return _cout;
}


int main()
{
	test01();
	test02();
	cout << endl;

	Complex comp(2, 3);

	cout << comp++ << endl;
	cout << "comp = " << comp << endl;

	cout << ++comp << endl;
}