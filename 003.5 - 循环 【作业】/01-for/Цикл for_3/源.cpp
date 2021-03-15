#include <iostream>
using namespace std;
int main() {

	int _long, _width;
	int i, r;

	cout << "LONG: "; cin >> _long;
	cout << "WIDTH: "; cin >> _width;

	for (r =  1;  r<= _width; r++) {

		for (i = 1; i <= _long; i++) {
			cout << "* ";
		}

		cout << endl;
	}

	cin.get();
	return 0;
}