#include "sort.h"

/**
 * shell_sort - it sort an array of integers using shell_sort method
 * @array: the array to be sorted
 * @size: the size of the array
 * Return: Nothing
 */

void shell_sort(int *array, size_t size)
{
	int  j, k, temp;
	int h = 1;

	if (size < 1 || array == NULL)
		return;
	/*find my h */
	while (h < (int)size)
		h = h * 3 + 1;
	h = (h - 1) / 3;

	while (h > 0)
	{
		for (j = 0; j < (int)size / 2; j++)
		{
			for (k = 0; k < ((int)size); k++)
			{
				if (h + k > (int)size - 1)
					break;
				else if (array[k] > array[h + k])
				{
					temp = array[k];
					array[k] = array[h + k];
					array[h + k] = temp;
				}
			}
		}
		print_array(array, size);
		h = (h - 1) / 3;

	}
}
