// 118 - 异常的基本处理
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
	try //试一试
	{
		myChuFa(10 , 0);
	}
	catch (int) //捕获异常
	{
		throw; //如果不想处理这个异常 ，可以继续向上抛出
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