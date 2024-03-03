#include "sort.h"

/**
 * find_max - find the max element of an array
 * @arr: the array containing values
 * @size: the size of the array
 * Return: the max
 */

int find_max(int *arr, size_t size)
{
	int max = 0;
	size_t i;

	for (i = 0; i < size; i++)
	{
		if (arr[i] >= max)
			max = arr[i];
	}
	return (max);
}

/**
 * counting_table - fills in the counting table
 * @arr: the input array
 * @size: size of input array
 * @count_arr: the counts array to be filled
 * @k: the max element of arr
 *
 */

void counting_table(int *arr, size_t size, int *count_arr, int k)
{
	int num;
	size_t i;

	for (i = 0; i < size; i++)
	{
		num = arr[i];
		count_arr[num] += 1;
	}
	for (i = 1; (int)i <= k; i++)
	{
		count_arr[i] += count_arr[i - 1];
	}
	print_array(count_arr, k + 1);
}

/**
 * counting_sort - sorts an array with the Counting sort algorithm
 * @array: array to sort
 * @size: size of the array
 */

void counting_sort(int *array, size_t size)
{
	int k, i, *count_arr, *output_arr;

	if (size < 2 || !array)
		return;
	/*find max*/
	k = find_max(array, size);
	/* create counter table*/
	count_arr = malloc(sizeof(size_t) * (k + 1));
	if (!count_arr)
		return;

	output_arr = malloc(sizeof(size_t) * size);

	if (!output_arr)
	{
		free(count_arr);
		return;
	}
	for (i = 0; i <= k; i++)
	{
		count_arr[i] = 0;
	}
	for (i = 0; i < (int)size; i++)
	{
		output_arr[i] = 0;
	}

	/* fill counter table with accurance count if each index*/
	counting_table(array, size, count_arr, k);

	/*created output array and fill*/
	for (i = 0; i < (int)size; i++)
	{
		output_arr[count_arr[array[i]] - 1] = array[i];
		count_arr[array[i]]--;
	}

	/*copy output array to input array*/
	for (i = 0; i < (int)size; i++)
		array[i] = output_arr[i];

	free(count_arr);
	free(output_arr);
}
