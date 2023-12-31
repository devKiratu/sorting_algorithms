#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm
 * @list: pointer to the head of a doubly linked list
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *runner;

	if (list == NULL || *list == NULL)
		return;

	runner = *list;

	while (runner->next != NULL)
	{
		while (runner != NULL && runner->n > (runner->next)->n)
		{
			temp = runner->next;
			runner->next = (runner->next)->next;
			if (runner->next != NULL)
				(runner->next)->prev = runner;
			temp->prev = runner->prev;
			if (runner != NULL && runner->prev != NULL)
				(runner->prev)->next = temp;
			else
				*list = temp;
			runner->prev = temp;
			temp->next = runner;
			print_list(*list);
			if (temp->prev != NULL)
				runner = temp->prev;
			else
				runner = temp;
		}
		runner = runner->next;
	}
}
