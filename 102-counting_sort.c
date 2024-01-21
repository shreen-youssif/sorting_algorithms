#include "sort.h"
/**
 * counting_sort - Sorts an array of integers using the Counting sort algorithm
 *
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void counting_sort(int *array, size_t size)
{
	int *count_array, *output;
	size_t i, max = 0;

	if (!array || size < 2)
		return;
	for (i = 0; i < size; i++)
	{
		if ((size_t)array[i] > max)
			max = array[i];
	}
	count_array = malloc(sizeof(int) * (max + 1));
	if (!count_array)
		return;
	for (i = 0; i <= max; i++)
		count_array[i] = 0;
	for (i = 0; i < size; i++)
		count_array[array[i]]++;
	print_array(count_array, max + 1);
	for (i = 1; i <= max; i++)
		count_array[i] += count_array[i - 1];
	output = malloc(sizeof(int) * size);
	if (!output)
	{
		free(count_array);
		return;
	}
	for (i = size - 1; i < size; i--)
	{
		output[count_array[array[i]] - 1] = array[i];
		count_array[array[i]]--;
	}
	for (i = 0; i < size; i++)
		array[i] = output[i];
	free(count_array);
	free(output);
}
