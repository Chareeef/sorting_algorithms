#ifndef HASH_TABLES_H
#define HASH_TABLES_H

/* INCLUDES : */

#include <stdlib.h>
#include <stdio.h>


/* STRUCTURES : */

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* FUNCTIONS : */

/* sorting algorithms */

void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);
void help_quick_sort_hoare(size_t start, size_t end, int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);

/* helper functions */

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void swap_and_print(size_t i, size_t j, int *array, size_t size);
void swap_them_and_print(listint_t *to_be_before, listint_t *to_be_next,
		listint_t **head, listint_t **list);
void lomuto_partition(size_t start, size_t end, int *array, size_t size);
size_t hoare_partition(size_t start, size_t end, int *array, size_t size);

#endif
