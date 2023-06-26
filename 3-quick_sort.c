#include "sort.h"

/**
 * quick_sort - sorts an array of integers in ascending order using the
 * Quick sort algorithm and the Lomuto partition scheme
 * @array: array of integers to sort
 * @size: size of the array
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	size_t start = 0, end = size - 1;

	q_sort(array, start, end, size);
}

/**
 * q_sort - recursively sorts two partitions of an array using quick sort
 * @array: the array to sort
 * @start: start index of partition
 * @end: end index of partition
 * @size: size of the array
 * Return: void
 */
void q_sort(int *array, int start, int end, size_t size)
{
	size_t pivot;

	if (start < end)
	{
		pivot = partition(array, start, end, size);
		q_sort(array, start, pivot - 1, size);
		q_sort(array, pivot + 1, end, size);
	}
}

/**
 * partition - partitions the array using Lomuto partition scheme
 * @array: array to partition
 * @start: start index
 * @end: end index
 * @size: size of the array
 * Return: index of the latest element in a sorted position
 */
size_t partition(int *array, int start, int end, size_t size)
{
	int i, j, pivot = end;

	i = start - 1;

	for (j = start; j <= end - 1; j++)
	{
		if (array[j] <= array[pivot])
		{
			i++;
			if (i != j)
			{
				swap_elements(array, i, j);
				print_array(array, size);
			}
		}
	}
	if (i + 1 != end)
	{
		swap_elements(array, i + 1, end);
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * swap_elements - swaps two elements of an integer array
 * @array: array whose elements are being swapped
 * @i: index of the first element
 * @j: index of the second element
 * Return: void
 */
void swap_elements(int *array, size_t i, size_t j)
{
	int temp;

	temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}
