#define SUM(x, y) x + y


#include <iostream>
using namespace std;

int main()
{
	int y = 10;

	cout << SUM(++y, y++) << endl;
	cout << y << endl;
}