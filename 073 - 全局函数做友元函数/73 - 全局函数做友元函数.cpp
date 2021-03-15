#include <iostream>
#include <string>
using namespace std;


class Building
{
	// 让好基友变好朋友 ---- 友元函数！
	// 要在类内进行声明
	friend void goodGay(Building* building);

public:
	Building()
	{
		this->m_VisitRoom = "客厅";
		this->m_BedRoom = "卧♂室";
	}

public:
	string m_VisitRoom;
private:
	string m_BedRoom;
};

// 全局函数
void goodGay(Building* building)
{
	cout << "好基友正在访问---" << building->m_VisitRoom << endl;
	cout << "好基友正在访问---" << building->m_BedRoom << endl;

}

void test01()
{
	Building* b1 = new Building; // 分配内存时会调用 构造函数！（复习）
	// Building b1;
	goodGay(b1);
}

int main()
{
	test01();
}