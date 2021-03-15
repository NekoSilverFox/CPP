#include <iostream>
#include <conio.h>
using namespace std;
int main(void) {

	int a, b, c;

	cout << "a="; cin >> a;
	cout << "b="; cin >> b;
	cout << "c="; cin >> c;

	if ((a == b) && (b == c)) {
		cout << "3";
		}

	else if (((a == b) && ((b != c) || (b != a)))|| ((a == c) && (( a != b) || (b != c ))) || ((b == c) && ((c != b) || (c != a)))) {
		cout << "2";
	}
	else {
		cout << "0";
	}
	
	cin.get();
	return 0;
}