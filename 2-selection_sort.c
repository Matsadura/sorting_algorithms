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
 * selection_sort - Sorts an array of integers
 *	in ascending order using
 *	the Selection Sort Algorithm
 * @array: The array to sort
 * @size: The size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, tmp;
		
		if ((array) == NULL || size < 2)
			return;
				
				for (i = 0; i < size - 1; i++)
				{
					tmp = i;
						for (j = i + 1; j < size ; j++)
						{
							if (array[tmp] > array[j])
							{
								tmp = j;
							}
						}
					if (tmp != i)
					{
						_swap(array + i, array + tmp);
							print_array(array, size);
					}
				}
}

