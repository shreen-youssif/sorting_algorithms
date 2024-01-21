#include "sort.h"
#include <stdio.h>

/**
 * shell_sort - Sorts an array of integers in ascending order
 *               using the Shell sort algorithm with Knuth sequence
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void shell_sort(int *array, size_t size)
{
    size_t gap = 1, i, j;
    int temp;

    if (!array || size < 2)
        return;

    /* Calculate the initial gap using Knuth sequence */
    while (gap < size / 3)
        gap = gap * 3 + 1;

    /* Perform Shell sort with decreasing gaps from Knuth sequence */
    while (gap > 0)
    {
        for (i = gap; i < size; i++)
        {
            temp = array[i];
            j = i;

            while (j >= gap && array[j - gap] > temp)
            {
                /* Swap elements and print the array */
                array[j] = array[j - gap];
                j -= gap;
                print_array(array, size);
            }

            array[j] = temp;
        }

        /* Calculate the next gap using Knuth sequence */
        gap /= 3;
    }
}
