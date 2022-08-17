#include "sort.h"

/**
 * quick_sort - it sorts an array using the quick sort algorithm
 * @array: the array to be sorted
 * @size: the size of the array
 * Return: Nothing
 */


void quick_sort(int *array, size_t size)
{
	int i, j, k, track, pivot = 0, sizep = size - 1;

	if (array == NULL || size < 1)
		return;
	pivot = array[sizep];
	for (i = 0; i < (int)size; i++)
	{
		k = -1;
		for (j = 0; j < (int)size; j++)
		{
			if (array[j] > pivot)
				continue;
			if (array[j] < pivot)
			{
				k += 1;
				if (array[j] < array[k])
				{
					track = array[j];
					array[j] = array[k];
					array[k] = track;
					print_array(array, size);
				}
			}
		}
		k += 1;
		if (pivot < array[k])
		{
			track = array[sizep];
			array[sizep] = array[k];
			array[k] = track;
			pivot = array[sizep];
			print_array(array, size);
			i--;
		}
		else if (pivot >= array[k])
		{
			sizep -= 1;
			pivot  = array[sizep];
		}
	}
}
