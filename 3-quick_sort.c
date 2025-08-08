#include "sort.h"
#include <stddef.h>

/**
 * lomuto_partition - function partitions the array
 * @array: pointer to array
 * @low: start index for partition
 * @high: end index for partition
 * @size: size of array
 *
 * Return: index where pivot ends up
 */

int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low;
	int j;
	int temp;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
			i++;
		}
	}

	if (i != high)
	{
		temp = array[i];
		array[i] = array[high];
		array[high] = temp;
		print_array(array, size);
	}

	return (i);
}

/**
 * quick_sort_recursive - function
 * @array: pointer to array
 * @low: starting index of current sub-array
 * @high: ending index of current sub-array
 * @size: size of array
 *
 * Return: void - nothing
 */

void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	int pivot_index;

	if (low < high)
	{
		pivot_index = lomuto_partition(array, low, high, size);

		quick_sort_recursive(array, low, pivot_index - 1, size);
		quick_sort_recursive(array, pivot_index + 1, high, size);
	}
}

/**
 * quick_sort - function sorts list using Quick Sort
 * @array: pointer to array
 * @size: size of array
 *
 * Return: void - nothing
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}

