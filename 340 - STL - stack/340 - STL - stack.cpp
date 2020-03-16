#include<iostream>
#include<stack>
using namespace std;

int main()
{
	stack<char> letter;
	for (int i = 64; i < 90; i++)
	{
		cout << (char)i  << letter.size() << " - ";
		letter.push(i);
	}
	
	cout << endl << endl;

	while (letter.size() != 0)
	{
		cout << letter.top() << letter.size() << " - ";
		letter.pop();
	}
}