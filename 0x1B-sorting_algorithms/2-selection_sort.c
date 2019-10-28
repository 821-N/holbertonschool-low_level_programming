#include "sort.h"
#include <limits.h>

/**
 * find_min - return pointer to smallest item in array
 * @array: array
 * @size: don't pass 0, silly
 * Return: pointer to smallest item
 */
static int *find_min(int *array, size_t size)
{
	int *min = array++;

	while (--size)
	{
		if (*array < *min)
			min = array;
		array++;
	}
	return (min);
}

/**
 * selection_sort - sort an array using selection sort and print each step
 * @array: array to sort
 * @size: length of @array
 */
void selection_sort(int *array, size_t size)
{
	size_t remain = size;
	int temp, *min, *pos = array;

	while (remain > 1)
	{
		min = find_min(pos, remain--);
		if (pos != min)
		{
			temp = *min;
			*min = *pos;
			*pos = temp;
			print_array(array, size);
		}
		pos++;
	}
}
