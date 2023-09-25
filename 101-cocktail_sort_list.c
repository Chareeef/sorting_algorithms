#include "sort.h"

/**
 * swap_and_print - swaps two nodes
 * @old_prev: previous node to be next
 * @old_next: next node to be first
 * @list: a double pointer to the list we are sorting
 */
void swap_and_print(listint_t *old_prev, listint_t *old_next,
		listint_t **list)
{
	if (old_prev == *list)
		*list = old_next;

	if (old_prev->prev)
		old_prev->prev->next = old_next;
	if (old_next->next)
		old_next->next->prev = old_prev;

	old_prev->next = old_next->next;
	old_next->prev = old_prev->prev;

	old_prev->prev = old_next;
	old_next->next = old_prev;

	print_list(*list);
}
/**
 * cocktail_sort_list - Cocktail shaker sort algorithm
 * @list: a double pointer to the head of a doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *curr, *tail = NULL, *head = NULL;
	int swap;

	if (!list || !(*list) || !((*list)->next))
		return;

	curr = *list;
	swap = 1;
	while  (swap)
	{
		for (swap = 0; curr && curr->next && curr->next != tail;)
		{
			if (curr->n > curr->next->n)
			{
				swap_and_print(curr, curr->next, list);
				swap = 1;
			}
			else
				curr = curr->next;
		}
		if (!swap)
			return;

		tail = curr;
		curr = curr->prev;

		for (swap = 0; curr && curr->prev != head;)
		{
			if (curr->prev->n > curr->n)
			{
				swap_and_print(curr->prev, curr, list);
				swap = 1;
			}
			else
				curr = curr->prev;
		}

		head = curr;
		curr = curr->next;
	}
}
