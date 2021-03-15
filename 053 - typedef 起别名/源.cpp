//53 - typedef 起别名
#include<iostream>
using namespace std;

typedef unsigned long long ull; // <----- 对数据类型 起别名


struct StudentsInfoList
{
	char* name;
	int age;
};
typedef StudentsInfoList sl;  // <---- 对结构体起别名


int main()
{
	ull a = 1000;
	sl s;
	cout << a << endl;
	s.age = 14;
	cout << s.age;
}