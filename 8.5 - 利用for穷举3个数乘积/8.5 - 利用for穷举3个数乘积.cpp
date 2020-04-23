#include <iostream>
using namespace std;

const int NUM = 18;

void test01()
{
	for (int a = 1; a < NUM; a++)
	{
		for (int b = 1; b < NUM; b++)
		{
			for (int c = 1; c < NUM; c++)
			{
				if (NUM == a * b * c)
				{
					if (c + 3 * a == a * c)
					{
						cout << "a = " << a
							<< "  b = " << b
							<< "  c = " << c
							<< endl;
					}
				}
			}
		}
	}
}

int main()
{
	test01();
}