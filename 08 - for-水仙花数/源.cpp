#include <iostream>
using namespace std;
int main(){
	int index = 100, a, b, c; // a百    b十    c个
	
	for (index; index <= 999; index++) {

		// 注意 a，b，c，的定义要放在for 循环中， 不然 a，b，c，将无法被重新定义！！！！
		a = index / 100;
		b = index / 10 % 10;
		c = index % 10;

		if (a*a + b*b + c*c == index)
		{
			cout << "水仙花数为：" << index << endl;
		}

	}

	cin.get();
	return 0;

	}