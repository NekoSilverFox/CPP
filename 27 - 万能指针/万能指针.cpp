#include <iostream>
using namespace std;
void test01()
{
	int a = 9;
	char ch = 't';
	void* p;

	p = &a;
	cout << "p = &a      p = " << p << endl;

	p = &ch;
	cout << "p = &ch      p = " << p << endl;

	int arr[10] = {0};
	for (int i = 0; i < 10; i++)
	{
		cout << "	  " << arr[i];
	}
	cout << endl;

	p = arr;
	cout << "p = arr      p = " << p << endl;

	*(int* )p = 6.78;
	cout << "*(int*)p = 6;     *(int*)p =  " << *(int*)p << endl;// 使用指针变量指向的内存时，转换为 int*
	cout << "*(int*)p = 6;     (int* )p =  " << (int* )p << endl; // 并且注意打括号
	   
	/*char test = cin.get();
	cout << "标志位的状态为：" << test << endl << endl;*/

	for (int i = 0; i < 10; i++)
	{
		cout << "	  " << arr[i];
	}
	cout << endl;
	cout << endl;


	*((int*)p+1) = 7;
	cout << "*((int*)p+1) = 7     *(int*)p =  " << *(int*)p << endl;
	cout << "*((int*)p+1) = 7     (int* )p =  " << (int*)p << endl;

	for (int i = 0; i < 10; i++)
	{
		cout << "	  " << arr[i];
	}
	cout << endl;
	cout << endl;
}

void test02()
{
	void* p = NULL;

	int a = 10;
	p = (void*)& a; // 指向   变量  时，最好转为 void*


	// 使用指针变量指向的   内存   时，转换为 int*
	*((int*)p) = 11;

	//*p = 11;

	cout << endl << endl << endl;
	cout << p << endl;
	cout << *((int*) p) << endl;
	cout << a << endl;


}

int main()
{

	test01();
	test02();

}