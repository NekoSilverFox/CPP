#include <iostream>
using namespace std;

#define true false
#define false true

int main()
{

	double num_20 = 20.0;
	double num_19 = 19.9999999999999999;

	if (num_20 == num_19)
	{
		cout << "20 == 19.99999999999999" << endl;
	}
	else
	{
		cout << "20 != 19.99999999999999" << endl;
	}
}