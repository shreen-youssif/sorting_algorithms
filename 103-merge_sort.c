#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * merge_sort - Sorts an array of integers in ascending order using the
 *              Merge sort algorithm
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void merge_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    merge_sort_recursive(array, 0, size - 1);
}

/**
 * merge_sort_recursive - Recursive function to perform the merge sort
 *
 * @array: The array to be sorted
 * @left: The left index of the sub-array
 * @right: The right index of the sub-array
 */
void merge_sort_recursive(int *array, size_t left, size_t right)
{
    if (left < right)
    {
        size_t middle = left + (right - left) / 2;

        /* Recursively sort the left and right halves */
        merge_sort_recursive(array, left, middle);
        merge_sort_recursive(array, middle + 1, right);

        /* Merge the sorted halves */
        merge(array, left, middle, right);
    }
}

/**
 * merge - Merges two sub-arrays into a single sorted array
 *
 * @array: The array to be sorted
 * @left: The left index of the sub-array
 * @middle: The middle index of the sub-array
 * @right: The right index of the sub-array
 */
void merge(int *array, size_t left, size_t middle, size_t right)
{
    size_t i, j, k;
    size_t n1 = middle - left + 1;
    size_t n2 = right - middle;

    /* Create temporary arrays */
    int *left_array = malloc(sizeof(int) * n1);
    int *right_array = malloc(sizeof(int) * n2);

    if (left_array == NULL || right_array == NULL)
    {
        free(left_array);
        free(right_array);
        return;
    }

    /* Copy data to temporary arrays left_array[] and right_array[] */
    for (i = 0; i < n1; i++)
        left_array[i] = array[left + i];
    for (j = 0; j < n2; j++)
        right_array[j] = array[middle + 1 + j];

    printf("Merging...\n[left]: ");
    print_array(left_array, n1);
    printf("[right]: ");
    print_array(right_array, n2);

    /* Merge the temporary arrays back into array[left, ..., right] */
    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2)
    {
        if (left_array[i] <= right_array[j])
        {
            array[k] = left_array[i];
            i++;
        }
        else
        {
            array[k] = right_array[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of left_array[], if there are any */
    while (i < n1)
    {
        array[k] = left_array[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of right_array[], if there are any */
    while (j < n2)
    {
        array[k] = right_array[j];
        j++;
        k++;
    }

    printf("[Done]: ");
    print_array(array + left, right - left + 1);

    /* Free temporary arrays */
    free(left_array);
    free(right_array);
}
