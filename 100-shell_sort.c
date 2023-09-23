#include "sort.h"

/**
 * shell_sort - function that sorts an array of integers
 * in ascending order using the Shell sort algorithm,
 * using the Knuth sequence.
 *
 * @array: array of integers
 * @size: size of the array.
 */

void shell_sort(int *array, size_t size)
{
	size_t interval;
	int temp;
	size_t i, j;

	interval = 1;

	while (interval <= size / 3)
	{
		interval = interval * 3 + 1;
	}
	while (interval > 0)
	{
		for (i = interval; i < size; i++)
		{
			temp = array[i];
			j = i;
			while (j >= interval && array[j - interval] > temp)
			{
				array[j] = array[j - interval];
				j -= interval;
			}
			array[j] = temp;
		}
		print_array(array, size);

		interval = (size_t)(interval - 1) / 3;
	}
}
