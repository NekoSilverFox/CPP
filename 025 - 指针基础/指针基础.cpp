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
	p = &b;				  // ��ʱ p ָ����� &b �ĵ�ַ
	
	
	cout << "============== p = &b ================; " << endl;
	cout << " p = " << p << endl;
	cout << " *p = " << *p << endl;

	// �� ��  �� ��  �� ��  �� ��  �� ��  �� ��  �� ��  �ص��ܽ� �� ��  �� ��  �� ��  �� ��  �� ��  �� ��  �� ��  �� ��  �� �� 
	// p -> ָ�����һ����ַ������
	// *p -> ָ�����һ��ֵ������


}