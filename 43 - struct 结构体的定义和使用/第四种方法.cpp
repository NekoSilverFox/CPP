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
}stu; // <------------ע���������


int main()
{
	// Students stu;

	// ��ֵ���� 1�����սṹ��˳��ֵ
	stu = { "Nick Wilde", 16, 'M', "+662974303", 100, 94 , 97 };


	// ��ֵ���� 2��
	// stu = { ._tel = "+234732094", ._age = 14, ._sex = 'M' };  // C++�в����ԣ�C�п���

	// ��ֵ���� 3��
	// stu._name = "Judy Hopps";  struct ��������ô��ֵ���������Ϊ ._name ��һ����ַ�����ܽ�ֵ��ֵ����ַ��
	//strcpy(stu._name, "Judy Hopps");
	//stu._age = 14;
	//stu._scores[0] = 123;
	//stu._scores[1] = 97;
	//stu._scores[2] = 98;
	//stu._sex = 'F';
	//// stu._tel = "+2134214124"
	//strcpy(stu._tel, "+666666235234");



	cout << "������" << stu._name << endl;
	cout << "���䣺" << stu._age << endl;
	cout << "�Ա�" << (stu._sex == 'M' ? "��" : "Ů"); cout << endl;
	cout << "�绰��" << stu._tel << endl;
	cout << "�ɼ���" << stu._scores[0] << "  " << stu._scores[1] << "  " << stu._scores[2] << endl;

}