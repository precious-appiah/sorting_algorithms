#include "sort.h"

/**
 * selection_sort- function to sort integers
 * in ascending order using selection sort
 * @array: array to be sorted
 * @size: size of array
 */
void selection_sort(int *array, size_t size)
{
	int i, j, min, temp;

	for (i = 0; i < n - 1; i++)
	{
		j = i + 1;
		min = i;

		while (j < n)
		{
			if (array[min] > array[j])
				min = j;
			j++;
		}
		temp = arr[i];
		arr[i] = arr[min];
		arr[min] = arr[temp];
		print_array(array, size);
	}
}
