#include "sort.h"

/**
 * bubble_sort - A function that sorts an array
 *	of integers in asceending order using
 *	the Bubble Sort algorithm
 * @array: The array to sort
 * @size: The size of the array
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	char tmp;
	int flag = 1;

	if ((array == NULL) || (size < 2))
		return;

	for (i = 0; i < size - 1; i++)
	{
		flag = 0;
		for (j = 0 ; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				print_array(array, size);
				flag = 1;
			}
		}
		if (flag == 0)
			break;
	}
}
