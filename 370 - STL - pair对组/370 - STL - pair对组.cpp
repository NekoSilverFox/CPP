#include<iostream>
#include<string>
using namespace std;

// 使用pair对组，不需要引入任何头文件！！！


// 第一种创建
void test01()
{
	// 对组只能引入两个类型
	pair<string, int> pair_1("Tom", 13);

	// 取值
	cout << pair_1.first << "  " << pair_1.second << endl;
}


// 第二种创建
void test02()
{
	// 建议使用
	pair<string, int> pair_2 = make_pair("Jerry", 14);

	cout << pair_2.first << "  " << pair_2.second << "  " << endl;
}

int main()
{
	test01();
	test02();
}