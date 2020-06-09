#include <iostream>
using namespace std;


/*
** 已知arr[] 中记录的关键字除arr[s]之外均满足堆的定义，本函数调整arr[s]的关键字，使R[s...m]成为一个小根堆
*/
void HeapAdjust(int arr[], int s, int m)
{
	int rc = arr[s];

	for (int i = 2 * s; i <= m; i *= 2) // 沿key较小的孩子节点向下筛选
	{
		if ((i < m) && arr[i] > arr[i + 1]) i++;

	}
}


#if 0
void heapAdjust(int arr[], int arr_length)
{
	int* arr_heap = new int[arr_length + 1];

	arr_heap[0] = 0;

	for (int i = 1; i < arr_length + 1; i++)
	{
		arr_heap[i] = arr[i - 1];
	}


}
#endif

int main()
{

}