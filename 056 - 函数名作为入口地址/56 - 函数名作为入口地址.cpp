#include<iostream>
using namespace std;

void func()
{
	cout << "TEST!";

}

int main()
{
	cout << "������ڵ�ַ��" << func; // 000C103C
	int* funAddr = (int* )func;

	void (*myFunc)() = funAddr;

}