#include <iostream>
#include<string>
using namespace std;

class Building;
class GoodGay;

class Building
{
	//让好基友类 作为 Building的好朋友
	friend class GoodGay;

public:
	Building();
public:
	string m_SittingRoom;
private:
	string m_BedRoom;
};

Building::Building()
{
	this->m_SittingRoom = "客厅";
	this->m_BedRoom = "卧♂室";
}

class GoodGay
{

public:
	GoodGay();
	void visitRoom();

private:
	Building* building;
};

GoodGay::GoodGay()
{
	building = new Building;
}

void GoodGay::visitRoom()
{
	cout << "好基友正在访问-----" << this->building->m_SittingRoom << endl;
	cout << "好基友正在访问-----" << this->building->m_BedRoom << endl;
}

int main() {
	GoodGay gg;
	gg.visitRoom();
}