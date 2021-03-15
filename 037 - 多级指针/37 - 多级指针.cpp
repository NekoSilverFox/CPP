#include<iostream>
using namespace std;

// 几级指针就有几个“ * ”

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
	cout << "pp = " << pp << endl; // 一级指针的地址
	cout << "*pp = " << *pp << endl; //一级指针的储存的值，也就是 t 的地址 *pp = p = &t
	cout << "**pp = " << **pp << endl; // 一级指针储存地址的值，也就是 t 的值
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
	cout << "pp = " << pp << endl; // 一级指针的地址
	cout << "*pp = " << *pp << endl; //一级指针的储存的值，也就是 t 的地址 *pp = p = &t
	cout << "**pp = " << **pp << endl << endl; // 一级指针储存地址的值，也就是 t 的值

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