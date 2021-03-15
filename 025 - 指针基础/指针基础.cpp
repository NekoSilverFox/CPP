#include <iostream>
using namespace std;

int main()
{
	int a = 10;
	int* p = &a;
	cout << " a = " << a << endl;
	cout << " p = " << p << endl;
	cout << " *p = " << *p << endl;

	int b = 99;
	p = &b;				  // 此时 p 指向的是 &b 的地址
	
	
	cout << "============== p = &b ================; " << endl;
	cout << " p = " << p << endl;
	cout << " *p = " << *p << endl;

	// ★ ★  ★ ★  ★ ★  ★ ★  ★ ★  ★ ★  ★ ★  重点总结 ★ ★  ★ ★  ★ ★  ★ ★  ★ ★  ★ ★  ★ ★  ★ ★  ★ ★ 
	// p -> 指向的是一个地址！！！
	// *p -> 指向的是一个值！！！


}