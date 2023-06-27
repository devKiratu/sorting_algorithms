#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order using the
 * Shell sort algorithm, implementing the Knuth sequence
 * @array: array of integers to sort
 * @size: size of array
 * Return: void
 */
void shell_sort(int *array, size_t size)
{
	size_t i, interval = 1;

	while (interval <= size / 3)
		interval = interval * 3 + 1;

	while (interval > 0)
	{
		for (i = interval; i < size; i++)
		{
			while (i >= interval && array[i] < array[i - interval])
			{
				swap_elements(array, i, i - interval);
				i -= interval;
			}
		}
		print_array(array, size);
		interval = (interval - 1) / 3;
	}
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
