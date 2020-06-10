#include <iostream>
using namespace std;

void printArray(int arr[], const int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << arr[i] << " ";
	}

	cout << endl;
}

void indexSwap(int arr[], int left, int right)
{
	int temp = arr[left];
	arr[left] = arr[right];
	arr[right] = temp;
}

void heapAdjust(int arr[], int index, int length)
{
	int i_max = index;
	int i_lchild = index * 2 + 1;
	int i_rchild = i_lchild + 1;

	if ((i_lchild < length) && (arr[i_lchild] < arr[i_max]))
	{
		i_max = i_lchild;
	}

	if ((i_rchild < length) && (arr[i_rchild] < arr[i_max]))
	{
		i_max = i_rchild;
	}

	if (i_max != index)
	{
		indexSwap(arr, index, i_max);
		heapAdjust(arr, i_max, length);
	}
}

void heapSort(int arr[], int length)
{
	// ³õÊ¼»¯¶Ñ£º
	for (int i = length / 2 - 1; i >= 0; i--)
	{
		heapAdjust(arr, i, length);
	}

	// ¶ÑÅÅÐò
	for (int i = length - 1; i >= 0; i--)
	{
		indexSwap(arr, 0, i);
		heapAdjust(arr, 0, i);
	}
}

int main()
{
	int arr[9] = { 7,4,7,2,5,1,8,0,6 };
	const int length = sizeof(arr) / sizeof(arr[0]);

	printArray(arr, length);

	heapSort(arr, length);

	printArray(arr, length);
}