#include<iostream>
using namespace std;

// ����ָ����м����� * ��

void p_LV2()
{
	int t = 10;
	cout << "t = " << t << endl << endl;

	int* p = &t;
	cout << "p = " << p << endl;
	cout << "*p = " << *p << endl << endl;

	int** pp = &p;
	cout << "int** p = &p" << endl;
	cout << "&p = " << &p << endl;
	cout << "pp = " << pp << endl; // һ��ָ��ĵ�ַ
	cout << "*pp = " << *pp << endl; //һ��ָ��Ĵ����ֵ��Ҳ���� t �ĵ�ַ *pp = p = &t
	cout << "**pp = " << **pp << endl; // һ��ָ�봢���ַ��ֵ��Ҳ���� t ��ֵ
}


void p_LV3()
{
	int t = 10;
	cout << "t = " << t << endl << endl;

	int* p = &t;
	cout << "p = " << p << endl;
	cout << "*p = " << *p << endl << endl;

	int** pp = &p;
	cout << "int** p = &p" << endl;
	cout << "&p = " << &p << endl;
	cout << "pp = " << pp << endl; // һ��ָ��ĵ�ַ
	cout << "*pp = " << *pp << endl; //һ��ָ��Ĵ����ֵ��Ҳ���� t �ĵ�ַ *pp = p = &t
	cout << "**pp = " << **pp << endl << endl; // һ��ָ�봢���ַ��ֵ��Ҳ���� t ��ֵ

	int*** ppp = &pp;
	cout << "&pp = " << &pp << endl;
	cout << "&ppp = " << &ppp << endl; //
	cout << "ppp = " << ppp << endl; // &pp
	cout << "*ppp = " << *ppp << endl; // pp = &p
	cout << "**ppp = " << **ppp << endl; // p = &t
	cout << "***ppp = " << ***ppp << endl; // t = *p = **pp


}

int main()
{
//	p_LV2();
	p_LV3();
}