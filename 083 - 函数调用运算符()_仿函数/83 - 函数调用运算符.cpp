#include<iostream>
using namespace std;


// ���أ�������Ϊ��Ա����

class Adder
{
public:
	int operator()(int a, int b);
};

int Adder::operator()(int a, int b)
{
	return a + b;
}


int main()
{
	Adder a1;
	// cout << a1.test(1, 1) << endl;

	cout << a1(1, 1) << endl; // <-ע���÷������������º�����
	cout << Adder()(2, 1) << endl; // ��������
}