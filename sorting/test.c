#include "sort.h"

void cocktail_sort_list(listint_t **list)
{
	listint_t *temp = NULL, *temp1, *prevp, *nextp,  *front, *back;
	int flag = 0, flag1 = 2;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	temp1 = (*list)->next;
    front = temp1;
	while (1)
	{
		while (temp1 != temp)
		{
            if (flag1 % 2 == 0)
            {
                nextp = front;
                prevp = front->prev;
                front = front->next;
                temp1 = front;
            }
            else
            {
                nextp = back;
			    prevp = back->prev;
			    back = back->prev;
                temp1 = back;
			    if (prevp == NULL)
				    break;
            }
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
        if (flag1 % 2 == 0)
		{
            temp = prevp;
		    back = prevp;
            flag1 = 1;
            temp1 = back;
        }
       
		
        else if (flag1 % 2 != 0)
        {
            temp = nextp;
		    front = nextp->next;
            temp1 = front;
            flag1 = 2;

        }
		
		if (flag == 0)
			break;
		flag = 1;
	}
}
