#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>  //内建函数对象头文件
using namespace std;

// 1. 算数类函数对象
void test01()
{
	// 只有 negate 是一元运算，（取反仿函数）
	negate<int>n;
	cout << n(10) << endl
		<< n(-6) << endl;

	divides<double>div1;
	cout << div1(10, 3) << endl;
}


// 2. 关系运算类函数
void test02()
{
	vector<int>v;
	v.push_back(3);
	v.push_back(6);
	v.push_back(1);
	v.push_back(8);
	v.push_back(9);

	sort(v.begin(), v.end(), greater<int>());
	for_each(v.begin(), v.end(), [](int val) {cout << val << " "; });
}

// 3. 逻辑运算
void test03()
{
	vector<int>v;
	v.push_back(3);
	v.push_back(6);
	v.push_back(1);
	v.push_back(8);
	v.push_back(9);

	// vector<int>::iterator it = find_if(v, begin(), v.end(), logical_not<int>());
}

int main()
{
	test01();
	test02();
}