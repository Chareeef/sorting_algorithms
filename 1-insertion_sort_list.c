#include "sort.h"

/**
 *
 *
 *
 *
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *tmp, *temp, *new_node, *head, *tail, *curr = *list, *sorted_list = NULL;

	if (curr == NULL || curr->next == NULL)
		return;

	while (curr && curr->next)
	{
		if (curr->n > curr->next->n)
		{
			tmp = curr;
			curr = curr->next;
			curr->next = tmp;

			if (sorted_list == NULL)
			{
				/* sorted_list = malloc(sizeof(listint_t)); */
				sorted_list = curr;
				sorted_list->prev = NULL;
				sorted_list->next = NULL;
			}
			else
			{
				/* new_node = malloc(sizeof(listint_t)); */
				new_node = curr;
				new_node->next = NULL;
				new_node->prev = NULL;

				head = sorted_list;

				while (head)
				{
					head = head->next;
				}
				new_node->prev = head;
				head->next = new_node;
				tail = new_node;

				while (tail)
				{
					if (tail->n < tail->prev->n)
					{
						temp = tail;
						tail = tail->prev;
						tail->prev = temp;
					}
					tail = tail->prev;
				}
			}
			print_list(*list);
		}
		curr = curr->next;
	}
}
