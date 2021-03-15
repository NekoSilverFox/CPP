#include<iostream>
using namespace std;

int fun_static() {
	static int num = 10;

	num++;

	return num;
}



int main() {

	for (int i = 0; i < 10; i++) {
		cout << fun_static() << endl;
	}

	cin.get();
	return 0;
}