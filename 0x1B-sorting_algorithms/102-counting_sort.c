#include "sort.h"
#include <string.h>
#include <stdio.h>

/**
 * print_totals - print running totals of list
 * @counts: list
 * @len: length of counts
 * yes these arg types are correct lol
 */
static void print_totals(size_t *counts, int len)
{
	int i;
	size_t total = 0;

	for (i = 0; i < len; i++)
	{
		total += counts[i];
		if (i)
			printf(", ");
		printf("%ld", total);
	}
	printf("\n");
}

/**
 * counting_sort - <3
 * @array: array to sort (must not have negatives even though it's signed...)
 * @size: number of items in @array
 */
void counting_sort(int *array, size_t size)
{
	size_t i, j;
	int max = array[0];
	size_t *counts;

	for (i = 1; i < size; i++)
		if (array[i] > max)
			max = array[i];

	counts = malloc(max + 1);

	if (!counts)
		return;
	memset(counts, 0, (max + 1) * sizeof(size_t));

	for (i = 0; i < size; i++)
		counts[array[i]]++;
	print_totals(counts, max + 1);

	for (i = 0; i <= max; i++)
		for (j = 0; j < counts[i]; j++)
			*array++ = i;

	free(counts);
}
