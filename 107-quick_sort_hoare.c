#include "sort.h"
#include <stdio.h>

/**
 * quick_sort_hoare - Sorts an array of integers in ascending order using
 *                    the Quick sort algorithm (Hoare partition scheme)
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void quick_sort_hoare(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quicksort_hoare(array, 0, size - 1, size);
}

/**
 * quicksort_hoare - Recursive function for Quick sort using Hoare scheme
 *
 * @array: The array to be sorted
 * @low: The starting index of the partition to be sorted
 * @high: The ending index of the partition to be sorted
 * @size: Number of elements in @array
 */
void quicksort_hoare(int *array, int low, int high, size_t size)
{
    if (low < high)
    {
        int pivot = hoare_partition(array, low, high, size);

        quicksort_hoare(array, low, pivot, size);
        quicksort_hoare(array, pivot + 1, high, size);
    }
}

/**
 * hoare_partition - Partitions the array using the Hoare scheme
 *
 * @array: The array to be partitioned
 * @low: The starting index of the partition
 * @high: The ending index of the partition
 * @size: Number of elements in @array
 *
 * Return: The index of the pivot after partitioning
 */
int hoare_partition(int *array, int low, int high, size_t size)
{
    int pivot = array[high];
    int i = low - 1, j = high + 1;

    while (1)
    {
        do
        {
            i++;
        } while (array[i] < pivot);

        do
        {
            j--;
        } while (array[j] > pivot);

        if (i < j)
        {
            swap(&array[i], &array[j]);
            print_array(array, size);
        }
        else
        {
            return j;
        }
    }
}

/**
 * swap - Swaps two elements in an array
 *
 * @a: Pointer to the first element
 * @b: Pointer to the second element
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
