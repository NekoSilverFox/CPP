#include <iostream>
#define NUM 15
using namespace std;

// ���ڼ��� n �ļ��η��ĺ��� ��x-Ϊ�ݣ�n-Ϊָ����index-Ϊָ��������
double index(double  x, int n) {  
	double sqr = x;
	for (int for_i = 1; for_i < n; for_i++)
		sqr *= x;
	return sqr;
	}

// No.4 ����ҵ��#4 ����ߧܧ�ڧڣ�- ��17�⣬���� ln( x+1/ x-1 ) (2<x<3)
double fun19(double x) {
	double add = 0;
	for (double i = 1; i <= NUM; i++) {
		add += 1 / ((i * 2 - 1) * index(x, i * 2 - 1)); 
	}
	return add * 2;
}

// ������
int main() {
	double x;

	cout << "������ x ��ֵ��"; cin >> x; 

	if (x <= 2 || x >= 3 || !cin) {
		cerr << "ERROR! ����اߧ� �ӧӧ�էڧ� x, (2 < x < 3) !" << endl;
		return 1;
	}
	else {
		cout << fun19(x) << endl;
		return 0;
	}
}