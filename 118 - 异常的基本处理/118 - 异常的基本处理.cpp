// 118 - �쳣�Ļ�������
#include<iostream>
using namespace std;

int myChuFa(int a, int b)
{
	if (b == 0)
	{
		throw - 1;
	}
	return a / b;
	
}

void catchError()
{
	try //��һ��
	{
		myChuFa(10 , 0);
	}
	catch (int) //�����쳣
	{
		throw; //������봦������쳣 �����Լ��������׳�
		cout << "ERROR in the my function" << endl;
	}
}

int main()
{
	try
	{
		catchError();
	}
	catch (...)
	{
		cout << "The other Error in the main function" << endl;
	}
}