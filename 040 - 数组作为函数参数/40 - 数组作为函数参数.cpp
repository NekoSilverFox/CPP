//1��������Ϊ�������� �����˻�Ϊָ��
//2���ڴ�������ʱ��Ҫ��������ĸ���
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

	int long_sizeof = sizeof(arr) / sizeof(arr[0]); // error    char ���͵����飨�ַ�����������ô����������  ֻ�����������ַ�����
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
