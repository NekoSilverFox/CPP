#include <iostream>
#include<string>
using namespace std;

class Building;
class GoodGay;

class Building
{
	//�úû����� ��Ϊ Building�ĺ�����
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
	this->m_SittingRoom = "����";
	this->m_BedRoom = "�ԡ���";
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
	cout << "�û������ڷ���-----" << this->building->m_SittingRoom << endl;
	cout << "�û������ڷ���-----" << this->building->m_BedRoom << endl;
}

int main() {
	GoodGay gg;
	gg.visitRoom();
}