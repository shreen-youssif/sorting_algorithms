#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order using Counting sort
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void counting_sort(int *array, size_t size)
{
    if (array == NULL || size <= 1)
        return;

    /* Find the maximum element in the array */
    int max = array[0];
    for (size_t i = 1; i < size; ++i)
    {
        if (array[i] > max)
            max = array[i];
    }

    /* Create and initialize the counting array */
    int *count = malloc((max + 1) * sizeof(int));
    if (count == NULL)
        return;

    for (int i = 0; i <= max; ++i)
        count[i] = 0;

    /* Count occurrences of each element in the array */
    for (size_t i = 0; i < size; ++i)
        count[array[i]]++;

    /* Update the array with sorted elements */
    size_t j = 0;
    for (int i = 0; i <= max; ++i)
    {
        while (count[i] > 0)
        {
            array[j++] = i;
            count[i]--;
        }
    }

    /* Print the counting array */
    print_array(count, max + 1);

    /* Free the counting array */
    free(count);
}
