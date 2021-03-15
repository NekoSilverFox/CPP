#include<iostream>
using namespace std;

void test01()
{
	int* p;
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };

	// 打印测试数组：
	cout << "输入的数组为：" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << "  ";
	}

	// 将数组的首地址 赋值给 p 指针
	p = arr;
	cout << endl << endl << "p = arr" << endl;
	cout << "输入的数组为（使用了指针操作）：" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << *(p + i) << "  ";
	}


	// 利用++，将指针指向的地址进行++操作，及对数组的赋值
	p++;  // 此时 p 指向的是 arr[1] 的 地址，而不是 arr[0]
	cout << endl << endl << "p++   <---- 使用的操作" << endl;
	cout << "输入的数组为（使用了指针地址++操作）：" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << *(p + i) << "  ";
	}

	p = &arr[7];  // 此时 p 指向的是 arr[7] 的 地址，注意加 “&”
	*p = 66;
	cout << endl << endl << "p = &arr[7]	  *p = 66   <---- 使用的操作" << endl;

	cout << "*(p + i) 循环 :" ;
	for (int i = 0; i < 10; i++)
	{
		cout <<  *(p + i) << "  ";
	}

	cout << endl << "arr[i] 循环 :";
	for (int i = 0; i < 10; i++)
	{
		cout <<arr[i] << "  ";
	}


	cout << endl << endl << "这个地方可能会崩掉，是编译器的问题，但命令窗中的结果是对的！---->";

	*(p + 4) = 233;
	cout << endl << endl << "*(p + 4) = 233   <---- 使用的操作" << endl;
	cout << "*(p + i) 循环 :";
	for (int i = 0; i < 13; i++)
	{
		cout << *(p + i) << "  ";
	}

	cout << endl << "arr[i] 循环 :";


	for (int i = 0; i < 13; i++)
	{
		cout << arr[i] << "  ";
	}// 这个地方可能会崩掉，是编译器的问题，但命令窗中的结果是对的！



	int len = p - arr;
	cout << endl << endl << "int len = p - arr   p = &arr[7]  <---- 使用的操作" << endl;
	cout << "p 此时的地址：" << p << endl;
	cout << "arr 此时的地址：" << arr << endl;
	cout << "len = p - arr = " << len << endl;

} 

int main()
{
	test01();
	return 0;
}