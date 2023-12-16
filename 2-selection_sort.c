#include "sort.h"

/**
 * selection_sort- function to sort integers
 * in ascending order using selection sort
 * @array: array to be sorted
 * @size: size of array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min;
	int temp;

	for (i = 0; i < size - 1; i++)
	{
		j = i + 1;
		min = i;

		while (j < size)
		{
			if (array[min] > array[j])
				min = j;
			j++;
		}
		temp = array[i];
		array[i] = array[min];
		array[min] = temp;
		print_array(array, size);
	}
}
