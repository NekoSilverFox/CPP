#include<iostream>
using namespace std;

void func()
{
	cout << "TEST!";

}

int main()
{
	cout << "函数入口地址：" << func; // 000C103C
	int* funAddr = (int* )func;

	void (*myFunc)() = funAddr;

}