#include <iostream>
using namespace std;

char* test01()
{
	char arr[] = "Hello world";

	cout << arr << endl;
	return arr;

	char* arr = {"Hello world"}; // C++ �в�����
}

int main()
{
	// cout << *test01() << endl;
	cout << test01() << endl;
}