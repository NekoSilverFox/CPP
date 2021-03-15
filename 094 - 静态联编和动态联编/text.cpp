#include<iostream>
using namespace std;
// 94 - 静态联编和动态联编

class Animle
{
public:
	 virtual void speak()
	{
		cout << "小动物们在说话" << endl;
	}
	 void eat()
	 {
		 cout << "小动物们在吃饭" << endl;
	 }
};

class Fox : public Animle
{
public:
	 void speak()
	{
		cout << "What's the fox say? Yiff Yiff!!!!!" << endl;
	}
	 void eat()
	 {
		 cout << "Fox are having lanch" << endl;
	 }
};

// 调用doSpeak ，speak函数的地址早就绑定好了，早绑定，静态联编，编译阶段就确定好了地址
// 如果想调用fox的speak，不能提前绑定好函数的地址了，所以需要在运行时候再去确定函数地址
// 动态联编，写法 doSpeak方法改为虚函数,在父类上声明虚函数，发生了多态
// 父类的引用或者指针 指向 子类对象
void dospeak(Animle& animle) //Animal & animal = fox
{
	animle.speak();
}

void test01()
{
	Fox f1;
	dospeak(f1);
}

void test02()
{
	//Animle* an = new Animle;
	//an->speak();

	Animle* an = new Fox;
	an->speak();
	// *(int*)* (int*)an 函数地址，函数指针可以指向函数地址
	((void(*)())	(*(int*) * (int*)an)) ();
}

int main()
{
//	test01();
	test02();
	cout << sizeof(Animle) << endl;
	cout << sizeof(Fox) << endl;
}