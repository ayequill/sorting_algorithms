#include "sort.h"

/**
 * swap_nodes - Swap two nodes in a doubly linked list.
 * @node_a: Pointer to listint_t node.
 * @node_b: Pointer to listint_t node.
 */
void swap_nodes(listint_t **node_a, listint_t **node_b)
{
	listint_t *next, *prev;

	next = (*node_b)->next;
	prev = (*node_a)->prev;
	(*node_b)->next = *node_a;
	(*node_b)->prev = prev;
	if (prev)
		prev->next = *node_b;

	(*node_a)->next = next;
	if (next)
		next->prev = *node_a;
	(*node_a)->prev = *node_b;
}

/**
 * insertion_sort_list - Sort a doubly linked list using
 * insertion sort algorithm.
 * @list: Pointer to the head of the linked list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *first, *second, *tmp;

	if (list == NULL || *list == NULL)
		return;

	curr = *list;
	while (curr)
	{
		first = curr;
		second = curr->next;
	if (first && second && first->n > second->n)
	{
		swap_nodes(&first, &second);
		if (second && second->prev == NULL)
			*list = second;
		print_list(*list);
		while (second && second->prev && second->n < second->prev->n)
		{
			tmp = second->prev;
			swap_nodes(&tmp, &second);
			if (second->prev == NULL)
				*list = second;
			print_list(*list);
		}
	}
	else
		curr = curr->next;
	}
}
