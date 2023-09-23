#include "sort.h"

/**
 * counting_sort - sorting algo
 *
 * @array: array to sort
 * @size: array's size
 */

void counting_sort(int *array, size_t size)
{
	size_t i;
	int max = array[0];
	int *aux;
	int *sortedArray = malloc(sizeof(int) * size);

	if (sortedArray == NULL)
		return;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	aux = malloc(sizeof(int) * max + 1);

	for (i = 0; i <= (size_t) max; i++)
		aux[i] = 0;

	for (i = 0; i < size; i++)
		aux[array[i]]++;

	for (i = 1; i <= (size_t) max; i++)
		aux[i] += aux[i - 1];

	print_array(aux, max);

	for (i = 0; i < size; i++)
	{
		aux[array[i]]--;
		sortedArray[aux[array[i]]] = array[i];
	}
	for (i = 0; i < size; i++)
		array[i] = sortedArray[i];

	free(aux);
	free(sortedArray);
}
