#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <string>

class GoodGay;
class Building;


class GoodGay
{
public:
	GoodGay();
	void visitRoom();
private:
	Building* building;
};



class Building
{

	friend void GoodGay::visitRoom();

public:
	Building();
public:
	string m_SittingRoom;
private:
	string m_BedRoom;
};
Building::Building()
{
	this->m_BedRoom = "Bed Room";
	this->m_SittingRoom = "Sitting Room";
}





int main() {

	GoodGay gg;
	gg.visitRoom();

	system("pause");
	return EXIT_SUCCESS;
}