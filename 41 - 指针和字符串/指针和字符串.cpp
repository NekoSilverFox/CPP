#include<iostream>
using namespace std;

void test01(char* arr) // δ������
{
	char* p = NULL;
	p = arr;
	*p = 'A';
	p++;
	*p = 'B';

	cout << p << endl;					// �����������ص㣡��������
	cout << sizeof(arr) << endl; // �����ʱ��ӡ�����Ϊ 4 ����Ϊ ��ʱ �� arr Ϊһ�� char ���͵�ָ�룬������һ�����飬ֻ��ָ����һ�������������
}

int main()
{

	char arr[] = "Hello world";
	cout << arr << endl;

	char* p = NULL;
	p = arr;
	*p = 'A';
	p++;
	*p = 'B';

	cout << p << endl;
	// test01(arr);
	cout << arr << endl;
																				// strlen() ---> �����ж��ٸ��ַ�����������\0����β
	cout << "sizeof(arr) = " << sizeof(arr) << endl; // ���Ϊ 12 �����ǣ�10 �� 11�� ��Ϊ������ ���ո񡱺͡�\0��
	cout << "strlen(arr) = " << strlen(arr) << endl; // ������ַ�����   ->��Ч����<-���������ո�ġ�����
	cout << "sizeof(p) = " << sizeof(p) << endl; // ���Ϊ 4 ��Ϊ char ���͵�ָ�룡
	cout << "strlen(p) = " << strlen(p) << endl; // strlen() ->��Ч����<- ���Ϊ 10 ���൱����һ��������׵�ַ������\0����ֹͣ

}