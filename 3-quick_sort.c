#include "sort.h"

/**
 * arr_partition - function to partition array
 * @array: array to be partitioned
 * @low_idx: index of first element
 * @high_idx: index of last element
 * @len: len of original array
 * Return: int
 */
int arr_partition(int *array, int low_idx, int high_idx, int len)
{
	int i, j, temp, pivot;

	pivot = array[high_idx];
	j = low_idx - 1;

	for (i = low_idx; i < high_idx; i++)
	{
		if (array[i] < pivot)
		{
			j += 1;
			temp = array[j];
			array[j] = array[i];
			array[i] = temp;
		}
	}

	temp = array[j + 1];
	array[j + 1] = array[high_idx];
	array[high_idx] = temp;
	print_array(array, len);

	return (j + 1);
}

/**
 * quick_sort_recursive - function to recursively sort
 * @arr: array to be sorted
 * @low_idx: least index
 * @high_idx: highest index
 * @len: len of original array
 */
void quick_sort_recursive(int *arr, int low_idx, int high_idx, int len)
{
	int result;

	if (low_idx < high_idx)
	{
		result = arr_partition(arr, low_idx, high_idx, len);
		quick_sort_recursive(arr, low_idx, result - 1, len);
		quick_sort_recursive(arr, result + 1, high_idx, len);
	}
}


/**
 * quick_sort - function to quick sort
 * @array: array to be sorted
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	quick_sort_recursive(array, 0, size - 1, size);
}
