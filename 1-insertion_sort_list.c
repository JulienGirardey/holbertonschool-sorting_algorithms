#include "sort.h"

/**
* insertion_sort_list - that sorts a doubly linked list of integers in
* ascending order using the Insertion sort algorithm
*
* @list: double pointer to the head of the list
*
* Return: noting
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *insert, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while (current != NULL)
	{
		tmp = current;
		current = current->next;

		while (tmp->prev != NULL && tmp->n < tmp->prev->n)
		{
			insert = tmp->prev;

			if (tmp->next != NULL)
				tmp->next->prev = insert;
			insert->next = tmp->next;
			tmp->next = insert;

			tmp->prev = insert->prev;
			insert->prev = tmp;

			if (tmp->prev != NULL)
				tmp->prev->next = tmp;
			else
				*list = tmp;

			print_list(*list);
		}
	}
}
