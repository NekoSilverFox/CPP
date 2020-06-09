# include <iostream>
using namespace std;

void printArr(int arr[], int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void mySwap(int arr[], int left_index, int right_index)
{
	int temp = arr[left_index];

	arr[left_index] = arr[right_index];
	arr[right_index] = temp;
}

/*
	@param arr 待调整的数组
	@param index 待调整的结点的下标
	@param length 数组的长度
*/
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

	if (index != i_max)
	{
		mySwap(arr, index, i_max);
		heapAdjust(arr, i_max, length); // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	}
}

void heapSort(int arr[], int length)
{
	// 初始化堆
	for (int i = length / 2 - 1; i >= 0; i--)
	{
		heapAdjust(arr, i, length);
	}

	//交换堆顶元素和最后一个元素
	for (int i = length - 1; i >= 0; i--)
	{
		mySwap(arr, 0, i);
		heapAdjust(arr, 0, i);
	}
}

int main()
{
	int arr[9] = { 4, 2, 8, 0, 5, 7, 1, 3, 9 };
	int length = sizeof(arr) / sizeof(arr[0]);

	printArr(arr, length);

	heapSort(arr, length);

	printArr(arr, length);
}