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

/**
 * struct radix_listint_s - Singly linked list node for radix sort
 *
 * @n: Integer stored in the node
 * @next: Pointer to the next element of the list
 */
typedef struct radix_listint_s
{
	int n;
	struct radix_listint_s *next;
} listint_r;

/* FUNCTIONS : */

/* sorting algorithms */

void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);

/* helper functions */

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void lomuto_partition(size_t start, size_t end, int *array, size_t size);
size_t hoare_partition(size_t start, size_t end, int *array, size_t size);

#endif
