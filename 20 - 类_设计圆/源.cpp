#include<iostream>
using namespace std;

class Circall {

public:

	double R;
	const double pi = 3.1415926;

	double ZouChang(){
		return 2 * pi * R;
	}
	
	double MianJi() {
		return pi * R * R;
	}
};

int main() {

	Circall zc;
	cout << "�Զ�����Բ���ܳ������" << endl;
	cout << "������뾶��"; cin >> zc.R;
	cout << "�ܳ�Ϊ��" << zc.ZouChang() << endl;
	cout << "���Ϊ��" << zc.MianJi() << endl;

	return 0;
}