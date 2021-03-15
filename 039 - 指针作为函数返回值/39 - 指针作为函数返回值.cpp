#include <iostream>
using namespace std;

char* test01()
{
	char arr[] = "Hello world";

	cout << arr << endl;
	return arr;

	char* arr = {"Hello world"}; // C++ 中不可以
}

int main()
{
	// cout << *test01() << endl;
	cout << test01() << endl;
}