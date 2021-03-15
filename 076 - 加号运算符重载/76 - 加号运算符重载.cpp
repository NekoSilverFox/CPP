#include<iostream>
#include<string>
using namespace std;

class Number
{
public:
	Number();
	Number(int a, int b);

	// Ӧ�ó�Ա����ʵ�� + ���������
	// Number operator+(Number& num);
public:
	int m_A;
	int m_B;
};
Number::Number():m_A(0),m_B(0)
{}
Number::Number(int a, int b) : m_A(a), m_B(b)
{}

// Ӧ�ó�Ա����ʵ�� + ���������
//Number Number::operator+(Number& num)
//{
//	Number temp;
//	temp.m_A = this->m_A + num.m_A;
//	temp.m_B = this->m_B + num.m_B;
//	return temp;
//}


// Ӧ��ȫ�ֺ���ʵ�� + ���������
Number operator+(Number& n1, Number& n2) // ����ʹ��ȫ�ֺ�����������������أ�һ����������Խ��ж������
{
	Number temp;
	temp.m_A = n1.m_A + n2.m_A;
	temp.m_B = n2.m_A + n2.m_B;
	return temp;
}

// ��һ������
Number operator+(Number& n1, int a)
{
	Number temp;
	temp.m_A = n1.m_A + a;
	temp.m_B = n1.m_B + a;
	return temp;
}


int main()
{
	Number b1(2,4);
	Number b2(3,7);

	Number b3 = b1 + b2;
	cout << "b3.m_A = " << b3.m_A << endl;
	cout << "b3.m_B = " << b3.m_B << endl;

	Number b4(7, 1);
	cout << "b4.m_A + 10 = " << b4.m_A + 10 << endl;
	cout << "b4.m_B + 12 = " << b4.m_B + 12 << endl;

}