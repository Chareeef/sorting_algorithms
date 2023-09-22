#include "sort.h"

/**
 *
 *
 *
 */

void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i,j;
	int tmp = 0;

    while (gap < size / 3) {
        gap = gap * 3 + 1;
    }

    while (gap > 0)
	{
        for (i = gap; i < size; i++)
		{
            tmp = array[i];
            j = i;

            while (j >= gap && array[j - gap] > tmp)
			{
                array[j] = array[j - gap];
                j -= gap;
            }

            array[j] = tmp;
        }
        gap /= 3;
		print_array(array, size);
    }
}
