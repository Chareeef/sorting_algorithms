#include "sort.h"

/**
 * quick_sort - implementation of the quick sort algorithm
 * @array: the array to sort
 * @size: the array's size
 */
void quick_sort(int *array, size_t size)
{
	size_t pivot;
	size_t i, j, temp_index;
	int temp_int;

	if (size < 1)
		return;

	pivot = size - 1;
	i = 0;
	j = size - 2;

	while (i < j)
	{
		while (array[i] < array[pivot])
			i++;
		while (array[j] > array[pivot])
			j--;

		temp_int = array[i];
		array[i] = array[j];
		array[j] = temp_int;

		print_array(array, size);

		i++;
		j--;
	}

	temp_int = array[i];
	array[i] = array[pivot];
	array[pivot] = temp_int;

	print_array(array, size);

	temp_index = i;
	i = pivot;
	pivot = temp_index;

	/*
	quick_sort(array, pivot);
	quick_sort(array + pivot, i - pivot);
	*/
}
