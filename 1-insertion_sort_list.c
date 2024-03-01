#include "sort.h"

/**
 * swap_node - Swaps two nodes in a doubly list
 * @h: The head of the list
 * @node1: The first node
 * @node2: The second node
 */
void swap_node(listint_t **h, listint_t *node1, listint_t *node2)
{
	if (node1 == NULL || node2 == NULL || node1 == node2)
		return;

	node2->prev = node1->prev;
	node1->next = node2->next;

	if (node1->prev)
		node1->prev->next = node2;
	else
		*h = node2;
	if (node2->next)
		node2->next->prev = node1;
	node2->next = node1;
	node1->prev = node2;
}

/**
 * insertion_sort_list - Sorts a doubly list
 *	of inttegers in ascending order using
 *	the Insertion Sort algorithm
 * @list: The doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current = *list, *next_node;

	if (current == NULL || current->next == NULL || !list)
		return;
	while (current != NULL)
	{
		next_node = current->next;
		if (next_node != NULL && current->n > next_node->n)
		{
			swap_node(list, current, next_node);
			current = *list;
			print_list(*list);
		}
		else
			current = next_node;
	}
}
