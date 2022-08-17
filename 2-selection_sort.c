#include "sort.h"

/**
 * selection_sort - it sort an array of integers using
 *			selction sort technique
 * @array: contains the array to be sorted
 * @size: contains the size of the array
 * Return: Nothing
 */

void selection_sort(int *array, size_t size)
{
	int min = 0, index = 0, flag = 0;
	size_t i = 0, j = 0;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < size; i++)
	{
		min = array[i];
		flag = 0;
		for (j = i; j < size; j++)
		{
			if (min > array[j])
			{
				min = array[j];
				index = j;
				flag = 1;
			}
		}
		if (flag == 1)
		{
			array[index] = array[i];
			array[i] = min;
			print_array(array, size);
		}
	}

}
