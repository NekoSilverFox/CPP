#include <iostream>
#include <conio.h>
using namespace std;
int main(void) {

	double a, b, c;
	cout << "a="; cin >> a;
	cout << "b="; cin >> b;
	cout << "c="; cin >> c;

	if ((a > b) && (b > c)) {
		cout << a, b, c;
	}
	else {
		cout << c, b, a;
	}

	if ((a < b) && (b < c)) {
		cout << c, b, a;
	}
	else {
		cout << 
	}

	cin.get();
	return 0;
}