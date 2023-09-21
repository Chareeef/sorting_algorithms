#include "sort.h"

/**
 * selection_sort - implementation of the selection sort algorithm
 * @array: the array to sort
 * @size: the array's size
 */
void selection_sort(int *array, size_t size)
{
	size_t min_index, i, j;
	int temp;

	for (i = 0; i < size; i++)
	{
		min_index = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_index])
				min_index = j;
		}

		if (min_index > i)
		{
			temp = array[i];
			array[i] = array[min_index];
			array[min_index] = temp;

			print_array(array, size);
		}
	}
}
