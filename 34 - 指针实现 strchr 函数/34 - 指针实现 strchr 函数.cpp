#include<iostream>
using namespace std;


// strchr() �����������ַ����ַ������״γ��ֵ�λ�á�һ������ char ��������
void fun_strchr()
{
	char arr[] = "hello world";
	char ch = 'o';

	char* p = strchr(arr, ch);

	cout << p << endl;
}


// ʹ������ʵ��
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


// ʹ������ʵ��
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