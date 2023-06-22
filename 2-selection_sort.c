#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order using
 * the Selection sort algorithm
 * @array: integer array to sort
 * @size: size of the array
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	int temp, swap_pos, min;
	size_t i, j;

	for (i = 0; i < size; i++)
	{
		swap_pos = i;
		min = array[i];
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < min)
			{
				min = array[j];
				swap_pos = j;
			}
		}
		if (min != array[i])
		{
			temp = array[i];
			array[i] = min;
			array[swap_pos] = temp;
			print_array(array, size);
		}
	}
}
