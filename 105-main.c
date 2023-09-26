#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int array[] = {19, 48, 99, 71, 13, 50, 96, 73, 86, 7};
	size_t n = sizeof(array) / sizeof(array[0]);
	int array2[] = {87, 65, 28, 63, 93, 255, 39, 59, 27, 35, 24, 83, 69, 62,
		13, 6, 88, 58, 92, 26, 42, 11, 16, 21, 75, 36, 71, 8, 45, 38};
	size_t n2 = sizeof(array2) / sizeof(array2[0]);
	int array3[] = {9, 8, 16, 7, 16, 6, 6, 5};
	size_t n3 = sizeof(array3) / sizeof(array3[0]);

	print_array(array, n);
	printf("\n");
	radix_sort(array, n);
	printf("\n");
	print_array(array, n);

	printf("\n\t[------------[\n");

	print_array(array2, n2);
	printf("\n");
	radix_sort(array2, n2);
	printf("\n");
	print_array(array2, n2);

	printf("\n\t[------------[\n");

	print_array(array3, n3);
	printf("\n");
	radix_sort(array3, n3);
	printf("\n");
	print_array(array3, n3);

	return (0);
}
