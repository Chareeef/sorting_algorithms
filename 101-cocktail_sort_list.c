#include "sort.h"

/**
 * cocktail_sort_list - Cocktail shaker sort algorithm
 * @list: a double pointer to the head of a doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *curr, *head, *tail, *next_node, *prev_node;
	int swap;

	if (!list || !(*list) || !((*list)->next))
		return;
	head = *list;
	while (1)
	{
		curr = head;
		swap = 0;
		while (curr && curr->next)
		{
			next_node = curr->next;
			if (curr->n > curr->next->n)
			{
				swap_them_and_print(curr->next, curr, &head, list);
				swap = 1;
			}
			curr = next_node;
		}
		tail = curr->prev;
		if (!swap)
			return;
		curr = tail;
		swap = 0;
		while (curr && curr->prev)
		{
			prev_node = curr->prev;
			if (curr->prev->n > curr->n)
			{
				swap_them_and_print(curr, curr->prev, &head, list);
				swap = 1;
			}
			curr = prev_node;
		}
		if (!swap)
			return;
		head = head->next;
		tail = tail->prev;
	}
}

/**
 * swap_them_and_print - swaps two nodes
 * @to_be_before: node to be swapped
 * @to_be_next: to be swapped with
 * @head: head of the list
 * @list: a double pointer to the list we are sorting
 */
void swap_them_and_print(listint_t *to_be_before, listint_t *to_be_next,
		listint_t **head, listint_t **list)
{
	if (to_be_before == *list)
		*list = to_be_next;
	else if (to_be_next == *list)
		*list = to_be_before;


	if (to_be_next->prev)
		to_be_next->prev->next = to_be_before;
	if (to_be_before->next)
		to_be_before->next->prev = to_be_next;

	to_be_next->next = to_be_before->next;
	to_be_before->prev = to_be_next->prev;

	to_be_next->prev = to_be_before;
	to_be_before->next = to_be_next;
	print_list(*list);

	if (*head == to_be_next)
		*head = to_be_before;
	if (*head == to_be_before)
		*head = to_be_next;
}
