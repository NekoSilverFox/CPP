#include<iostream>
using namespace std;


// ͨ��ָ�������޸ı�����ֵ
void test01()
{
	int a = 10;
	int b = 20;
	int c = 30;

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl << endl;

	int* arr[] = { &a,&b,&c };

	*arr[1] = 66;  // ͨ��ָ�������޸ı�����ֵ

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl << endl;
}

void test02()
{
	// �洢 char* ���͵ĵ�ַ
	char* arr[] = { "Hello", "world","NiHao","ShiJie" }; // ��������C++��C++ �ᱨ��
}

int main()
{
	test01(); cout << endl;
}