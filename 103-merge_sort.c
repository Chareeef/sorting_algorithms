#include "sort.h"

/**
 * merge - Merge two subarrays using Merge sort algorithm
 *
 * @array: Array to be sorte/d
 * @left: left subarray
 * @l_size: size of left subarray
 * @right: left subarray
 * @r_size: size of right subarray
 */
void merge(int *array, int *left, size_t l_size, int *right, size_t r_size)
{
	size_t i, idx_l = 0, idx_r = 0;
	size_t total_size = l_size + r_size;
	int *sorted;

	sorted = malloc(total_size * sizeof(int));
	if (!sorted)
		exit(-1);

	printf("Merging...\n");
	printf("[left]: ");
	print_array(left, l_size);
	printf("[right]: ");
	print_array(right, r_size);

	for (i = 0; idx_l < l_size && idx_r < r_size; i++)
	{
		if (left[idx_l] < right[idx_r])
		{
			sorted[i] = left[idx_l];
			idx_l++;
		}
		else
		{
			sorted[i] = right[idx_r];
			idx_r++;
		}
	}

	for (; idx_l < l_size; idx_l++, i++)
		sorted[i] = left[idx_l];
	for (; idx_r < r_size; idx_r++, i++)
		sorted[i] = right[idx_r];
	for (i = 0; i < total_size; i++)
		array[i] = sorted[i];

	free(sorted);

	printf("[Done]: ");
	print_array(array, total_size);
}

/**
 * merge_sort - Sorts an array using Merge sort algorithm
 *
 * @array: Array to be sorted
 * @size: The size of that array
 */
void merge_sort(int *array, size_t size)
{
	int *left, *right;
	size_t l_size, r_size;
	size_t m;

	if (!array || size < 2)
		return;

	m = size / 2;

	left = array;
	l_size = m;

	right = array + m;
	r_size = size - m;

	merge_sort(left, l_size);
	merge_sort(right, r_size);

	merge(array, left, l_size, right, r_size);
}
