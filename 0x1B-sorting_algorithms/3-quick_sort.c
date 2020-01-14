#include "sort.h"

/**
 * swap - swap two indexes in @array, and print the result
 * nothing will happen if @a == @b
 * @array: pointer to start of array
 * @a: a
 * @b: b
 * @len: length of array
 */
static void swap(int *array, size_t a, size_t b, size_t len)
{
	int temp;

	if (a != b)
	{
		temp = array[a];
		array[a] = array[b];
		array[b] = temp;
		print_array(array, len);
	}
}

/**
 * partition - do swaps
 * @array: array
 * @low: first index
 * @high: last index
 * @len: length
 * Return: new pivot I guess
 */
static size_t partition(int *array, size_t low, size_t high, size_t len)
{
	int pivot = array[high];
	size_t i = low, j;

	for (j = low; j <= high; j++)
		if (array[j] < pivot)
		{
			swap(array, i, j, len);
			i++;
		}
	swap(array, i, high, len);
	return (i);
}

/**
 * quicksort_sub - recursive quicksort function
 * @array: array to sort
 * @low: ..
 * @high: ..
 * @len: ..
 */
static void quicksort_sub(int *array, ssize_t low, ssize_t high, size_t len)
{
	ssize_t p;

	if (low < high)
	{
		p = partition(array, low, high, len);
		quicksort_sub(array, low, p - 1, len);
		quicksort_sub(array, p + 1, high, len);
	}
}

/**
 * quick_sort - sort an array using quicksort, and print each step
 * @array: int array
 * @size: number of items
 */
void quick_sort(int *array, size_t size)
{
	quicksort_sub(array, 0, size - 1, size);
}
