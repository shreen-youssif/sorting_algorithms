#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order using the
 *                 Counting sort algorithm
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void counting_sort(int *array, size_t size)
{
    int *count_array, *output;
    int max_value = 0;
    size_t i;

    if (array == NULL || size < 2)
        return;

    /* Find the maximum value in the array */
    for (i = 0; i < size; i++)
    {
        if (array[i] > max_value)
            max_value = array[i];
    }

    /* Allocate memory for count_array */
    count_array = malloc(sizeof(int) * (max_value + 1));
    if (!count_array)
        return;

    /* Initialize count_array to 0 */
    for (i = 0; i <= (size_t)max_value; i++)
        count_array[i] = 0;

    /* Count occurrences of each element in the input array */
    for (i = 0; i < size; i++)
        count_array[array[i]]++;

    /* Print count_array */
    printf("0");
    for (i = 1; i <= (size_t)max_value; i++)
        printf(", %d", count_array[i]);
    printf("\n");

    /* Update count_array to store the actual position of each element */
    for (i = 1; i <= (size_t)max_value; i++)
        count_array[i] += count_array[i - 1];

    /* Allocate memory for the output array */
    output = malloc(sizeof(int) * size);
    if (!output)
    {
        free(count_array);
        return;
    }

    /* Build the output array */
    for (i = size - 1; i < size; i--)
    {
        output[count_array[array[i]] - 1] = array[i];
        count_array[array[i]]--;
    }

    /* Copy the sorted output array back to the original array */
    for (i = 0; i < size; i++)
        array[i] = output[i];

    /* Print the sorted array */
    print_array(array, size);

    /* Free allocated memory */
    free(count_array);
    free(output);
}
