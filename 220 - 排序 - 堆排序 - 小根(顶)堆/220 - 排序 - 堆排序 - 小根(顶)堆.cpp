#include <iostream>
using namespace std;


/*
** ��֪arr[] �м�¼�Ĺؼ��ֳ�arr[s]֮�������ѵĶ��壬����������arr[s]�Ĺؼ��֣�ʹR[s...m]��Ϊһ��С����
*/
void HeapAdjust(int arr[], int s, int m)
{
	int rc = arr[s];

	for (int i = 2 * s; i <= m; i *= 2) // ��key��С�ĺ��ӽڵ�����ɸѡ
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