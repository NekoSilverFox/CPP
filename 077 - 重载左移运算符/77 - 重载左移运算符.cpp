#include<iostream>
using namespace std;

class Number
{
	// �����ԱΪ˽�У�Ҫʹ����Ԫ�ṩ����Ȩ��
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


// �������������������д����Ա������
// �� ���������
ostream& operator<<(ostream& cout, Number num)
{
	cout << "m_A = " << num.m_A << endl;
	cout << "m_B = " << num.m_B << endl;
	return cout; // ע�⣬����һ�� cout
}



int main()
{
	Number n1(10, 66);
	cout << n1 << endl;
}