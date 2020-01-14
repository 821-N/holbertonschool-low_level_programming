#include <stdio.h>

/**
 * print_region - print section of array
 * @array: array
 * @start: start
 * @end: end (inclusive)
 */
void print_region(int *array, size_t start, size_t end)
{
	size_t i;

	printf("Searching in array: ");
	for (i = start ; i <= end; i++)
	{
		if (i > start)
			printf(", ");
		printf("%d", array[i]);
	}
	printf("\n");
}

/**
 * binary_search - search for a value in a sorted array using binary search
 * @array: array to search in (must be sorted)
 * @size: number of items in @array
 * @value: value to search for
 * Return: index, or -1 if not found
 */
int binary_search(int *array, size_t size, int value)
{
	size_t low = 0, high = size - 1, mid;

	do { /* <3 */
		print_region(array, low, high);
		mid = (low + high) / 2;
		if (array[mid] < value)
			low = mid + 1;
		else if (array[mid] > value)
			high = mid - 1;
		else
			return (mid);
	} while (low <= high);
	return (-1);
}
