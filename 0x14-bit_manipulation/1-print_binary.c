#include "holberton.h"

/**
 * print_binary - print a number in binary
 * @n: number to print
 */
void print_binary(unsigned long int n)
{
	unsigned long int y;

	if (n)
		for (y = 1L << 63; !(y & n); y >>= 1)
			;
	else
		y = 1;

	while (y)
	{
		_putchar('0' + !!(n & y));
		y >>= 1;
	}
	_putchar('\n');
}
