#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * counting_sort - Sorts an array of integers in ascending order using the
 *                 Counting sort algorithm
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void counting_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    /* Find the maximum value in the array */
    int max = array[0];
    for (size_t i = 1; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }

    /* Create and initialize the count array with zeros */
    int *count_array = malloc(sizeof(int) * (max + 1));
    if (count_array == NULL)
        return;

    for (int i = 0; i <= max; i++)
        count_array[i] = 0;

    /* Populate the count array with the occurrences of each element */
    for (size_t i = 0; i < size; i++)
        count_array[array[i]]++;

    /* Print the count array */
    print_array(count_array, max + 1);

    /* Update the original array with sorted values using the count array */
    size_t i = 0;
    for (int j = 0; j <= max; j++)
    {
        while (count_array[j] > 0)
        {
            array[i] = j;
            count_array[j]--;
            i++;
        }
    }

    /* Free dynamically allocated memory */
    free(count_array);
}
