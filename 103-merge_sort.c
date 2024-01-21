#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

void merge_sort(int *array, size_t size);
void merge_sort_recursive(int *array, int *copy, size_t start, size_t end);
void merge(int *array, size_t start, size_t middle, size_t end);

/**
 * merge_sort - Sorts an array of integers using the Merge sort algorithm
 *
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void merge_sort(int *array, size_t size)
{
    if (!array || size < 2)
        return;
    
    merge_sort_recursive(array, malloc(sizeof(int) * size), 0, size - 1);
    free(array);
}

/**
 * merge_sort_recursive - Recursively divides and merges the array
 *
 * @array: The array to be sorted
 * @copy: Copy of the array for merging
 * @start: Starting index of the subarray
 * @end: Ending index of the subarray
 */
void merge_sort_recursive(int *array, int *copy, size_t start, size_t end)
{
    if (start < end)
    {
        size_t middle = (start + end) / 2;
        merge_sort_recursive(array, copy, start, middle);
        merge_sort_recursive(array, copy, middle + 1, end);
        merge(array, start, middle, end);
    }
}

/**
 * merge - Merges two sorted subarrays into a single sorted array
 *
 * @array: The array to be sorted
 * @start: Starting index of the first subarray
 * @middle: Ending index of the first subarray
 * @end: Ending index of the second subarray
 */
void merge(int *array, size_t start, size_t middle, size_t end)
{
    size_t i, j, k;
    size_t n1 = middle - start + 1;
    size_t n2 = end - middle;

    int left[n1], right[n2];

    for (i = 0; i < n1; i++)
        left[i] = array[start + i];

    for (j = 0; j < n2; j++)
        right[j] = array[middle + 1 + j];

    i = 0;
    j = 0;
    k = start;

    while (i < n1 && j < n2)
        array[k++] = (left[i] <= right[j]) ? left[i++] : right[j++];

    while (i < n1)
        array[k++] = left[i++];

    while (j < n2)
        array[k++] = right[j++];
}
