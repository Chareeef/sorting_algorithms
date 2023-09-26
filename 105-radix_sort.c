#include "sort.h"

/**
 * free_ints - free integers array
 * @integers: integers array
 * @size: size of integers
 */
void free_ints(listint_r **integers, size_t size)
{
	listint_r *current, *temp;
	size_t i;

	for (i = 0; i < size; i++)
	{
		current = integers[i];

		while (current)
		{
			temp = current->next;
			free(current);
			current = temp;
		}
	}

	free(*integers);
}

/**
 * add_node_end - Add a node at the end of a listint
 * @head: pointer to pointer to the SLL's head
 * @num: integer to be stored in the new node
 *
 * Return: adress of the new node, NULL if it failed.
 */
listint_r *add_node_end(listint_r **head, int num)
{
	listint_r *current;
	listint_r *new;

	if (!head)
		return (NULL);

	new = malloc(sizeof(listint_r));
	if (!new)
		return (NULL);
	new->n = num;
	new->next = NULL;

	if (!(*head))
	{
		*head = new;
		return (new);
	}

	current = *head;
	while (current->next)
		current = current->next;
	current->next = new;

	return (new);
}

/**
 * radix_sort - implementation of the radix sort algorithm
 * @array: the array to sort
 * @size: the array's size
 */
void radix_sort(int *array, size_t size)
{
	listint_r **integers, *current;
	size_t i, j, lsd;
	int end, div;

	for (end = 0, div = 10; !end; div *= 10)
	{
		integers = malloc(10 * sizeof(listint_r *));
		if (!integers)
			exit(-1);
		for (i = 0; i < 10; i++)
			integers[i] = NULL;

		for (end = 1, i = 0; i < size; i++)
		{
			lsd = (array[i] / (div / 10)) % 10;
			if (array[i] / div)
				end = 0;
			add_node_end(&integers[lsd], array[i]);
		}

		j = 0;
		for (i = 0, current = integers[j]; i < size;)
		{
			while (!current)
			{
				j++;
				current = integers[j];
			}
			for (; current != NULL; current = current->next, i++)
				array[i] = current->n;
		}

		free_ints(integers, 10);
		print_array(array, size);
	}
}
