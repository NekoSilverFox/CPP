// 204 - 排序 - 插入排序
#include<iostream>
#include<time.h>
#include<sys/timeb.h>
using namespace std;

const int MAX = 250000;

void ShellSort(int arr[], int length)
{
	int i, j, k;
	int increasement = length;

	do
	{
		//确定分组的增量
		increasement = increasement / 3 + 1;

		for (i = 0; i < increasement; i++)
		{

			for (j = i + increasement; j < length; j += increasement)
			{

				if (arr[j] < arr[j - increasement])
				{
					int temp = arr[j];
					for (k = j - increasement; k >= 0 && temp < arr[k]; k -= increasement) arr[k + increasement] = arr[k];
					arr[k + increasement] = temp;
				}

			}

		}

	} while (increasement > 1);


	cout << endl << "================================================================" << endl << endl;
}


// function for print the array
void printArray(int arr[], int length)
{
	for (int i = 0; i < length; i++)
		cout << arr[i] << " ";
	cout << endl << "================================================================" << endl << endl;
}

// count the time 
long getSystemTime() {
	timeb tb;
	ftime(&tb);
	return tb.time * 1000 + tb.millitm;
}

int main()
{
	int arr[MAX];

	// 获取随机数种子
	srand((unsigned int)time(NULL));

	// Init
	for (int i = 0; i < MAX; i++)
	{
		arr[i] = rand() % MAX;
	}

	cout << __TIME__ << endl;
	//printArray(arr, MAX);
	double t_start = getSystemTime();
	ShellSort(arr, MAX);
	double t_end = getSystemTime();
	//printArray(arr, MAX);

	cout << endl << "Use time : " << (t_end - t_start) / 1000;

}