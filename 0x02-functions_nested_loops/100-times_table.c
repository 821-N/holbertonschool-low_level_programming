#include <stdio.h>

/**
 * print_times_table - print @n*@n times table
 *
 * @n: size (0 to 15)
 */
void print_times_table(int n)
{
	char x, y;

	if (n < 0 || n > 15)
		return;

	for (y = 0; y <= n; y++)
	{
		putchar('0');
		for (x = 1; x <= n; x++)
			printf(",%4d", x * y);
		putchar('\n');
	}
}
