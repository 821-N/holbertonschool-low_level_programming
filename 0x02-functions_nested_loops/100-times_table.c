#include <stdio.h>
#include "holberton.h"

/**
 * print_digit - display 1 digit of a number,
 *  unless it is a leading 0
 *
 * @n: number
 * @place: power of 10. Do not use 1.
 */
void print_digit(int n, int place)
{
	if (n >= place)
		_putchar('0' + n / place % 10);
	else
		_putchar(' ');
}

/**
 * print_4_digits - print without leading 0s
 *
 * @n: number to print
 */
void print_4_digits(int n)
{
	print_digit(n, 1000);
	print_digit(n, 100);
	print_digit(n, 10);
	_putchar('0' + n % 10);
}

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
		_putchar('0');
		for (x = 1; x <= n; x++)
		{
			_putchar(',');
			print_4_digits(x * y);
		}
		_putchar('\n');
	}
}
