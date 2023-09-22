#include "sort.h"

/**
 * swap_and_print - swap and print the array
 * @i: first index to be swapped
 * @j: second index to be swapped
 * @array: pointer to the array to sort
 * @size: the array's size
 */
void swap_and_print(size_t i, size_t j, int *array, size_t size)
{
	int temp;

	temp = array[i];
	array[i] = array[j];
	array[j] = temp;

	if (i != j)
		print_array(array, size);
}

/**
 * lomuto_partition - partition a subarray around a pivot (Lomuto)
 * @start: starting index of the subarray
 * @end: ending index of the subarray
 * @array: pointer to the array to sort
 * @size: the array's size
 */
void lomuto_partition(size_t start, size_t end, int *array, size_t size)
{
	size_t pivot, i, j;

	if (!array || start >= end || end <= 0)
		return;

	pivot = end;
	i = start - 1;

	for (j = start; j < end; j++)
	{
		if (array[j] <= array[pivot])
		{
			i++;
			swap_and_print(i, j, array, size);
		}
	}

	i++;
	swap_and_print(i, pivot, array, size);

	pivot = i;
	if (pivot > start + 1)
		lomuto_partition(start, pivot - 1, array, size);
	if (pivot < end - 1)
		lomuto_partition(pivot + 1, end, array, size);
}

/**
 * quick_sort - implementation of the quick sort algorithm (Lomuto)
 * @array: pointer to the array to sort
 * @size: the array's size
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;

	lomuto_partition(0, size - 1, array, size);
}
