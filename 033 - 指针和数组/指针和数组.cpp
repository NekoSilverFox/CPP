#include<iostream>
using namespace std;

void test01()
{
	int* p;
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };

	// ��ӡ�������飺
	cout << "���������Ϊ��" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << "  ";
	}

	// ��������׵�ַ ��ֵ�� p ָ��
	p = arr;
	cout << endl << endl << "p = arr" << endl;
	cout << "���������Ϊ��ʹ����ָ���������" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << *(p + i) << "  ";
	}


	// ����++����ָ��ָ��ĵ�ַ����++��������������ĸ�ֵ
	p++;  // ��ʱ p ָ����� arr[1] �� ��ַ�������� arr[0]
	cout << endl << endl << "p++   <---- ʹ�õĲ���" << endl;
	cout << "���������Ϊ��ʹ����ָ���ַ++��������" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << *(p + i) << "  ";
	}

	p = &arr[7];  // ��ʱ p ָ����� arr[7] �� ��ַ��ע��� ��&��
	*p = 66;
	cout << endl << endl << "p = &arr[7]	  *p = 66   <---- ʹ�õĲ���" << endl;

	cout << "*(p + i) ѭ�� :" ;
	for (int i = 0; i < 10; i++)
	{
		cout <<  *(p + i) << "  ";
	}

	cout << endl << "arr[i] ѭ�� :";
	for (int i = 0; i < 10; i++)
	{
		cout <<arr[i] << "  ";
	}


	cout << endl << endl << "����ط����ܻ�������Ǳ����������⣬������еĽ���ǶԵģ�---->";

	*(p + 4) = 233;
	cout << endl << endl << "*(p + 4) = 233   <---- ʹ�õĲ���" << endl;
	cout << "*(p + i) ѭ�� :";
	for (int i = 0; i < 13; i++)
	{
		cout << *(p + i) << "  ";
	}

	cout << endl << "arr[i] ѭ�� :";


	for (int i = 0; i < 13; i++)
	{
		cout << arr[i] << "  ";
	}// ����ط����ܻ�������Ǳ����������⣬������еĽ���ǶԵģ�



	int len = p - arr;
	cout << endl << endl << "int len = p - arr   p = &arr[7]  <---- ʹ�õĲ���" << endl;
	cout << "p ��ʱ�ĵ�ַ��" << p << endl;
	cout << "arr ��ʱ�ĵ�ַ��" << arr << endl;
	cout << "len = p - arr = " << len << endl;

} 

int main()
{
	test01();
	return 0;
}