//53 - typedef �����
#include<iostream>
using namespace std;

typedef unsigned long long ull; // <----- ���������� �����


struct StudentsInfoList
{
	char* name;
	int age;
};
typedef StudentsInfoList sl;  // <---- �Խṹ�������


int main()
{
	ull a = 1000;
	sl s;
	cout << a << endl;
	s.age = 14;
	cout << s.age;
}