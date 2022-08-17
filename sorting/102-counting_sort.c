#include "sort.h"
#include <stdlib.h>

/**
 *  counting - it initalize an array with the cummulative sum of the element
 * @array: the array to use
 * @size: the size of the array
 * Return: the initalized array
 */

int *counting(int *array, size_t size)
{
	int max = 0, max1 = 0, i = 0;
	int *count_array;

	for (i = 0; i < (int)size; i++)
	{
		if (max < array[i])
			max = array[i];
	}
	max1 = max + 1;
	count_array = malloc(sizeof(int) * max1 + 1);
	if (count_array == NULL)
	{
		free(count_array);
		return (NULL);
	}

	for (i = 0; i <= max1 ; i++)
		count_array[i] = 0;
	count_array[i] = '\0';
	for (i = 0; i < (int)size; i++)
		count_array[array[i]] += 1;
	max = 0;
	for (i = 0; i < max1; i++)
	{
		count_array[i] = count_array[i] + max;
		max = count_array[i];
	}
	print_array(count_array, max1);
	return (count_array);
}

/**
 * counting_sort - implementing count sorting algorithm
 * @array: the array to be sorted
 * @size: the size of the array
 * Return: Nothing
 */

void counting_sort(int *array, size_t size)
{
	int max = 0, i = 0;
	int *count_array, *new;

	if (array == NULL || (int)size < 2)
		return;
	count_array = counting(array, size);
	if (count_array == NULL)
		return;
	new = malloc(sizeof(int) * size);
	if (new == NULL)
	{
		free(new);
		return;
	}

	for (i = 0; i < (int)size; i++)
	{
		max = count_array[array[i]];
		max = max - 1;
		while (new[max] == array[i] && array[i] != 0)
			max--;
		new[max] = array[i];
	}
	for (i = 0; i < (int)size; i++)
		array[i] = new[i];
	free(new);
	free(count_array);
}
