#include "sort.h"

/**
 * swap - swaps two items in the arrays
 * @x: pointer to first item to be compared
 * @y: pointer to second item to be compared
 */

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

/**
 * bubble_sort -  Function for bubble sort
 * @array: pointer to unsorted array
 * @size: number of elements in the array
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j, k;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				for (k = 0; k < size; k++)
				{
					printf("%d", array[k]);
					if (k < size - 1)
					{
						printf(", ");
					}
					else
					{
						printf("\n");
					}
				}
			}
		}
	}
}
