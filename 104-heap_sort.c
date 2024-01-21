#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * heap_sort - Sorts an array of integers in ascending order using the
 *             Heap sort algorithm
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void heap_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    /* Build a max heap */
    build_max_heap(array, size);

    /* Extract elements from the heap one by one */
    for (int i = size - 1; i > 0; i--)
    {
        /* Swap the root (maximum value) with the last element */
        swap(&array[0], &array[i]);

        /* Heapify the reduced heap */
        heapify(array, i, 0);
    }
}

/**
 * build_max_heap - Builds a max heap from an array
 *
 * @array: The array to be transformed into a max heap
 * @size: Number of elements in @array
 */
void build_max_heap(int *array, size_t size)
{
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(array, size, i);
}

/**
 * heapify - Heapifies a subtree rooted with the given root
 *
 * @array: The array to be heapified
 * @size: Number of elements in @array
 * @root: The index of the root of the subtree
 */
void heapify(int *array, size_t size, int root)
{
    int largest = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    /* If the left child is larger than the root */
    if (left < size && array[left] > array[largest])
        largest = left;

    /* If the right child is larger than the current largest */
    if (right < size && array[right] > array[largest])
        largest = right;

    /* If the largest is not the root, swap and recursively heapify */
    if (largest != root)
    {
        swap(&array[root], &array[largest]);
        print_array(array, size);
        heapify(array, size, largest);
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
