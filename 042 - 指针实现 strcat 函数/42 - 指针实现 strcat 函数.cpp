#include<iostream>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

// strcat - 讲一个字符串 追加在另一个的后面

void fun_strcat_test(char* arr1,char* arr2)
{
	// cout << strcat(arr1, arr2);
}


void my_strcat(char* arr1, char* arr2)
{
	while (*arr1)
	{
		arr1++;
	}
	while (*arr2)
	{
		*arr1 = *arr2;
		arr1++;
		arr2++;
	}
}

int main()
{
	char arr1[1000] = "Hello";
	char arr2[] = "World";

	// fun_strcat_test(arr1, arr2);
	my_strcat(arr1, arr2);
	cout << arr1 << endl;
}