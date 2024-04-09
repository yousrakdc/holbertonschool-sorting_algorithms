#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order
 * @list: double pointer to the head of the list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *front, *back;

	if (!list || !(*list) || !((*list)->next))
		return;

	front = (*list)->next;

	while (front)
	{
		back = front->prev;

		while (back && back->n > front->n)
		{
			if (back->prev)
				back->prev->next = front;
			else
				*list = front;

			front->prev = back->prev;
			back->prev = front;
			back->next = front->next;
			front->next = back;

			if (back->next)
				back->next->prev = back;

			print_list(*list);

			back = front->prev;
		}

		front = front->next;
	}
}
