#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// 一元谓词
class MoreThan2
{
public:
	bool operator()(int val)
	{
		return val > 2;
	}
};

void test01()
{
	vector<int> v;
	v.push_back(2);
	v.push_back(5);
	v.push_back(4);
	v.push_back(6);
	v.push_back(2);
	v.push_back(1);

	//打印出所有大于2 的数 （注意要引入系统的头文件）
	
	// 1.
	//MoreThan2 than2;
	// vector<int>::iterator it = find_if(v.begin(), v.end(), than2); // <--- 注意，这里是带括号的（），第三个参数，函数对象，匿名对象
	
	// 2.
	vector<int>::iterator it = find_if(v.begin(), v.end(), MoreThan2()); // <--- 注意，这里是带括号的（），第三个参数，函数对象，匿名对象
	if (it != v.end())
		cout << "找到了为 " << *it << " 的数！" << endl;
	else cout << "未找到！" << endl;
}


class MyCompare
{
public:
	bool operator()(int num1, int num2)
	{
		return num1 > num2;
	}
};

// 二元谓词
void test02()
{
	vector<int>v;
	v.push_back(3);
	v.push_back(10);
	v.push_back(4);
	v.push_back(3);
	v.push_back(8);
	v.push_back(7);

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
		cout << *it << " ";
	cout << endl;


	sort(v.begin(), v.end(), MyCompare());
	//for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	//	cout << *it << " ";
	//cout << endl;

	// 匿名函数 lambda 表达式 [](){};
	for_each(v.begin(), v.end(), [](int val) {cout << val << " "; });
}
int main()
{
	test01();
	test02();
}
