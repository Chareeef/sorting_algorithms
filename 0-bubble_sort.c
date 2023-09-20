#include "sort.h"

/**
 * bubble_sort - implementation of the bubble sort algorithm
 * @array: the array to sort
 * @size: the array's size
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;
	int swapped; /* track if there was a swap */

	for (i = 0; i < size; i++)
	{
		swapped = 0;

		for (j = 0; j < size - 1; j++)
		{
			if (array[j] < array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swapped = 1;
			}

			print_array(array, size);

			if (!swapped && j == size - 2)
			{
				return;
			}
		}
	}
}
