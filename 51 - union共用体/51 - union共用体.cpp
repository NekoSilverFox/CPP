#include<iostream>
using namespace std;
union foxes
{
	double dou_fox;
	int int_fox;
	char ch_fox;
	float fl_fox;
};

int main()
{
	foxes nick;
	nick.ch_fox = 'a';
	cout << nick.ch_fox << endl;

	nick.dou_fox = 100;
	cout << nick.dou_fox << endl;

	nick.fl_fox = 3.14;
	cout << nick.fl_fox << endl;

	cout << "============================" << endl;
	cout << nick.ch_fox << endl;
	cout << nick.dou_fox << endl;
	cout << nick.fl_fox << endl;

	cout << "������ֻ�ܱ�֤���һ�εĸ�ֵ��׼ȷ�ģ����������ʹ�ã�����ʡ�ڴ棡" << endl;
}