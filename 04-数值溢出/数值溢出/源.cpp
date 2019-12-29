#include <iostream>
using namespace std;
int main() {

	int i = 2147483500; //2147483648      2^31 - 1

	for (i; i > 0; i++)
		cout << i << endl;

	cout << "But now i= " << i;






	/*
	char char_raw = 0x7f - 2;

	char char_1 = char_raw + 1;
	char char_2 = char_raw + 2;
	char char_3 = char_raw + 3;
	char char_4 = char_raw + 4;
	char char_5 = char_raw + 5;

	cout << "char_raw: " << char_raw << endl;
	cout << "char_1: " << char_1 << endl;
	cout << "char_2: " << char_2 << endl;
	cout << "char_3: " << char_3 << endl;
	cout << "char_4: " << char_4 << endl;
	cout << "char_5: " << char_5 << endl;
	*/


	/*
	cout << "ch_1: " << ch_1 + 1 << endl;
	cout << "ch_1: " << ch_1 + 2 << endl;
	cout << "ch_1: " << ch_1 + 9999 << endl;
	*/

	cin.get();
	return 0;
}