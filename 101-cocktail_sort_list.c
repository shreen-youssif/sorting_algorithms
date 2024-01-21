#include "sort.h"
#include <stdio.h>

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 *
 * @list: The doubly linked list
 * @a: First node to be swapped
 * @b: Second node to be swapped
 */
void swap_nodes(listint_t **list, listint_t *a, listint_t *b)
{
	if (!a || !b)
		return;

	if (a->prev)
		a->prev->next = b;
	if (b->next)
		b->next->prev = a;

	a->next = b->next;
	b->prev = a->prev;

	a->prev = b;
	b->next = a;

	if (*list == a)
		*list = b;

	print_list(*list);
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending
 *                     order using the Cocktail shaker sort algorithm
 *
 * @list: The doubly linked list to be sorted
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *start, *end;
	int swapped = 1;

	if (!list || !(*list) || !((*list)->next))
		return;
	start = *list;
	end = NULL;
	while (swapped)
	{
		swapped = 0;

		/* Forward pass (left to right) */
		while (start->next != end)
		{
			if (start->n > start->next->n)
			{
				swap_nodes(list, start, start->next);
				swapped = 1;
			}
			else
				start = start->next;
		}

		if (!swapped)
			break;

		end = start;

		/* Backward pass (right to left) */
		while (start->prev != NULL)
		{
			if (start->n < start->prev->n)
			{
				swap_nodes(list, start->prev, start);
				swapped = 1;
			}
			else
				start = start->prev;
		}
	}
}
