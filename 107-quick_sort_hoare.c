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
 * hoare_partition - partition a subarray around a pivot (Hoare)
 * @start: starting index of the subarray
 * @end: ending index of the subarray
 * @array: pointer to the array to sort
 * @size: the array's size
 */
void hoare_partition(size_t start, size_t end, int *array, size_t size)
{
	size_t i, j, idx_pivot;
	int pivot;

	pivot = array[end];
	idx_pivot = end;
	i = start;
	j = end - 1;

	while (i < j)
	{
		while (array[i] < pivot)
			i++;
		while (array[j] > pivot && j > 0)
			j--;

		if (i < j)
		{
			swap_and_print(i, j, array, size);
		}
	}

	swap_and_print(i, idx_pivot, array, size);
	idx_pivot = i;

	if (idx_pivot > 1)
		hoare_partition(0, idx_pivot - 1, array, size);
	if (idx_pivot < end - 1)
		hoare_partition(idx_pivot + 1, end, array, size);
}

/**
 * quick_sort_hoare - implementation of the quick sort algorithm (Hoare)
 * @array: pointer to the array to sort
 * @size: the array's size
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size <= 1)
		return;

	hoare_partition(0, size - 1, array, size);
}
