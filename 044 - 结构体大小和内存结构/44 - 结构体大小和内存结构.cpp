#include<iostream>
#include<stdlib.h>
#include<string>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

struct Students
{
	char _name[200];
	unsigned int _age;
	char _sex;
	char _tel[20];
	int _scores[3];
}stu01;

// �����ڴ�������⣬Ϊ�˽�ʡ�ڴ棬��ý� �������� �ɴ�С���У�
// ���᲻�����Ķ�

// ע�⣺�����������͵Ĵ�С���ڴ��д洢������һ�����������͵ı���

struct Students
{
	unsigned int _age;
	int _scores[3];

	char _name[200];
	char _sex;
	char _tel[20];
}stu02;

int main()
{
	cout << "sizeof(stu01) = " << sizeof(stu01) << endl;  // ����������ͬ������ӡ�����Ĵ�С ��ͬ������
	cout << "sizeof(stu01) = " << sizeof(stu02) << endl;// ����Ϊ�ڴ�������⣡��

}