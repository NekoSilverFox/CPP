#include<iostream>
using namespace std;

class Animal
{
public:
	Animal() :m_age(0) {}
public:
	int m_age;
};

class Sheep : virtual public Animal
{
	// 空实现
};

class Tuo : virtual public Animal
{

};

class SheepTuo : public Sheep, public Tuo
{

};

int main()
{
	SheepTuo st;
	st.Sheep::m_age = 10;
	st.Tuo::m_age = 20;

	// cout << st.m_age << endl; 不会二义性
	cout << st.Sheep::m_age << endl;
	cout << st.Tuo::m_age << endl;
	cout << st.m_age << endl; // 不会二义性，操作的是一份数据
	

}

// 类图在根目录文件夹中！！
// 输第152 页
// 注意看偏移量！！