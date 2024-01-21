#include "sort.h"
#include <stdio.h>

/**
 * bitonic_sort - Sorts an array of integers in ascending order using
 *                the Bitonic sort algorithm
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void bitonic_sort(int *array, size_t size)
{
    if (size < 2)
        return;

    bitonic_sort_recursive(array, size, 1);
}

/**
 * bitonic_sort_recursive - Recursively performs Bitonic sort
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 * @dir: The direction of the sorting (1 for ascending, 0 for descending)
 */
void bitonic_sort_recursive(int *array, size_t size, int dir)
{
    if (size > 1)
    {
        size_t k = size / 2;
        printf("Merging [%lu/%lu] (%s):\n", k, size, dir ? "UP" : "DOWN");
        print_array(array, size);
        bitonic_sort_recursive(array, k, 1);
        bitonic_sort_recursive(array + k, k, 0);
        bitonic_merge(array, size, dir);
        printf("Result [%lu/%lu] (%s):\n", k, size, dir ? "UP" : "DOWN");
        print_array(array, size);
    }
}

/**
 * bitonic_merge - Merges two halves of the array
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 * @dir: The direction of the sorting (1 for ascending, 0 for descending)
 */
void bitonic_merge(int *array, size_t size, int dir)
{
    if (size > 1)
    {
        size_t k = size / 2;
        bitonic_compare(array, k, dir);
        bitonic_merge(array, k, dir);
        bitonic_merge(array + k, k, dir);
    }
}

/**
 * bitonic_compare - Compares and swaps elements to achieve the Bitonic property
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 * @dir: The direction of the sorting (1 for ascending, 0 for descending)
 */
void bitonic_compare(int *array, size_t size, int dir)
{
    size_t i, j;
    int tmp;

    for (i = 0; i < size / 2; i++)
    {
        if ((array[i] > array[i + size / 2]) == dir)
        {
            tmp = array[i];
            array[i] = array[i + size / 2];
            array[i + size / 2] = tmp;
            printf("Swap: %d with %d\n", array[i], array[i + size / 2]);
        }
    }
}
