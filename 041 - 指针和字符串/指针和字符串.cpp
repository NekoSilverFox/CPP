#include<iostream>
using namespace std;

void test01(char* arr) // 未被调用
{
	char* p = NULL;
	p = arr;
	*p = 'A';
	p++;
	*p = 'B';

	cout << p << endl;					// ！！！！！重点！！！！！
	cout << sizeof(arr) << endl; // 如果此时打印，结果为 4 ，因为 此时 的 arr 为一个 char 类型的指针，而不是一个数组，只是指向了一个数组数组而已
}

int main()
{

	char arr[] = "Hello world";
	cout << arr << endl;

	char* p = NULL;
	p = arr;
	*p = 'A';
	p++;
	*p = 'B';

	cout << p << endl;
	// test01(arr);
	cout << arr << endl;
																				// strlen() ---> 不管有多少个字符，反正到“\0”结尾
	cout << "sizeof(arr) = " << sizeof(arr) << endl; // 结果为 12 而不是，10 或 11， 因为包含了 “空格”和“\0”
	cout << "strlen(arr) = " << strlen(arr) << endl; // 这才是字符串的   ->有效长度<-（包含“空格的”）！
	cout << "sizeof(p) = " << sizeof(p) << endl; // 结果为 4 ，为 char 类型的指针！
	cout << "strlen(p) = " << strlen(p) << endl; // strlen() ->有效长度<- 结果为 10 ，相当于是一个数组的首地址读到“\0”才停止

}