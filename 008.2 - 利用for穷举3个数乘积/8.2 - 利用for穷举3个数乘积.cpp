#include <iostream>
using namespace std;

const int NUM_MAX = 100;

void test01()
{
	for (int a = -100; a < NUM_MAX; a++)
	{
		for (int b = -100; b < NUM_MAX; b++)
		{
			for (int c = -100; c < NUM_MAX; c++)
			{
				if (18 == a * b * c)
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