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

	print_array(array, size);
}

/**
 * partition - partition a subarray around a pivot
 * @start: starting index of the subarray
 * @end: ending index of the subarray
 * @array: pointer to the array to sort
 * @size: the array's size
 */
void partition(size_t start, size_t end, int *array, size_t size)
{
	size_t pivot, i, j;

	if (!array || start >= end || end <= 0)
		return;

	pivot = end;
	i = start;
	j = end - 1;

	while (i < j)
	{
		while (array[i] < array[pivot] && i < size)
			i++;
		while (array[j] > array[pivot] && j > 0)
			j--;

		if (i < j)
		{
			swap_and_print(i, j, array, size);
			i++;
			j--;
		}
	}

	if (array[i] > array[pivot])
	{
		swap_and_print(i, pivot, array, size);
	}

	pivot = i;
	if (pivot > start + 1)
		partition(start, pivot - 1, array, size);
	if (pivot < end - 1)
		partition(pivot + 1, end, array, size);
}

/**
 * quick_sort - implementation of the quick sort algorithm
 * @array: pointer to the array to sort
 * @size: the array's size
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;

	partition(0, size - 1, array, size);
}
