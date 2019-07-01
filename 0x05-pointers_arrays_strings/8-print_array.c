#include <stdio.h>

/**
 * print_array - print integer array separated by
 *  commas.
 *
 * @a: array
 * @n: number of items
 */
void print_array(int *a, int n)
{
	while (n--)
	{
		printf("%d", *a++);
		if (n)
			printf(", ");
	}
	putchar('\n');
}
