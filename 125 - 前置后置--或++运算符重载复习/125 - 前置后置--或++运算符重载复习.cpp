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

	friend ostream& operator<<(ostream& _cout, Complex complex); // ���������������д�ڳ�Ա�����У�����

public:
	Complex()
	{
		this->m_a = 0;
		this->m_b = 0;
	}

	Complex(int a, int b) : m_a(a), m_b(b) {}

	// ����ǰ��++
	Complex& operator++() // ǰ��++��������
	{
		this->m_a++;
		this->m_b++;
		return *this;
	}

	// ���ú���++
	Complex operator++(int) // ����++����ֵ
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

ostream& operator<<(ostream& _cout, Complex complex) // ���������������д�ڳ�Ա�����У�����
{
	cout << "m_a = " << complex.m_a << endl << "m_b = " << complex.m_b; // ע�⣬������ complex ���� this-> !!
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