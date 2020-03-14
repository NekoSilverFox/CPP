#include<iostream>
#include<vector>
using namespace std;

void vector_test()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
		cout << v.capacity() << " "; // v.capacity()容器的容量
	}
	cout << endl;
}


/*
vector构造函数
vector<T> v; //采用模板实现类实现，默认构造函数
vector(v.begin(), v.end());//将v[begin(), end())区间中的元素拷贝给本身。
vector(n, elem);//构造函数将n个elem拷贝给本身。
vector(const vector &vec);//拷贝构造函数。
*/
void test01()
{
	// vector<T> v; //采用模板实现类实现，默认构造函数
	vector<int> v;

	// 1. vector(v.begin(), v.end());//将v[begin(), end())区间中的元素拷贝给本身。
	int array_[] = { 1,2,3,4,5 };
	vector<int> v1(array_, array_ + sizeof(array_) / sizeof(int));
	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	// 2. vector(v.begin(), v.end());//将v[begin(), end())区间中的元素拷贝给本身。
	vector<int> v2(v1.begin(), v1.end());
	for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	// 3. vector(n, elem);//构造函数将n个elem拷贝给本身。
	vector<int> v3(10, 66);
	for (vector<int>::iterator it = v3.begin(); it != v3.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}


/*
3.2.4.2 vector常用赋值操作
assign(beg, end);//将[beg, end)区间中的数据拷贝赋值给本身。
assign(n, elem);//将n个elem拷贝赋值给本身。
vector& operator=(const vector  &vec);//重载等号操作符
swap(vec);// 将vec与本身的元素互换。
*/
void test02()
{
	vector<char> v1;
	char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };

	// assign(beg, end);//将[beg, end)区间中的数据拷贝赋值给本身。
	v1.assign(&arr[1], &arr[4]);
	for (vector<char>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	// assign(beg, end);//将[beg, end)区间中的数据拷贝赋值给本身。
	vector<char> v2;
	v2.push_back('A');
	v2.push_back('B');
	v2.push_back('C');
	v2.push_back('D');
	v2.push_back('E');

	vector<char> v3(v2.begin() + 1, v2.end());
	for (vector<char>::iterator it = v3.begin(); it != v3.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	// assign(n, elem);//将n个elem拷贝赋值给本身。
	v3.assign(10, '$');
	for (vector<char>::iterator it = v3.begin(); it != v3.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	// swap(vec);// 将vec与本身的元素互换。
	v3.swap(v2);
	cout << "swap() 之后的 v3 ：" << endl;
	for (vector<char>::iterator it = v3.begin(); it != v3.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	cout << "swap() 之后的 v2 ：" << endl;
	for (vector<char>::iterator it = v2.begin(); it != v2.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

}


/*
3.2.4.3 vector大小操作
size();//返回容器中元素的个数
empty();//判断容器是否为空
resize(int num);//重新指定容器的长度为num，若容器变长，则以默认值填充新位置。如果容器变短，则末尾超出容器长度的元素被删除。
resize(int num, elem);//重新指定容器的长度为num，若容器变长，则以elem值填充新位置。如果容器变短，则末尾超出容器长>度的元素被删除。
capacity();//容器的容量
reserve(int len);//容器预留len个元素长度，预留位置不初始化，元素不可访问。
*/
void test03()
{
	vector<char>v;
	v.push_back('X');
	v.push_back('Y');
	v.push_back('Z');

	// size(); 返回容器中元素的个数
	cout << "size = " << v.size() << endl;

	// empty();//判断容器是否为空
	if (v.empty()) cout << "vector 容器为空" << endl;
	else  cout << "vector 容器不为空" << endl;


	cout << endl;
	// resize(int num);//重新指定容器的长度为num，若容器变长，则以默认值###########默认值为空字符###########填充新位置。如果容器变短，则末尾超出容器长度的元素被删除。
	v.resize(10);
	cout << "size = " << v.size() << endl;
	for (vector<char>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << '\'' << endl << endl;


	// resize(int num, elem);//重新指定容器的长度为num，若容器变长，则以elem值填充新位置。如果容器变短，则末尾超出容器长>度的元素被删除。
	v.resize(20, '#');
	cout << "size = " << v.size() << endl;
	for (vector<char>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << '\'' << endl << endl;


	v.resize(5, '#');
	cout << "size = " << v.size() << endl;
	for (vector<char>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << '\'' << endl << endl;


	// reserve(int len);//容器预留len个元素长度，预留位置不初始化，元素不可访问。
	// v.reserve(3);
	v.reserve(10);
	cout << "size = " << v.size() << endl;
	for (vector<char>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << "\' <- 预留位置不初始化，元素不可访问。!!!" << endl << endl; // 预留位置不初始化，元素不可访问。!!!
}

int main()
{
	vector_test();
	cout << endl << "-----------------------------------------------------------" << endl << endl;
	test01();
	cout << endl << "-----------------------------------------------------------" << endl << endl;
	test02();
	cout << endl << "-----------------------------------------------------------" << endl << endl;
	test03();
	cout << endl << "-----------------------------------------------------------" << endl << endl;
}