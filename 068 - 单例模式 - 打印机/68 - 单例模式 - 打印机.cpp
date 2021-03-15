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
		cout << "打印机使用的次数为：" << useTime << endl;
	}


};
Penter* Penter::singlePenter = new Penter;

int main()
{
	//拿到打印机
	Penter* p1 = Penter::getSinglePenter();

	p1->printText("123");
	p1->printText("234");
	p1->printText("345");
	p1->printText("456");
}