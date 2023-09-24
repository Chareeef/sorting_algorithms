#include "sort.h"

/**
 * merge - Merge two subarrays using Merge sort algorithm
 *
 * @array: Array to be sorted
 * @l: left most index
 * @m: middle index
 * @r: roght most index
 */
void merge(int *array, int l, int m, int r)
{
	int i, idx_sorted, idx_l, idx_r;
	int l_size = m - l, r_size = r - m + 1, s_size = r - l + 1;
	int *sorted_part;

	sorted_part = malloc(s_size * sizeof(int));
	if (!sorted_part)
		exit(-1);

	for (idx_sorted = 0; idx_sorted < s_size; idx_sorted++)
		sorted_part[idx_sorted] = 0;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + l, l_size);
	printf("[right]: ");
	print_array(array + m, r_size);

	for (idx_sorted = 0, idx_l = l, idx_r = m;
			idx_l < m && idx_r <= r; idx_sorted++)
	{
		if (array[idx_l] < array[idx_r])
		{
			sorted_part[idx_sorted] = array[idx_l];
			idx_l++;
		}
		else
		{
			sorted_part[idx_sorted] = array[idx_r];
			idx_r++;
		}
	}
	for (; idx_l < m; idx_sorted++, idx_l++)
		sorted_part[idx_sorted] = array[idx_l];
	for (; idx_r <= r; idx_sorted++, idx_r++)
		sorted_part[idx_sorted] = array[idx_r];

	for (i = l, idx_sorted = 0; idx_sorted < s_size; i++, idx_sorted++)
		array[i] = sorted_part[idx_sorted];
	printf("[Done]: ");
	print_array(sorted_part, s_size);
	free(sorted_part);
}

/**
 * split_and_merge - Split then merge using Merge sort algorithm
 * @array: Array to be sorted
 * @l: left most index
 * @r: right most index
 */
void split_and_merge(int *array, int l, int r)
{
	int m;

	if (!array || l >= r)
		return;
	
	m = l + (r - l) / 2;

	if (m % 2 != 0)
		m++;
	if (r - l == 1)
		m = r;
	split_and_merge(array, l, m - 1);
	split_and_merge(array, m, r);

	merge(array, l, m, r);

}

/**
 * merge_sort - Sorts an array using Merge sort algorithm
 *
 * @array: Array to be sorted
 * @size: The size of that array
 */
void merge_sort(int *array, size_t size)
{
	if (!array || size <= 1)
		return;

	split_and_merge(array, 0, size - 1);
}
