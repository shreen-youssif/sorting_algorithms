#include "sort.h"

/**
 * find_max_value - Find the maximum value in an array of integers.
 * @arr: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int find_max_value(int *arr, int size)
{
	int max_value, i;

	for (max_value = arr[0], i = 1; i < size; i++)
	{
		if (arr[i] > max_value)
			max_value = arr[i];
	}

	return (max_value);
}

/**
 * counting_sort - Sort an array of integers in ascending order
 *                 using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the counting array after setting it up.
 */
void counting_sort(int *array, size_t size)
{
	int *count_array, *sorted_array, max_value, i;

	if (array == NULL || size < 2)
		return;

	sorted_array = malloc(sizeof(int) * size);
	if (sorted_array == NULL)
		return;

	max_value = find_max_value(array, size);
	count_array = malloc(sizeof(int) * (max_value + 1));
	if (count_array == NULL)
	{
		free(sorted_array);
		return;
	}

	for (i = 0; i <= max_value; i++)
		count_array[i] = 0;

	for (i = 0; i < (int)size; i++)
		count_array[array[i]] += 1;

	print_array(count_array, max_value + 1);

	for (i = 1; i <= max_value; i++)
		count_array[i] += count_array[i - 1];

	for (i = size - 1; i >= 0; i--)
	{
		sorted_array[count_array[array[i]] - 1] = array[i];
		count_array[array[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = sorted_array[i];

	print_array(array, size);

	free(sorted_array);
	free(count_array);
}
