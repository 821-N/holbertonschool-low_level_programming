#include <stdlib.h>
#include "sort.h"

/**
 * bubble_sort - sort an array using bubble sort and print each step
 * @array: array to sort
 * @size: length of @array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i;
	int temp;
	char swapped;

	do {
		swapped = 0;
		for (i = 1; i < size; i++)
		{
			if (array[i - 1] > array[i])
			{
				temp = array[i - 1];
				array[i - 1] = array[i];
				array[i] = temp;
				print_array(array, size);
				swapped = 1;
			}
		}
	} while (swapped);
}
