#include "sort.h"

void swap_node_ahead(listint_t **ls, listint_t **tl, listint_t **shk);
void swap_node_behind(listint_t **ls, listint_t **tl, listint_t **shk);
void cocktail_sort_list(listint_t **ls);

/**
 * swap_node_ahead - Swap a nodes function
 * @ls: head
 * @tl: tail
 * @shk: the cocktail shaker
 */
void swap_node_ahead(listint_t **ls, listint_t **tl, listint_t **shk)
{
	listint_t *tmp = (*shk)->next;

	if ((*shk)->prev != NULL)
		(*shk)->prev->next = tmp;
	else
		*ls = tmp;
	tmp->prev = (*shk)->prev;
	(*shk)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *shk;
	else
		*tl = *shk;
	(*shk)->prev = tmp;
	tmp->next = *shk;
	*shk = tmp;
}

/**
 * swap_node_behind - Swap a node in a list
 * @ls: head
 * @tl: tail
 * @shk: the cocktail shaker algo.
 */
void swap_node_behind(listint_t **ls, listint_t **tl, listint_t **shk)
{
	listint_t *tmp = (*shk)->prev;

	if ((*shk)->next != NULL)
		(*shk)->next->prev = tmp;
	else
		*tl = tmp;
	tmp->next = (*shk)->next;
	(*shk)->prev = tmp->prev;
	if (tmp->prev != NULL)
		tmp->prev->next = *shk;
	else
		*ls = *shk;
	(*shk)->next = tmp;
	tmp->prev = *shk;
	*shk = tmp;
}

/**
 * cocktail_sort_list - Sort a list using the cocktail shaker algorithm
 * @ls: head
 */
void cocktail_sort_list(listint_t **ls)
{
	listint_t *tl, *shk;
	bool shaken_not_stirred = false;

	if (ls == NULL || *ls == NULL || (*ls)->next == NULL)
		return;

	for (tl = *ls; tl->next != NULL;)
		tl = tl->next;

	while (shaken_not_stirred == false)
	{
		shaken_not_stirred = true;
		for (shk = *ls; shk != tl; shk = shk->next)
		{
			if (shk->n > shk->next->n)
			{
				swap_node_ahead(ls, &tl, &shk);
				print_list((const listint_t *)*ls);
				shaken_not_stirred = false;
			}
		}
		for (shk = shk->prev; shk != *ls;
				shk = shk->prev)
		{
			if (shk->n < shk->prev->n)
			{
				swap_node_behind(ls, &tl, &shk);
				print_list((const listint_t *)*ls);
				shaken_not_stirred = false;
			}
		}
	}
}
