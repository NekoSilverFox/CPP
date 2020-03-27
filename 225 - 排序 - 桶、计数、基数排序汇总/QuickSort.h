#pragma once

void QuickSort(int arr[], int start_arr, int end_arr)
{
	int i = start_arr;
	int j = end_arr;

	//base number
	int base = arr[start_arr];

	if (i < j)
	{

		while (i < j)
		{

			// from right to left, find which num is smaller than base
			while (i < j && arr[j] >= base) j--;
			// МоїУ
			if (i < j)
			{
				arr[i] = arr[j];
				i++;
			}

			// from left to right, find which num is bigger than base
			while (i < j && arr[i] < base) i++;
			// МоїУ
			if (i < j)
			{
				arr[j] = arr[i];
				j--;
			}
		}
		// put the number base into arr[i] or arr[j]
		arr[i] = base;

		// Quick Sort for the left part
		QuickSort(arr, start_arr, i - 1);

		// Quick Sort for the right part
		QuickSort(arr, i + 1, end_arr);
	}

}