#include <iostream>
#include <string>
using namespace std;


class Building
{
	// �úû��ѱ������ ---- ��Ԫ������
	// Ҫ�����ڽ�������
	friend void goodGay(Building* building);

public:
	Building()
	{
		this->m_VisitRoom = "����";
		this->m_BedRoom = "�ԡ���";
	}

public:
	string m_VisitRoom;
private:
	string m_BedRoom;
};

// ȫ�ֺ���
void goodGay(Building* building)
{
	cout << "�û������ڷ���---" << building->m_VisitRoom << endl;
	cout << "�û������ڷ���---" << building->m_BedRoom << endl;

}

void test01()
{
	Building* b1 = new Building; // �����ڴ�ʱ����� ���캯��������ϰ��
	// Building b1;
	goodGay(b1);
}

int main()
{
	test01();
}