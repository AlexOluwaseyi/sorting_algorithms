#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * counting_sort - Sorts an array of integers in ascending
 * order using Counting Sort.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */

void counting_sort(int *array, size_t size)
{
	int max, i, *count_array, *sorted_array;
	size_t k;

	max = array[0];
	for (k = 1; k < size; k++)
	{
		if (array[k] > max)
			max = array[k];
	}
	count_array = malloc((max + 1) * sizeof(int));
	if (count_array == NULL)
		return;
	for (i = 0; i <= max; i++)
		count_array[i] = 0;
	for (k = 0; k < size; k++)
		count_array[array[k]]++;
	for (i = 1; i <= max; i++)
		count_array[i] += count_array[i - 1];
	for (i = 0; i <= max; i++)
	{
		printf("%d", count_array[i]);
		if (i < max)
			printf(", ");
	}
	printf("\n");
	sorted_array = malloc(size * sizeof(int));
	if (sorted_array == NULL)
		return;
	for (i = max; i >= 0; i--)
	{
		while (count_array[i] > 0)
		{
			sorted_array[count_array[i] - 1] = i;
			count_array[i]--;
		}
	}
	for (k = 0; k < size; k++)
		array[k] = sorted_array[k];
	free(sorted_array);
	free(count_array);
}
