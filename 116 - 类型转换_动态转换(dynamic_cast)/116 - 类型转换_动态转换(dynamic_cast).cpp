#include<iostream>
using namespace std;

// 116 - 类型转换_动态转换(dynamic_cast) dynamic_cast非常严格，失去精度 或者不安全都不可以转换


// 普通类型转换
//基础类型不可以转换
void test01()
{
	int int_type = 10;
	double double_type = 3.14926;
	short short_type = 1.11;
	char chat_type = 'a';

	// double 转 shout （丢失精度）
	//short_type = dynamic_cast<short>(double_type);

	//// shout 转 double 
	//double_type = dynamic_cast<double>(short_type);

	//// int 转 double 
	//double_type = dynamic_cast<double>(int_type);
}


// 继承关系指针
class Base {};
class Son : public Base {};
class Other{};

void dynamicTest()
{

	Base* base = nullptr;
	Son* son = nullptr;
	Other* other = nullptr;

	// 向下类型转换 - 不安全 除非发生多态
	son = dynamic_cast <Son*>(base);

	// 向上类型转换 - 安全
	base = dynamic_cast<Base*>(son);

	// 其他类型转化 - 不支持
	son = dynamic_cast<Son*>(other);
	base = dynamic_cast<Base*>(other);
	other = dynamic_cast<Other*>(son);
}




// 继承关系指针 (发生了多态)
class Base2 { virtual void virtual_func() = 0; };
class Son2 : public Base2 { void virtual_fun() {} };
class Other2 {};

void dynamicTest2()
{

	Base2* base2 = nullptr;
	Son2* son2 = nullptr;
	Other2* other2 = nullptr;

	// 向下类型转换 - 不安全 - 但是发生了多态
	son2 = dynamic_cast <Son2*>(base2);

	// 向上类型转换 - 安全
	base2 = dynamic_cast<Base2*>(son2);

	// 其他类型转化 - 不支持
	son2 = dynamic_cast<Son2*>(other2);
	base2= dynamic_cast<Base2*>(other2);
	other2 = dynamic_cast<Other2*>(son2); // 发生了多态