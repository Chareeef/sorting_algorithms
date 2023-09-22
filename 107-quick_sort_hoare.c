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
 *
 * Return: new pivot's index
 */
size_t hoare_partition(size_t start, size_t end, int *array, size_t size)
{
	size_t i, j;
	int pivot;

	pivot = array[end];
	i = start - 1;
	j = end + 1;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (i >= j)
		{
			return (i);
		}

		if (i != j)
			swap_and_print(i, j, array, size);
	}

	return (-1);
}

/**
 * help_quick_sort_hoare - helper function for quick_sort_hoare
 * @start: starting index of the subarray
 * @end: ending index of the subarray
 * @array: pointer to the array to sort
 * @size: the array's size
 */
void help_quick_sort_hoare(size_t start, size_t end, int *array, size_t size)
{
	size_t idx_pivot;

	if (start < end)
	{
		idx_pivot = hoare_partition(start, end, array, size);

		help_quick_sort_hoare(start, idx_pivot - 1, array, size);
		help_quick_sort_hoare(idx_pivot, end, array, size);
	}
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

	help_quick_sort_hoare(0, size - 1, array, size);
}
