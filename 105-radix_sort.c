#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * radix_sort - Sorts an array of integers in ascending order using
 *              the LSD Radix sort algorithm
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void radix_sort(int *array, size_t size)
{
    int max = getMax(array, size);

    /* Do counting sort for every digit */
    for (int exp = 1; max / exp > 0; exp *= 10)
    {
        counting_sort(array, size, exp);
        print_array(array, size);
    }
}

/**
 * counting_sort - Counting sort algorithm for LSD Radix sort
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 * @exp: The current digit being processed
 */
void counting_sort(int *array, size_t size, int exp)
{
    int *output = malloc(sizeof(int) * size);
    int count[10] = {0};

    if (!output)
        return;

    /* Store count of occurrences in count[] */
    for (size_t i = 0; i < size; i++)
        count[(array[i] / exp) % 10]++;

    /* Change count[i] so that count[i] now contains actual
     position of this digit in output[] */
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    /* Build the output array */
    for (int i = size - 1; i >= 0; i--)
    {
        output[count[(array[i] / exp) % 10] - 1] = array[i];
        count[(array[i] / exp) % 10]--;
    }

    /* Copy the output array to array[], so that array[] now
     contains sorted numbers according to the current digit */
    for (size_t i = 0; i < size; i++)
        array[i] = output[i];

    free(output);
}

/**
 * getMax - Finds the maximum value in an array
 *
 * @array: The array to find the maximum value
 * @size: Number of elements in @array
 * Return: The maximum value in @array
 */
int getMax(int *array, size_t size)
{
    int max = array[0];
    for (size_t i = 1; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }
    return max;
}
