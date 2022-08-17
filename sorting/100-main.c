#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int array[] = {10, 7, 5, 3, 39, 34, 33, 35,35433, 33, 54,80, 30, 90, 40, 50, 70, 2, 1, 0 , 35, 1, 0  , 0, 33, 49, 01, 02, 45};
    size_t n = sizeof(array) / sizeof(array[0]);

    print_array(array, n);
    printf("\n");
    shell_sort(array, n);
    printf("\n");
    print_array(array, n);
    return (0);
}