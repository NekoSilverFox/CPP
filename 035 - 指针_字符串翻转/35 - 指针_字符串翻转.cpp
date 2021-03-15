#include<iostream>
using namespace std;

char* rec(char* arr)
{
	int len = strlen(arr);
	cout << "字符串的长度为：" << len << endl;	
	
	char* p_1 = arr;
	char* p_end = &arr[len - 1];
	while (p_1 < p_end)
	{
		char temp;
		temp = *p_1;
		*p_1 = *p_end;
		*p_end = temp;
		p_1++;
		p_end--;
	}
	return arr;
}

int main()
{
	char arr[] = "Hello world";
	cout << arr << endl;
	cout << rec(arr);
}