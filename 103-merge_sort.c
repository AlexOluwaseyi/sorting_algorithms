#include "sort.h"
/**
 * merge - Merges two sorted subarrays into a single sorted array.
 * @array: The original array containing the subarrays.
 * @size: The size of the original array.
 * @left: The starting index of the left subarray.
 * @mid: The ending index of the left subarray (midpoint).
 * @right: The ending index of the right subarray.
 * @temp: Temporary array for merging.
 */

void merge(int *array, size_t size, size_t left,
		size_t mid, size_t right, int *temp)
{
	size_t i = left, j = mid + 1;
	size_t k = 0, l;

	(void)size;
	printf("Merging...\n[left]: ");
	for (l = left; l <= mid; l++)
	{
		printf("%d", array[l]);
		if (l < mid)
			printf(", ");
	}
	printf("\n[right]: ");
	for (l = mid + 1; l <= right; l++)
	{
		printf("%d", array[l]);
		if (l < right)
			printf(", ");
	}
	printf("\n");
	while (i <= mid && j <= right)
	{
		if (array[i] <= array[j])
			temp[k++] = array[i++];
		else
			temp[k++] = array[j++];
	}
	while (i <= mid)
		temp[k++] = array[i++];
	while (j <= right)
		temp[k++] = array[j++];
	for (k = 0; left <= right; left++, k++)
		array[left] = temp[k];
	printf("[Done]: ");
	for (l = left - k; l <= right; l++)
	{
		printf("%d", array[l]);
		if (l < right)
			printf(", ");
	}
	printf("\n");
}

/**
 * merge_sort_recursive - Recursive function to perform Merge Sort.
 * @array: The array to be sorted.
 * @size: The size of the array.
 * @left: The starting index of the current subarray.
 * @right: The ending index of the current subarray.
 * @temp: Temporary array for merging.
 */
void merge_sort_recursive(int *array, size_t size,
		size_t left, size_t right, int *temp)
{
	size_t mid;

	if (left < right)
	{
		mid = left + (right - left) / 2;

		merge_sort_recursive(array, size, left, mid, temp);
		merge_sort_recursive(array, size, mid + 1, right, temp);

		merge(array, size, left, mid, right, temp);
	}
}

/**
 * merge_sort - Sorts an array of integers in ascending order using Merge Sort.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (array == NULL || size <= 1)
		return;

	temp = malloc(size * sizeof(int));
	if (temp == NULL)
		return;

	merge_sort_recursive(array, size, 0, size - 1, temp);

	free(temp);
}
