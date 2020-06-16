#include <iostream>
using namespace std;

#define DEBUG 3

int main()
{
#if 0
	cout << "if 0" << endl;

#elif DEBUG == 1
	cout << "DEBUG 1" << endl;

#elif DEBUG == 2
	cout << "DEBUG 2" << endl;

#else
	cout << "ELSE" << endl;

#endif
}