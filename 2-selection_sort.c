#include "sort.h"

/**
 * swap - swaps two numbers
 * @a: Pointer to first number
 * @b: Pointer to second number
 */

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
/**
 * selection_sort - performs a selection sort on an unsorted array
 * @array: pointer to unsorted array
 * @size: size of the unsorted array
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, k, min_index;

	for (i = 0; i < size - 1; i++)
	{
		min_index = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_index])
			{
				min_index = j;
			}
		}

		if (min_index != i)
		{
			swap(&array[i], &array[min_index]);

			for (k = 0; k < size; k++)
			{
				printf("%d", array[k]);
				if (k < size - 1)
				{
					printf(", ");
				}
			}
			printf("\n");
		}
	}
}
