#include "sort.h"
#include <stdlib.h>

/**
 * insertion_sort_list - it sort a double linked list of integers using
 *						insertion sort algorithm
 * @list: the double linked to be sorted
 * Return: nothing
 */


void insertion_sort_list(listint_t **list)
{
	listint_t *nextN, *prevN, *track;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	nextN = (*list)->next;
	prevN = *list;
	while (nextN)
	{
		track = nextN;
		while (prevN->n > nextN->n)
		{
			/*first swap of link */
			if (prevN->prev == NULL)
				*list = nextN;
			else if (prevN->prev != NULL)
				prevN->prev->next = nextN;
			nextN->prev = prevN->prev;
			/*second swap of link*/
			if (nextN->next != NULL)
				nextN->next->prev = prevN;
			prevN->next = nextN->next;
			/*last swap of link */
			nextN->next = prevN;
			prevN->prev = nextN;

			print_list(*list);
			prevN = nextN->prev;
			if (prevN == NULL)
				break;
		}
		prevN = track;
		nextN = track->next;
	}
}
