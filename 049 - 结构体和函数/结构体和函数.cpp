#include <iostream>
#include<string>
using namespace std;

// 定义一个结构体
struct Students
{
	string name;
	int age;
};

// 并不会改变 主函数中 的 结构体s
void test01(Students s)
{
	s.name = "TTTTTT";
	s.age = 16;

	cout << endl << s.name << endl;
	cout << s.age << endl << endl;
}

// 因为接受 的是一个 地址 ，所以会改变主函数中 的 s
void test02(Students* t)
{
	t->name = "JJJJJJJ";  // 注意 用的是 “ -> ”
	t->age = 16;
}

// 结构体作为 返回值
// 函数作为结构体
Students test03(Students* p)
{
	
	p->name = "GGGGGGG";
	p->age = 14;
	return *p;
}

int main()
{
	Students s;
	// s.name = (char*)malloc(sizeof(char) * 200);
	s.name = "Mr.Z";
	s.age = 18;

	cout << endl << s.name << endl;
	cout << s.age << endl << endl;

	test01(s);
	cout << endl << s.name << endl;
	cout << s.age << endl << endl;

	test02(&s);
	cout << endl << s.name << endl;
	cout << s.age << endl << endl;

	s = test03(&s);
	cout << endl << s.name << endl;
	cout << s.age << endl << endl;
}