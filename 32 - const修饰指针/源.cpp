#include <iostream>
using namespace std;


// 1. ͨ��ָ���޸� const ���εĳ���
void test01()
{
	const int a = 10;
	cout << "a = " << a << endl;
	int* p = NULL;
	//p = &a;  ERROR ���ܽ� "const int *" ���͵�ֵ���䵽 "int *" ���͵�ʵ��
	*p = a;
	*p = 100;
	
	cout << "*p = a " << endl << "*p = 100" << endl;
	cout << "a = " << a << endl;

}

void test02()
{
	int a = 10;
	int b = 20;
	cout << " a = " << a << endl;
	const int* p;
	p = &a;
	// *p = 100; ERROR const ���� int* ���ܸı�ָ�������p��ָ����ڴ��ַ��ֵ
	p = &b; // �������޸�ָ��ָ��ĵ�ַ

}

void test03()
{
	int a = 10, b = 20;
	cout << " a = " << a << endl;

	//int* const p = NULL;   <<<<---------- ������ĥ����,  ��ָ��ָ����ڴ��ַ���� const ������Ҳ���޷����ĵģ�@��
	//p = &a;

	int* const p = &a;
	//*p = a;  û����
	//cout << " *p = a " << endl << "*p = 100" << endl;
	*p = 100;
	cout << " a = " << a << endl;

	// p = &20; ERROR const ����ָ��������ܸı�ָ�����ָ��ĵ�ַ��ֵ�� �����ܸı��������ַ!!!!!

}

void test04()
{
	int b = 20;
	int a = 10;
	const int* const p = &a;  // һ��Ҫ���ó�ʼֵ!!!!!!

	p = &b;
	*p = 100;
	// ���޷��޸ĵ�ַ��Ҳ�޷��޸�ֵ��
	// const ������ָ�����ͣ�Ҳ����ָ���������ô���ܸı�ָ��ָ��ĵ�ַ��Ҳ���ܸı�ָ��ָ���ֵ��
}


int main()
{
	test03();

}