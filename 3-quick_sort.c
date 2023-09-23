#include "sort.h"

/**
 * lomuto - Partition function based on Lomuto scheme.
 *
 * @array: Array of integers.
 * @low: Starting index for partitioning.
 * @high: Ending index for partitioning.
 * @size: Size of the array.
 *
 * Return: Index of the pivot element.
 */
int lomuto(int *array, int low, int high, size_t size)
{
	int i, j, swap;

	i = low - 1;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < array[high])
		{
			i++;
			if (i != j)
			{
				swap = array[i];
				array[i] = array[j];
				array[j] = swap;
				print_array(array, size);
			}
		}
	}

	if (i + 1 != high)
	{
		swap = array[i + 1];
		array[i + 1] = array[high];
		array[high] = swap;
		print_array(array, size);
	}

	return (i + 1);
}

/**
 * quicksort - Recursive function to perform Quick Sort.
 *
 * @array: Array of integers.
 * @low: Starting index for sorting.
 * @high: Ending index for sorting.
 * @size: Size of the array.
 */
void quicksort(int *array, int low, int high, size_t size)
{
	int pivot_idx;

	if (low < high)
	{
		pivot_idx = lomuto(array, low, high, size);

		quicksort(array, low, pivot_idx - 1, size);
		quicksort(array, pivot_idx + 1, high, size);
	}
}

/**
 * quick_sort -  function that sorts an array of integers
 * in ascending order using the Quick sort algorithm
 * with Lomuto partition scheme.
 *
 * @array: array of integers.
 * @size: size of array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;
	quicksort(array, 0, size - 1, size);
}
