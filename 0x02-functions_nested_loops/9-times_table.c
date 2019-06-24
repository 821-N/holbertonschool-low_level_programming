#include "holberton.h"

/**
 * print_2_digits - print 2 digit number
 * (doesn't print leading 0s)
 *
 * @n: number to print
 */
void print_2_digits(char n)
{
	/* print the 10s digit, or a space if 0 */
	_putchar((n / 10) ? '0' + n / 10 : ' ');
	_putchar('0' + n % 10);
}

/**
 * times_table - print 9x9 multiplcation table
 */
void times_table(void)
{
	char x, y;

	for (y = 0; y <= 9; y++)
	{
		_putchar('0');
		for (x = 1; x <= 9; x++)
		{
			_putchar(',');
			_putchar(' ');
			print_2_digits(x * y);
		}
		_putchar('\n');
	}
}
