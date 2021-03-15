#include<iostream>
using namespace std;


// strchr() 函数：查找字符在字符串中首次出现的位置。一般用于 char 类型数组
void fun_strchr()
{
	char arr[] = "hello world";
	char ch = 'o';

	char* p = strchr(arr, ch);

	cout << p << endl;
}


// 使用数组实现
char* myStrchr(char* arr, char ch)
{
	int i = 0;
	while (arr[i] != '\0')
	{
		if (arr[i] == ch)
		{
			return &arr[i];
		}
		i++;
	}
	return NULL;
}


// 使用数组实现
char* myStrchr_p(char* arr, char ch)
{
	char* p = arr;
	while (*p != '\0')
	{
		if (*p == ch)
		{
			return p;
		}
		p++;
	}
	return NULL;
}


int main()
{
	char arr[] = "hello world";
	char ch = 'o';

	cout << arr << endl;

	cout << myStrchr_p(arr,ch);
	
	//cout << myStrchr(arr,ch);
	// fun_strchr();
}