#include <iostream>
using namespace std;
int main(void) {
	int x = 1, x2 = 0, i = 0;

	while (x != 0)
	{
		cout << "Please take the x in :" << endl; cin >> x;

		if (x > x2) {
			++i;
			x = x2;
		}
	}

	cin.get();
	return 0;
}