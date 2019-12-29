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

// 由于内存对齐问题，为了节省内存，最好将 数据类型 由大到小排列！
// 但会不方便阅读

// 注意：所有数据类型的大小在内存中存储的资质一定是他的类型的倍数

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
	cout << "sizeof(stu01) = " << sizeof(stu01) << endl;  // 两者内容相同，但打印出来的大小 不同！！！
	cout << "sizeof(stu01) = " << sizeof(stu02) << endl;// 是因为内存对齐问题！！

}