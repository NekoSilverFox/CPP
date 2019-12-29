#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include "MyArray.h"
using namespace std;


void test01()
{
	//堆区创建数组
	MyArray * array = new MyArray(30);

	MyArray  * array2 = new MyArray(*array);  //new方式指定调用拷贝构造
	MyArray array3 = *array;    //构造函数返回的本体

	//MyArray * array4 = array; //这个是声明一个指针 和array执行的地址相同，所以不会调用拷贝构造

	delete array;
	//尾插法测试
	for (int i = 0; i < 10;i++)
	{
		array2->push_Back(i);
	}
	//获取数据测试
	for (int i = 0; i < 10;i++)
	{
		cout << array2->getData(i) << endl;
	}
	
	//设置值测试
	array2->setData(0, 1000);

	cout << array2->getData(0) << endl;;

	//获取数组大小
	cout << "array2 的数组大小为： " << array2->getSize() << endl;


	//获取数组容量
	cout << "array2 的数组容量为： " << array2->getCapacity() << endl;

	//获取 设置 数组内容  如何用[]进行设置和访问
	array3.push_Back(100000);
	cout << array3.getData(0) << endl;
	cout << array3[0] << endl;
	array3[0] = 100; // 100000 = 100
	cout << array3[0] << endl;

}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}