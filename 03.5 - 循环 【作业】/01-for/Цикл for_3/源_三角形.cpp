#include <iostream>
using namespace std;
int main2() {

	int  N;
	int l;		// l 为三角形的边长
	
	cout << "N= "; cin >> N;

	for (l = 1; l <= N; l++) {
		cout << "* ";
	}

	cout << endl;

	cin.get();
	return 0;
}