#include "sort.h"

void cocktail_sort_list(listint_t **list)
{
	listint_t *temp = NULL, *temp1 = NULL, *prevp, *nextp,  *front, *back;
	int flag = 0;
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	front = (*list)->next;
	while (1)
	{
		while (front != temp)
		{
			nextp = front;
			prevp = front->prev;
			front = front->next;
			if (prevp->n > nextp->n)
			{
				nextp->prev = prevp->prev;
				if (prevp->prev != NULL)
					prevp->prev->next = nextp;
				else
					*list = nextp;
				prevp->next = nextp->next;
				if (nextp->next != NULL)
					nextp->next->prev =prevp;
				nextp->next = prevp;
				prevp->prev = nextp;
				print_list(*list);
				flag = 1;
			}
		}
		temp = prevp;
		back = prevp;
		while (back != temp1)
		{
			nextp = back;
			prevp = back->prev;
			back = back->prev;
			if (prevp == NULL)
				break;
			if (prevp->n > nextp->n)
			{
				if (prevp->prev == NULL)
					*list = nextp;
				else if (prevp->prev != NULL)
					prevp->prev->next = nextp;
				nextp->prev = prevp->prev;
				if (nextp->next != NULL)
					nextp->next->prev = prevp;
				prevp->next = nextp->next;
				nextp->next = prevp;
				prevp->prev = nextp;
				print_list(*list);
				flag = 1;
			}
		}
		temp1 = nextp;
		front = nextp->next;
		if (flag == 0)
			break;
		flag = 0;
	}
}
