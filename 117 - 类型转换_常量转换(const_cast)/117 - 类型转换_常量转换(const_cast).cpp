#include<iostream>
using namespace std;

// 117 - ����ת��_����ת��(const_cast)
void test01()
{
	const int* a = NULL;
	int* b = NULL;

	// ȥ�� const
	b = const_cast<int*>(a);

	// ���� const
	a = const_cast<const int*>(b);
}

// ���ܶԷ�ָ������� �ı���ʹ�� const_cast ����ȥֱ��һ������ const��
void test02()
{
	const int a = NULL;
	int b = NULL;

	// ȥ�� const
	b = const_cast<int>(a);

	// ���� const
	a = const_cast<const int>(b);
}