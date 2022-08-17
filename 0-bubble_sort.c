#include "sort.h"

/**
 * bubble_sort - it sort an array of integer in ascending
 *		using bubble sort
 * @array: the array of integer to be sorted
 * @size: the size of the array
 * Return: Nothing of type void
 */

void bubble_sort(int *array, size_t size)
{
	int temp, flag = 0, endflag = 0;
	size_t track = size, i, j;
	if (array == NULL || array[1] == '\0' || array[0] == '\0')
		return;
	for (i = 0; i < size; i++)
	{
		for (j = 1; j < track; j++)
		{
			if (array[j - 1] > array[j])
			{
				if (j + 1 == track)
					endflag = 1;
				flag = 1;
				temp = array[j];
				array[j] = array[j - 1];
				array[j - 1] = temp;
				print_array(array, size);

			}

		}
		if (flag == 0)
			break;
		else if (endflag == 0)
		{
			track -= 2;
			flag = 0;
		}
		else
		{
			track -= 1;
			flag = 0;
			endflag = 0;
		}
	}

}
