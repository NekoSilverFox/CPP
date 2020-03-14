#include<string>
#include<iostream>
using namespace std;

// 使用系统算法的头文件
#include<algorithm>
#include<vector>

// 迭代器  - 遍历功能 - 用指针理解
// 普通指针也是一种迭代器
void test01()
{
	int array1[] = { 1,2,3,4,5 };

	int* p = array1; //指针指向数组首地址  &array[0]

	for (int i = 0; i < 5; ++i)
	{
		// cout << array1[i] << " ";
		cout << *(p++) << " "; 
	}
	cout << endl;
}


void myPrint(int num)
{
	cout << num << " ";
}

void test02()
{
	// 声明容器
	vector<int> v; //声明一个容器  这个容器中存放int类型数据 对象名称v

	// 向容器中加入数据
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);


	// iterator - 迭代器
	// 利用迭代器 遍历容器中的元素
	vector<int>::iterator itBegin = v.begin(); // .begin - 指向的是容器中的起始位置
	vector<int>::iterator itEnd = v.end(); // .end - 指向的是容器中！！！最后一个元素的下一个位置！！！

	//1.  使用迭代器遍历
	while (itBegin != itEnd)
	{
		cout << *(itBegin++) << " ";
	}
	cout << endl;

	// 2. 使用for遍历
	for (vector<int>::iterator it = v.begin(); it < v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;


	// 3. 利用算法
	for_each(v.begin(), v.end(), myPrint);
	cout << endl;
}


// 操作自定义数据类型
class Person
{
public:
	Person(string name, int age) : name_(name) , age_(age){}
	string name_;
	int age_;
};

void test03()
{
	vector<Person> v;
	Person p1("冰糖雪狸", 13);
	Person p2("狐萝卜", 14);
	Person p3("彩蛋", 17);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);

	// 遍历
	for (vector<Person>::iterator it = v.begin(); it != v.end(); ++it)
	{
		cout << "Name : " << (*it).name_ << " Age : " << it->age_ << endl;
	}
}


//存放自定义数据类型的指针
void test04()
{
	vector<Person*> v;
	Person p1("冰糖雪狸", 13);
	Person p2("狐萝卜", 14);
	Person p3("彩蛋", 17);

	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);

	for (vector<Person*>::iterator it = v.begin(); it < v.end(); ++it)
	{
		cout << "Name : " << (*it)->name_ << " Age : " << (*it)->age_ << endl;
	}

}


void test05()
{
	// 容器嵌套容器
	vector<vector<int>> v;

	vector<int>v1;
	vector<int>v2;
	vector<int>v3;

	for (int i = 0; i < 5; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 10);
		v3.push_back(i + 100);
	}

	// 将小容器放入到大容器中
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);

	for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++)
	{
		for (vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++)
		{
			cout << *vit << " ";
		}
		cout << endl;
	}

}
int main()
{
	// test01();
	test02();
	test03();
	test04();
	test05();
}