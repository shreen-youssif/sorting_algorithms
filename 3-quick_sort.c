#include "sort.h"

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
size_t lomuto_partition(int *array, ssize_t low, ssize_t high, size_t size)
{
	int pivot;
	int i, j;

	pivot = array[high];
	i = low - 1;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			swap(array, size, &array[j], &array[i++]);
		}
	}
	swap(array, size, &array[i], &array[high]);

	return (i);
}

/**
 * lomuto_quick_sort - Recursive function for Lomuto Quick Sort
 *
 * @array: The array to be sorted
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Number of elements in @array
 */
void lomuto_quick_sort(int *array, ssize_t low, ssize_t high, size_t size)
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
	if (!array || !size)
		return;
	lomuto_quick_sort(array, 0, size - 1, size);
}
/**
 * swap - swap tow integers
 * @array: integer array to be sotred
 * @Size: array size
 * @a: first value address
 * @b: second value address
 *
*/
void swap(int *array, size_t size, int *a, int *b)
{
	if (*a != *b)
	{
		*a = *a + *b;
		*b = *a - *b;
		*a = *a - *b;
		print_array((const  int *)array, size);
	}
}
