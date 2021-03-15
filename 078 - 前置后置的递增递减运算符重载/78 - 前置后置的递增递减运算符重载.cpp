#include<iostream>
using namespace std;

class MyInteger
{
	friend ostream& operator<<(ostream& cout, MyInteger num);

public:
	MyInteger() : m_B(0), m_A(0)
	{}

public:
	int m_A;
	int m_B;

	//前置++重载
	MyInteger& operator++()
	{
		this->m_A++;
		return *this;
	}

	//后置++ 重载
	MyInteger operator++(int)
	{
		MyInteger tmp = *this;
		m_A++;
		return tmp;
	}

};

ostream& operator<<(ostream& cout, MyInteger num)
{
	cout << "m_A = " << num.m_A << endl;
	cout << "m_B = " << num.m_B << endl;
	return cout;
}

int main()
{
	MyInteger t1;
	cout << t1++ << endl;
	cout << ++(++t1) << endl;
}