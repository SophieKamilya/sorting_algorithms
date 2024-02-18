#include <stdio.h>
#include "sort.h"

/**
 * print_list - Prints a list
 * @ls: The list to be printed
 */
void print_list(const listint_t *ls)
{
	int i;

	i = 0;
	while (ls)
	{
		if (i > 0)
			printf(", ");
		printf("%d", ls->n);
		++i;
		ls = ls->next;
	}
	printf("\n");
}
