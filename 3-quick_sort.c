#include "sort.h"

/**
 * quick_sort - implementation of the quick sort algorithm
 * @array: the array to sort
 * @size: the array's size
 */

void partition(int low, int high, int *array, size_t size);

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;

	partition(0, size - 1, array, size);
}

void partition(int low, int high, int *array, size_t size)
{
	size_t pivot = high, i = low, j = high - 1, tmp = 0;

	while (i < j)
	{
		while (array[i] < array[pivot])
			i++;
		while (array[j] > array[pivot])
			j--;

		if (i < j)
		{
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;

			print_array(array, size);

			i++;
			j--;
		}
	}

	tmp = array[i];
	array[i] = array[pivot];
	array[pivot] = tmp;
	print_array(array, size);

	partition(0, i - 1, array, size);
	partition(i + 1, size - 1, array, size);
}
