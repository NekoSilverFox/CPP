#include<iostream>
using namespace std;

/*
标准输入流对象cin，重点掌握的函数
cin.get() //一次只能读取一个字符
cin.get(一个参数) //读一个字符
cin.get(两个参数) //可以读字符串
cin.getline()
cin.ignore()
cin.peek() 偷窥
cin.putback()

*/

void cinget01()
{
	// 如果 输入as  缓冲区中“ a   s 换行“
	// 第一个a拿 - a；
	// 第二个a2拿 - s
	// 第三个a3拿 - 换行
	// 第四个a4拿 - 等待下次输入
	char a = cin.get();
	cout <<"a =  " <<  a << endl;

	char a2 = cin.get();
	cout << "a2 =  " << a2 << endl;

	char a3 = cin.get();
	cout << "a3 =  " << a3 << endl;

	char a4 = cin.get();
	cout << "a4 =  " << a4 << endl;
}

// cin.get(两个参数)  可以读字符串
void cinget02() // 结论：cin.get(两个参数)  读取字符串时，不会把换行符拿走，换行还在缓冲区
{
	char arr[1024];
	cin.get(arr, 1024); // 读的字符串
	
	char a = cin.get();
	if (a == '\n')
	{
		cout << "换行还在缓冲区" << endl;
	}
	else
	{
		cout << "换行不在缓冲区" << endl;
	}

	cout << arr << endl;

}

void cingetline() // 结论：cin.getline() 把换行符读取，并且扔掉了
{
	char arr[1024];
	cin.getline(arr, 1024);
	char a = cin.get();
	if (a == '\n')	{	cout << "换行还在缓冲区" << endl;}
	else	{cout << "换行不在缓冲区" << endl;}
	cout << arr << endl;
}


void cin_ignore01()
{
	cin.ignore(); // 没有参数代表忽略一个字符
	char c = cin.get();

	cout << "c = " << c << endl;
}

void cin_ignore02()
{
	char arr[1024];
	cin.ignore(2); // 参数 n , 代表忽略 n 个字符
	cin.get(arr, 1024);
	cout << "arr = " << arr << endl;
}



// 偷窥
void cin_peek()
{
	char c = cin.peek(); // 如果输入 as，偷看一眼输入的字符再放回缓冲区，缓冲区中还是 as
	cout << "c = " << c << endl;

	c = cin.get();
	cout << "c = " << c << endl;
}


// 放回
void cin_putback()
{
	char c = cin.get();
	cin.putback(c);
	char arr[1024];
	cin.getline(arr, 1024);
	cout << arr << endl;
}



int main()
{
	// cinget02();
	// cingetline();
	// cin_ignore01();
	// cin_ignore02();
	// cin_peek();
	cin_putback();
}