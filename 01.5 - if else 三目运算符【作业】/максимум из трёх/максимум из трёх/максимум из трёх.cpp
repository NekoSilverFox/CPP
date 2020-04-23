#include <iostream>
#include <climits>
using namespace std;
int main(void) {

	int a, b, c;
	cout << "a="; cin >> a;
	cout << "b="; cin >> b;
	cout << "c="; cin >> c;

	/*
	if (a > b){
		if ((a > c) && (b > c)){
		cout << "妙忘抗扼我技批技 我戒 找把忸抒 - " << a;
}
		else {
		cout << "妙忘抗扼我技批技 我戒 找把忸抒 - " << c;
}
	}

	// b > a
	else {
		if ((b > c) && (c < a)){
			cout << "妙忘抗扼我技批技 我戒 找把忸抒 - " << b;
}
		else {
				cout << "妙忘抗扼我技批技 我戒 找把忸抒 - " << c;
			}
		}
		*/

	int max = a > b ? a : b;
	max = max > c ? max : c;

	cout << "妙忘抗扼我技批技 我戒 找把忸抒 - " << max << endl;

	cin.get();
	return 0;
}
