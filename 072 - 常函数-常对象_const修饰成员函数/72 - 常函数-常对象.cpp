#include<iostream>
using namespace std;

class Person
{
public:

	Person() : m_Age(0), m_Age2(0)
	{}

	// ������ ������� һ�� const������
	void showInfo() const // ���������ε���һ��ָ�� �൱�� const Person* const this
	{
		this->m_Age = 14; // �����������޸ĵ���ֵ
		this->m_Age2 = 14; // ���Ҫ�޸ģ�Ҫ��һ�� mutable �������Σ���
		cout << "m_Age = " << this->m_Age << endl;
		cout << "m_Age2 = " << this->m_Age2 << endl;
	}

	// ��ͨ��Ա����
	void func()
	{
		m_Age = 41;
	}



	int m_Age;
	mutable int m_Age2;
};

void test01()
{
	Person p1;
	cout << "m_Age = " << p1.m_Age << endl;
	cout << "m_Age2 = " << p1.m_Age2 << endl;


	// ������
	p1.showInfo();
	
}


// ������
void test02()
{
	// ������һ�������� p1
	//������ �������޸�����!!!!
	const Person p1;

	p1.func(); // ���������󲻿��Ե�����ͨ��Ա����, ��Ϊ��ͨ��Ա�����п��ܽ� �����ֵ�����޸�
	p1.showInfo();
	cout << "m_Age = " << p1.m_Age << endl;
	cout << "m_Age2 = " << p1.m_Age2 << endl;
}

int main()
{
	test01();
	cout << "-----------------------------------------------" << endl;
	test02();
}