#include "sort.h"

/**
 * _swap - swaps two integers
 * @int1: first integer
 * @int2: second integer
 */
void _swap(int *int1, int *int2)
{
	int tmp;

	tmp = *int1;
	*int1 = *int2;
	*int2 = tmp;
}

/**
 * shell_sort - sorts an array of integers using
 *	the Shell Sort algorith based on
 *	the Knuth Sequence (n + 1 = n * 3 + 1 )
 * @array: The array to sort
 * @size: The size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1;
	size_t i, j;

	if (!array || size < 2)
		return;

	while (gap < (size / 3))
	{
		gap = gap * 3 + 1;
	}

	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			for (j = i; j >= gap && array[j - gap] > array[j]; j -= gap)
				_swap(&array[j], &array[j - gap]);
		}
		gap = (gap - 1) / 3;
		print_array(array, size);
	}
}
