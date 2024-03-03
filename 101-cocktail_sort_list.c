#include "sort.h"

/**
 * swap_right - Swaps a node with the one to its right
 * @cursor: The node to be swapped
 * @head: The head of the doubly linked list
 */
void swap_right(listint_t *cursor, listint_t **head)
{
	listint_t *next;

	next = cursor->next;
	if (cursor->prev)
		cursor->prev->next = next;
	next->prev = cursor->prev;
	if (next->next)
		next->next->prev = cursor;
	cursor->next = next->next;
	next->next = cursor;
	cursor->prev = next;

	if (cursor == *head)
		*head = next;
}

/**
 * swap_left - Swaps a node with the one to its left
 * @cursor: The node to be swapped
 * @head: The head of the doubly linked list
 */
void swap_left(listint_t *cursor, listint_t **head)
{
	swap_right(cursor->prev, head);
}

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

	if (node2->prev)
		node2->prev = node1->prev;
	else
		*h = node1;
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
 * cocktail_sort_list - sorts a doubly list of
 *	integers in ascending order using
 *	the Cocktail Shaker Sort algorithm
 * @list: The head of the list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *current;
	int swapped = 1;

	if (list == NULL || (*list)->next == NULL || *list == NULL)
		return;

	current = *list;
	while (swapped)
	{
		swapped = 0;
		while (current->next != NULL)
		{
			if (current->n > current->next->n)
			{
				swap_right(current, list);
				print_list(*list);
				swapped = 1;
			}
			else
				current = current->next;
		}
		while (current->prev != NULL)
		{
			if (current->n < current->prev->n)
			{
				swap_left(current, list);
				print_list(*list);
				swapped = 1;
			}
			else
				current = current->prev;
		}
	}
}
