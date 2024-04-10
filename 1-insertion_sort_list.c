#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order
 * using the Insertion sort algorithm
 * @list: double pointer to the head of the list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *front, *back, *ptr;

	if (!list || !(*list) || !((*list)->next))
		return;

	front = (*list)->next;

	while (front != NULL)
	{
		back = front;
		front = front->next;
		ptr = back->prev;

		while (ptr != NULL && ptr->n > back->n)
		{
			ptr->next = back->next
			if (back->next != NULL)
				back->next->prev = ptr;

				back->next = ptr;
				back->prev = ptr->prev;
			if  (ptr->prev != NULL)
				ptr->prev->nect = back
			else
				*list = front;
			ptr->prev = back;
			ptr = bac->prev;
		}

	}
}
