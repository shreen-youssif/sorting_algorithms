#include "sort.h"
#include <stdio.h>

/**
 * lomuto_partition - Lomuto partition scheme for Quick Sort
 *
 * @array: The array to be partitioned
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Number of elements in @array
 *
 * Return: Index of the pivot after partitioning
 */
size_t lomuto_partition(int *array, int low, int high, size_t size)
{
    int pivot, temp;
    int i, j;

    pivot = array[high];
    i = low - 1;

    for (j = low; j <= high - 1; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            /* Swap elements and print the array */
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            print_array(array, size);
        }
    }

    /* Swap the pivot to its correct position and print the array */
    temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;
    print_array(array, size);

    return (i + 1);
}

/**
 * lomuto_quick_sort - Recursive function for Lomuto Quick Sort
 *
 * @array: The array to be sorted
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Number of elements in @array
 */
void lomuto_quick_sort(int *array, int low, int high, size_t size)
{
    size_t pivot;

    if (low < high)
    {
        pivot = lomuto_partition(array, low, high, size);

        lomuto_quick_sort(array, low, pivot - 1, size);
        lomuto_quick_sort(array, pivot + 1, high, size);
    }
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 *              using Quick sort (Lomuto partition scheme)
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void quick_sort(int *array, size_t size)
{
    if (!array || size < 2)
        return;

    lomuto_quick_sort(array, 0, size - 1, size);
}
