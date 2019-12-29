// 38 - 通过指针传递实参的值给函数的形参，并通过函数修改实参的值

#include<iostream>
using namespace std;

void turnNum(int* a, int* b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;

}

int main()
{
	int a = 10, b = 20;
	cout << "a = " << a << endl << "b = " << b << endl << endl;
	turnNum(&a, &b);
	cout << "a = " << a << endl << "b = " << b << endl;

}