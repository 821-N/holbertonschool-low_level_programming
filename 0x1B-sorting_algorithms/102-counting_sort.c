#include "sort.h"
#include <stdlib.h>

/**
 * totals - calculate running totals of list
 * @counts: list
 * @len: length of counts
 * yes these arg types are correct lol
 */
static void totals(int *counts, int len)
{
	int i;
	int total = 0;

	for (i = 0; i < len; i++)
	{
		total += counts[i];
		counts[i] = total;
	}
}

/**
 * counting_sort - <3
 * @array: array to sort (must not have negatives even though it's signed...)
 * @size: number of items in @array
 */
void counting_sort(int *array, size_t size)
{
	size_t i;
	int k, j;
	int max;
	int *counts;

	if (size < 2)
		return;
	max = array[0];
	for (i = 1; i < size; i++)
		if (array[i] > max)
			max = array[i];

	counts = malloc((max + 1) * sizeof(int));
	if (!counts)
		return;
	for (k = 0; k <= max; k++)
		counts[k] = 0;

	for (i = 0; i < size; i++)
		counts[array[i]]++;

	for (k = 0; k <= max; k++)
		for (j = 0; j < counts[k]; j++)
			*array++ = k;

	totals(counts, max + 1);
	print_array(counts, max + 1);

	free(counts);
}
