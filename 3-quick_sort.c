#include "sort.h"

/**
 * _swap - swaps two integers
 * @arr: array of ints
 * @size: size of the array
 * @int1: first integer
 * @int2: second integer
 */
void _swap(int *arr, size_t size, int *int1, int *int2)
{
	int tmp;
		
		tmp = *int1;
		*int1 = *int2;
		*int2 = tmp;
		
		print_array(arr, size);
}

/**
 * _sort - Applying the Lomuto Partition scheme
 * @arr: array of ints
 * @size: size of the array
 * @left: left side of the partition
 * @right: right side of the partition
 * Return: the pivot index
 */
size_t _sort(int *arr, size_t size, size_t left, size_t right)
{
	size_t piv;
		size_t i, j;
		
		piv = right;
		i = j = left;
		for (j = i; j < piv; j++)
		{
			if (arr[j] <= arr[piv])
			{
				if (j != i)
				{
					_swap(arr, size, &arr[i], &arr[j]);
				}
				i++;
			}
		}
	if (i != right)
		_swap(arr, size, &arr[i], &arr[piv]);
			return (i);
}

/**
 * q_sort_wrap - wrapper
 *    using the Quick Sort algorithm
 *    based on the Lomuto partition scheme
 * @array: The array to sort
 * @size: The size of the array
 * @left: begining of partition
 * @right: end of partition
 */
void q_sort_wrap(int *array, size_t size, size_t left, size_t right)
{
	size_t pivot;
		
		if (left < right)
		{
			pivot = _sort(array, size, left, right);
				if (pivot > 0)
					q_sort_wrap(array, size, left, pivot - 1);
						q_sort_wrap(array, size, pivot + 1, right);
		}
}

/**
 * quick_sort - Sorts an array of itnegers
 *    using the Quick Sort algorithm
 *    based on the Lomuto partition scheme
 * @array: The array to sort
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
	
		if (!array || size < 2)
			return;
				
				q_sort_wrap(array, size, 0, size - 1);
}
