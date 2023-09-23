#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list in ascending order
 * @list: Pointer to a pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev_node, *next_node;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		next_node = current->next;
		prev_node = current->prev;

		while (prev_node != NULL && prev_node->n > current->n)
		{
			prev_node->next = current->next;
			if (current->next != NULL)
				current->next->prev = prev_node;
			current->next = prev_node;
			current->prev = prev_node->prev;
			prev_node->prev = current;
			if (current->prev != NULL)
				current->prev->next = current;
			else
				*list = current;
			print_list(*list);
			prev_node = current->prev;
		}
		current = next_node;
	}
}
