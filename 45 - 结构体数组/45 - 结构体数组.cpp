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
	int _scores[2];
};


int main()
{
	Students stu[3];

	for (int i = 0; i < 3; i++) {
		cout << "Student NO. " << i + 1<< endl;
		cout << "Name: "; cin >> stu[i]._name;
		cout << "Age: "; cin >> stu[i]._age;
		cout << "Sex: "; cin >> stu[i]._sex;
		cout << "Tel: "; cin >> stu[i]._tel;
		cout << "Scores 1: "; cin >> stu[i]._scores[0];
		cout << "Scores 2: "; cin >> stu[i]._scores[1];
		cout << endl;
	}

	for (int i = 0; i < 3; i++) {
		cout << "������" << stu[i]._name << endl;
		cout << "���䣺" << stu[i]._age << endl;
		cout << "�Ա�" << (stu[i]._sex == 'M' ? "��" : "Ů"); cout << endl;
		cout << "�绰��" << stu[i]._tel << endl;
		cout << "�ɼ� 1��" << stu[i]._scores[0] << endl;
		cout << "�ɼ� 2��" << stu[i]._scores[1] << endl;
		cout << endl;

	}
}
