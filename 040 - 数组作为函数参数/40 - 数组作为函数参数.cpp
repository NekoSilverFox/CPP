//1、数组作为函数参数 可以退化为指针
//2、在传递数组时需要加上数组的个数
#include<iostream>
using namespace std;
void test01(char* arr)
{
	int i = 0;
	while (arr[i]!='\0')
	{

		i++;
	}
	cout << "The long is ( i ) " << i << endl;

	int len = strlen(arr);
	cout << "The long is ( len ) " << len << endl;

	int long_sizeof = sizeof(arr) / sizeof(arr[0]); // error    char 类型的数组（字符串）不能这么操作！！！  只能用以上两种方法！
	cout << "The long is ( long_sizeof ) " << long_sizeof << endl;

	long_sizeof = sizeof(*arr) / sizeof(arr[0]); // error
	cout << "The long is ( long_sizeof ) " << long_sizeof << endl;

	//long_sizeof = sizeof(&arr) / sizeof(arr[0]); // error
	//cout << "The long is ( long_sizeof ) " << long_sizeof << endl;
}

int main()
{
	char arrLetter[] = { 'H','e','l','l','o' };
	char arr[] = "Hello world";
	test01(arr);
}
