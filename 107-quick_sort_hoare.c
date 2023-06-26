#include "sort.h"

/**
 * quick_sort_hoare - sorts an array of integers in ascending order using the
 * Quick sort algorithm and Hoare's partitioning scheme
 * @array: array of integers to sort
 * @size: size of the array
 * Return: void
 */
void quick_sort_hoare(int *array, size_t size)
{
	q_sort_hoare(array, 0, size - 1, size);
}

/**
 * q_sort_hoare - recursive function for performing quick sort
 * @array: array to partition
 * @start: start index
 * @end: end index
 * @size: size of the array
 * Return: void
 */
void q_sort_hoare(int *array, int start, int end, size_t size)
{
	size_t pivot;

	if (start < end)
	{
		pivot = partition_hoare(array, start, end, size);
		q_sort_hoare(array, start, pivot - 1, size);
		q_sort_hoare(array, pivot, end, size);
	}
}

/**
 * partition_hoare - partitions an array using Hoare's partition scheme
 * @array: array to partition
 * @start: start index
 * @end: end index
 * @size: size of the array
 * Return: pivot index
 */
size_t partition_hoare(int *array, int start, int end, size_t size)
{
	int i = start - 1, j = end + 1;

	while (i < j)
	{
		do {
			i++;
		} while (array[i] < array[end]);

		do {
			j--;
		} while (array[j] > array[end]);

		if (i < j)
		{
			swap_elements(array, i, j);
			print_array(array, size);
		}
	}
	return (i);
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
