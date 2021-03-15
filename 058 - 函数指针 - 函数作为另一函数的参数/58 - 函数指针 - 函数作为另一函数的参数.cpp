#include <iostream>
using namespace std;

int fun01(int a, int b)
{
	cout << "fun01" << endl;
	return a + b;
}

int fun02(int a, int b)
{
	cout << "fun02" << endl;
	return a - b;
}

int fun03(int a, int b)
{
	cout << "fun03" << endl;
	return a * b;
}

//  ������Ϊ��һ�����Ĳ��� ���
int doLogic(int(*fun)(int, int))
{
	int a = 6, b = 9;
	double ret = fun(a, b);
	return ret;
}

// ����ָ������ ���
void fun_arr_p()
{
	int(*fun_arr[3])(int, int);
	fun_arr[0] = fun01; // ע�⣬�ṩ���ǽӿڲ���Ҫ ������
	fun_arr[1] = fun02;
	fun_arr[2] = fun03;

	for (int i = 0; i < 3; i++)
	{
		fun_arr[i]; // �ǵ�ַ��δ���ú���������ӡ�������������ţ����
		fun_arr[i](i, i * 6);// <---- ע�⣬����Ҫ�����Ų��ܵ��ú������������
		cout << fun_arr[i] << endl; // ��ӡ���ǵ�ַ������δ���� ���
		cout << fun_arr[i](i, i * 6) << endl; // �����Ų��ܵ��ú���!!! ���
	}
}

int main()
{	
	//  ������Ϊ��һ�����Ĳ��� ����
	cout << doLogic(fun01) << endl;

	// ����ָ������
	fun_arr_p();
}