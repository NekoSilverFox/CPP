#include <iostream>
using namespace std;

bool canJump(int arr[], int arr_lengtth)
{
	bool* b_arr = new bool[arr_lengtth];
	b_arr[0] = true;

	for (int j = 1; j < arr_lengtth; j++)
	{
		b_arr[j] = false;

		for (int i = 0; i < j; i++)
		{
			if (b_arr[i] && i + arr[i] >= j)
			{
				b_arr[j] = true;
				break;
			}
		}
	}

	return b_arr[arr_lengtth - 1];
}

int main()
{
	int arr[] = { 2, 3, 1, 1, 4 };
	int arr2[] = { 3, 2, 1, 0, 4 };

	if (canJump(arr2, 5)) cout << "True" << endl;
	else  cout << "False" << endl;

}