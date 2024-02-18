#include "sort.h"

/**
 * swap_nodes - Swap nodes
 * @head: A pointer to the head
 * @node1: the first node
 * @node2: The second node
 */
void swap_nodes(listint_t **head, listint_t **node1, listint_t *node2)
{
	(*node1)->next = node2->next;
	if (node2->next != NULL)
		node2->next->prev = *node1;
	node2->prev = (*node1)->prev;
	node2->next = *node1;
	if ((*node1)->prev != NULL)
		(*node1)->prev->next = node2;
	else
		*head = node2;
	(*node1)->prev = node2;
	*node1 = node2->prev;
}

/**
 * insertion_sort_list - Sorts using the insertion sort algorithm
 * @ls: the head of a doubly-linked list
 */
void insertion_sort_list(listint_t **ls)
{
	listint_t *loops, *insert, *tmp;

	if (ls == NULL || *ls == NULL || (*ls)->next == NULL)
		return;

	for (loops = (*ls)->next; loops != NULL; loops = tmp)
	{
		tmp = loops->next;
		insert = loops->prev;
		while (insert != NULL && loops->n < insert->n)
		{
			swap_nodes(ls, &insert, loops);
			print_list((const listint_t *)*ls);
		}
	}
}
