#include <iostream>
using namespace std;
int main() {

	int i = 2144967290;
	float f = 2144967290;
	float i_f = (float)i;
	for (i_f, i, f; f == i_f; i++, f++) {
		cout << "Now testing " << i << endl;
	}

	cout << "!!!!!!!!!!ERROR!!!!!!!!!!" << endl;
	cout << "i_f=" << i << endl;
	cout << "f=" << f << endl;

	cin.get();
	return 0;

}