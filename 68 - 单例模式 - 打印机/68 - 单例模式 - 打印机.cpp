#include<iostream>
#include<cstring>
using namespace std;

class Penter
{
private:
	static Penter* singlePenter;

	Penter() { useTime = 0; };

	Penter(const Penter& pt) {};

	int useTime;

public:
	static Penter* getSinglePenter()
	{
		return singlePenter;
	}
	void printText(string test)
	{
		cout << test << endl;
		useTime++;
		cout << "��ӡ��ʹ�õĴ���Ϊ��" << useTime << endl;
	}


};
Penter* Penter::singlePenter = new Penter;

int main()
{
	//�õ���ӡ��
	Penter* p1 = Penter::getSinglePenter();

	p1->printText("123");
	p1->printText("234");
	p1->printText("345");
	p1->printText("456");
}