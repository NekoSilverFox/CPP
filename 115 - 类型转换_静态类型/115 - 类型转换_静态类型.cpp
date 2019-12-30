#include<iostream>
using namespace std;

// 类型 = static_cast<要转换成的类型>(要转换的对象)


//静态转换
//基础类型
void test01()
{
	char a = 'a';
	double d = static_cast<double>(a);
	cout << d << endl << endl;

	a = static_cast<char>(d + 1);
	cout << a << endl << endl;

}


//父子之间转换
class Base {};
class Son : public Base{};
class Other{};
void test02()
{
	Base* base = nullptr;
	Son* son = nullptr;
	Other* other = nullptr;

	// 向下类型转换	把base转为 Child*类型		不安全
	Son* son_2 = static_cast<Son*>(base);
	son = static_cast<Son*>(base);

	// 向上类型转换	把son转为 Base* 类型		安全
	Base* base_2 = static_cast<Base*>(son);
	base = static_cast<Base*>(son);

	// 其他类型转换	不可以！！ 无效！！！
	Other* other_2 = static_cast<Other*>(son);
	other = static_cast<Other*>(base);

}

int main()
{
	test01();
}