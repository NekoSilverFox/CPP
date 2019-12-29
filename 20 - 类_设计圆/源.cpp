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
	cout << "自动计算圆的周长和面积" << endl;
	cout << "请输入半径："; cin >> zc.R;
	cout << "周长为：" << zc.ZouChang() << endl;
	cout << "面积为：" << zc.MianJi() << endl;

	return 0;
}