#include <iostream>
#include<cmath>
#define NUM 12
using namespace std;
int main(void) {
	double all_date = 0;
	int i;
	double date[NUM] = { 6.31,
6.40,
6.37,
6.20,
6.19,
5.90,
6.25,
6.34,
6.33,
6.45,
6.37,
6.27 };

	cout << "  NO" << "    t-^t       " << "  (t-^t)^2" << endl;
	cout << "+---------------------------------+" << endl;

	
	for (i = 0; i < 12; i++) {
		all_date += date[i];
	}

	for (i = 0; i < 12; i++) {
		//cout << "| " << i + 1 << " -- " << date[i] - (all_date / 12) << "  --  " << (date[i] - (all_date / 12)) * (date[i] - (all_date / 12)) << "   |" << endl;
		//cout << "+---------------------------------+" << endl;
		cout << date[i] - (all_date / 12) << endl;
	}

	cin.get();
	return 0;
}