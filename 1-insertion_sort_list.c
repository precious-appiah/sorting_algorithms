#include "sort.h"

/**
 * insertion_sort_list- function to perform insertion sort
 * @list: list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *sorted, *next, *temp, *aux;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	current = *list;
	sorted = NULL;
	while (current != NULL)
	{
		next = current->next;
		if (sorted == NULL || sorted->n >= current->n)
		{
			current->next = sorted;
			sorted = current;
		}
		else
		{
			aux = sorted;
			while (aux->next != NULL && aux->next->n <= current->n)
				aux = aux->next;
			if (aux->next == NULL)
			{
				aux->next = current;
				current->prev = aux;
				current->next = NULL;
			}
			else
			{

				temp = aux->next;
				aux->next = current;
				current->prev = aux;
				current->next = temp;
				temp->prev = current;
			}
		}
		current = next;
	}
	*list = sorted;
}
