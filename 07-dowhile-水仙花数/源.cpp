#include <iostream>
using namespace std;
int main() {

	int index = 100 , a, b, c; // a-百位 b-十位 c-个位
	
	do
	{
		a = index / 100;
		b = index / 10 % 10;
		c = index % 10;

		if (a*a*a + b*b*b + c*c*c == index) {
			cout << "水仙花数为：" << index << endl;
			}

		index++;
	} while (index < 1000);

	cin.get();
	return 0;
}