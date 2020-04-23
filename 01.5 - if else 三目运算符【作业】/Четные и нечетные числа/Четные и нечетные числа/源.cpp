#include <iostream>
#include <climits>
using namespace std;
int main() {

	int a, b, c;
	cout << "a="; cin >> a; a %= 2;
	cout << "b="; cin >> b; b %= 2;
	cout << "c="; cin >> c; c %= 2;

	if ((a + b + c == 0) || ((a != 0) && (b != 0) && (c != 0))) {
	cout << "NO";
	}

	else {
		cout << "YES";
	}

	cin.get();
	return 0;
}