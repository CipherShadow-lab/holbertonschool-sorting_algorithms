#include "sort.h"
#include <stdbool.h>
#include <stddef.h>


/**
 * swap - function flags whether integers are swapped or not
 * @a: first integer to swap
 * @b: second adjacent integer to swap
 *
 * Return: void - nothing
 */

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * bubble_sort - function sorts array using Bubble Sort
 * @array: list to sort
 * @size: size of array
 *
 * Return: void - nothing
 */

void bubble_sort(int *array, size_t size)
{
	size_t i;
	size_t j;
	bool swapped;

	for (i = 0; i < size - 1; i++)
	{
		swapped = false;

		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				print_array(array, size);
				swapped = true;
			}
		}
		if (swapped == false)
			break;
	}
}
