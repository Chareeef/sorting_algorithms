#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int array[] = {8, 5, 2, 4, 7, 1, 9, 3, 6};
	size_t n = sizeof(array) / sizeof(array[0]);

	print_array(array, n);
	printf("\n");
	selection_sort(array, n);
	printf("\n");
	print_array(array, n);
	return (0);
}
