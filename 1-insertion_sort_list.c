#include "sort.h"

/**
 * insertion_sort_list - implementation of the insertion sort algorithm
 * @list: the doubly linked list to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *to_be_next, *to_be_first;
	listint_t *current, *compared, *next_node;

	if (!list || !(*list) || !((*list)->next))
		return;

	current = (*list)->next;

	while (current)
	{
		compared = current;
		next_node = current->next;

		while (compared->prev && compared->n < compared->prev->n)
		{
			to_be_first = compared;
			to_be_next = compared->prev;

			if (to_be_next == *list)
				*list = to_be_first;

			if (to_be_next->prev)
				to_be_next->prev->next = to_be_first;
			if (to_be_first->next)
				to_be_first->next->prev = to_be_next;

			to_be_next->next = to_be_first->next;
			to_be_first->prev = to_be_next->prev;

			to_be_next->prev = to_be_first;
			to_be_first->next = to_be_next;

			print_list(*list);
		}

		current = next_node;
	}
}
