#include<iostream>
using namespace std;

class Person
{
public:

	// Ĭ�Ϲ��캯��
	Person()
	{}
	// ��Ҳ��Ĭ�Ϲ��캯��
	Person() :m_A(10), m_B(20), m_C(30)
	{}

	// �вι����ʼ������
	Person(int a, int b, int c)
	{
		m_A = a;
		m_B = b;
		m_C = c;
	}


	// ������� ���ó�ʼ���б� ��ʼ������ �������
	// ���캯������ �� �� ���ԣ������������ԣ�����������������
	Person(int a, int b, int c) :m_A(a), m_B(b), m_C(c)
	{}

	~Person()
	{}

	int m_A;
	int m_B;
	int m_C;

};


void test()
{
	Person p1(10, 20, 30);
	cout << "�вι����ʼ������ : m_A =" << p1.m_A << endl;
	cout << "�вι����ʼ������ : m_B =" << p1.m_B << endl;
	cout << "�вι����ʼ������ : m_C =" << p1.m_C << endl;

	Person p2;
	cout << "���ó�ʼ���б� ��ʼ������ : m_A =" << p2.m_A << endl;
	cout << "���ó�ʼ���б� ��ʼ������ : m_B =" << p2.m_B << endl;
	cout << "���ó�ʼ���б� ��ʼ������ : m_C =" << p2.m_C << endl;
}

int main()
{
	test();
}