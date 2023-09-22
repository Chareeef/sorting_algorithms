#include "sort.h"

/**
 *
 *
 *
 */

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
