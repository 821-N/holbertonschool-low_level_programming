#include <stdio.h>

/**
 * linear_search - search for value using linear search
 * @array: array to search in
 * @size: number of items in @array
 * @value: value to search for
 * Return: first index of @value in @array, or -1 if not found
 */
int linear_search(int *array, size_t size, int value)
{
	size_t i;

	if (array)
		for (i = 0; i < size; i++)
		{
			printf("Value checked array[%ld] = [%d]\n", i, array[i]);
			if (array[i] == value)
				return (i);
		}
	return (-1);
}
