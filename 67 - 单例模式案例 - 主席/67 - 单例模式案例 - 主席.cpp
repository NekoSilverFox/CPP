#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//创建主席类
//需求 单例模式  为了创建类中的对象，并且保证只有一个对象实例
class ChairMan
{
public:
	//提供 get方法 访问 主席
	static ChairMan* getInstance()
	{
		return singleMan;
	}

private:
	static ChairMan* singleMan;
	//1构造函数 进行私有化
	ChairMan()
	{
		cout << "创建国家主席 - 习近平" << endl;
	}
	//拷贝构造 私有化
	ChairMan (const ChairMan& c)
	{}
};
ChairMan* ChairMan::singleMan = new ChairMan;

int main()
{
	ChairMan* cm1 = ChairMan::getInstance();
	ChairMan* cm2 = ChairMan::getInstance();
	if (cm1 == cm2)
	{
		cout << "cm1 == cm2" << endl;
	}
	else
	{
		cout << "cm2 != cm2" << endl;
	}
}