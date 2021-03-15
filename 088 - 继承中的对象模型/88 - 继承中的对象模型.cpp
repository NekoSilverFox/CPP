#include<iostream>
using namespace std;

class Base
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

class Son : public Base
{
public:
	int m_D;
};


int main()
{
	cout << "派生类Son 的大小为：" << sizeof(Son) << endl;
}
// cl /d1 reportSingleClassLayout Son test.cpp