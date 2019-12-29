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
}stu; // <------------注意这里！！！


int main()
{
	// Students stu;

	// 赋值方法 1：按照结构体顺序赋值
	stu = { "Nick Wilde", 16, 'M', "+662974303", 100, 94 , 97 };


	// 赋值方法 2：
	// stu = { ._tel = "+234732094", ._age = 14, ._sex = 'M' };  // C++中不可以，C中可以

	// 赋值方法 3：
	// stu._name = "Judy Hopps";  struct 不可以这么赋值，会出错！因为 ._name 是一个地址，不能将值赋值给地址！
	//strcpy(stu._name, "Judy Hopps");
	//stu._age = 14;
	//stu._scores[0] = 123;
	//stu._scores[1] = 97;
	//stu._scores[2] = 98;
	//stu._sex = 'F';
	//// stu._tel = "+2134214124"
	//strcpy(stu._tel, "+666666235234");



	cout << "姓名：" << stu._name << endl;
	cout << "年龄：" << stu._age << endl;
	cout << "性别：" << (stu._sex == 'M' ? "男" : "女"); cout << endl;
	cout << "电话：" << stu._tel << endl;
	cout << "成绩：" << stu._scores[0] << "  " << stu._scores[1] << "  " << stu._scores[2] << endl;

}