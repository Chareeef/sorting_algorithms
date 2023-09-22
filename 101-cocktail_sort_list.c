#include "sort.h"

/**
 * cocktail_sort_list - Cocktail shaker sort algorithm
 * @tmp: node to be swapped
 * @tmp1: to be swapped with
 * @list: a double pointer to the head of a doubly linked list
 */

void swap_them(listint_t *tmp, listint_t *tmp1, listint_t **list);

void cocktail_sort_list(listint_t **list)
{
	listint_t *curr = *list, *tmp, *tmp1, *tail;
	int swap, len = 0;

	while (curr != NULL)
	{
		curr = curr->next;
		len++;
	}
	tail = curr;

	curr = (*list)->next;
	while (len > 0)
	{
		swap = 0;
		while (curr && curr->prev)
		{
			if (curr->n < curr->prev->n)
			{
				tmp = curr;
				tmp1 = curr->prev;

				swap_them(tmp, tmp1, list);

				print_list(*list);
				swap += 1;
			}
			curr = curr->next;
		}
		while (tail != NULL)
		{
			if (tail->n < tail->prev->n)
			{
				tmp = tail;
				tmp1 = tail->prev;

				swap_them(tmp, tmp1, list);

				print_list(*list);
				swap += 1;
			}
			tail = tail->prev;
		}
		curr = (*list)->next;
		if (swap == 0)
			break;
		len--;
	}
}

/**
 * swap_them - swaps two nodes
 * @tmp: first node to swap
 * @tmp1: second node to swap
 * @list: a double pointer to the list we are sorting
 */

void swap_them(listint_t *tmp, listint_t *tmp1, listint_t **list)
{
	if (tmp1 == *list)
		*list = tmp;

	if (tmp1->prev)
		tmp1->prev->next = tmp;
	if (tmp->next)
		tmp->next->prev = tmp1;

	tmp1->next = tmp->next;
	tmp->prev = tmp1->prev;

	tmp1->prev = tmp;
	tmp->next = tmp1;
}
