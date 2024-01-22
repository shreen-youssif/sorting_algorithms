#include "sort.h"

/**
 * merge_sort - Sorts an array of integers in ascending order using the
 *              Merge sort algorithm
 *
 * @arr: The array to be sorted
 * @size: Number of elements in @arr
 */
void merge_sort(int *arr, size_t size)
{
	int *temp_array;
	size_t i;

	if (arr == NULL || size < 2)
		return;

	temp_array = malloc(sizeof(int) * size);
	if (!temp_array)
		return;

	for (i = 0; i < size; i++)
		temp_array[i] = arr[i];

	recursive_merge(temp_array, 0, size, arr);
	free(temp_array);
}

/**
 * recursive_merge - Recursive function to perform the merge sort
 *
 * @arr: The array to be sorted
 * @left: The left index of the sub-array
 * @right: The right index of the sub-array
 * @result: The result array to store the sorted elements
 */
void recursive_merge(int *arr, size_t left, size_t right, int *result)
{
	size_t middle;

	middle = (left + right) / 2;
	if (right - left < 2)
		return;

	recursive_merge(result, left, middle, arr);
	recursive_merge(result, middle, right, arr);
	merge_arrays(arr, left, right, result);
}

/**
 * merge_arrays - Merges two sub-arrays into a single sorted array
 *
 * @arr: The array to be sorted
 * @left: The left index of the sub-array
 * @right: The right index of the sub-array
 * @result: The result array to store the sorted elements
 */
void merge_arrays(int *arr, size_t left, size_t right, int *result)
{
	size_t i = left, j, k, middle;

	j = middle = (left + right) / 2;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(arr + left, middle - left);
 	printf("[right]: ");
	print_array(arr + middle, right - middle);

	for (k = left; k < right; k++)
	{
		if (i < middle && (j >= right || arr[i] <= arr[j]))
		{
			result[k] = arr[i++];
		}
		else
		{
			result[k] = arr[j++];
		}
	}

	printf("[Done]: ");
	print_array(result + left, right - left);
}
