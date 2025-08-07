#include "sort.h"
#include <stddef.h>

/**
 * swap_nodes - function swaps two adjacent nodes in a list
 * @list: pointer to head of list
 * @left: first node before right
 * @right: second node after left
 *
 * Return: void - nothing
 */

void swap_nodes(listint_t **list, listint_t *left, listint_t *right)
{
	if (left == NULL || right == NULL)
		return;

	if (left->next != right)
		return;

	if (left->prev)
		left->prev->next = right;
	else
		*list = right;

	if (right->next)
		right->next->prev = left;

	left->next = right->next;
	right->prev = left->prev;
	right->next = left;
	left->prev = right;
}


/**
 * insertion_sort_list - function sorts list using Insertion Sort
 * @list: double pointer to list to sort
 *
 * Return: void - nothing
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current;
	listint_t *temp;

	if (list == NULL || *list == NULL)
		return;

	if ((*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		temp = current;

		while (temp->prev != NULL && temp->n < temp->prev->n)
		{
			swap_nodes(list, temp->prev, temp);
			print_list(*list);
		}
		current = current->next;
	}
}

