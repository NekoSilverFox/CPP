#include <iostream>
using namespace std;

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