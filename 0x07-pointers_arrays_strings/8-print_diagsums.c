#include <stdio.h>

/**
 * print_diagsums - print sums of diagonals
 *  in a square array
 *
 * @a: array
 * @size: side length
 */
void print_diagsums(int *a, int size)
{
	int sum1 = 0, sum2 = 0;
	int i;

	for (i = 0; i < size; i++)
	{
		sum1 += a[i * (size + 1)];
		sum2 += a[size - 1 + i * (size - 1)];
	}

	printf("%d, %d\n", sum1, sum2);
}
