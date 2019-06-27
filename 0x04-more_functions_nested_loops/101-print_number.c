#include "holberton.h"

/**
 * print_number_sub - magic recursive printer
 *
 * @n: number
 */
void print_number_sub(int n)
{
	if (!n)
		return;
	print_number_sub(n / 10);
	n %= 10;
	if (n < 0)
		n = -n;
	_putchar('0' + n);
}

/**
 * print_number - print number
 *
 * @n: number to print
 */
void print_number(int n)
{
	if (n)
	{
		if (n < 0)
			_putchar('-');
		print_number_sub(n);
	}
	else
	{
		_putchar('0');
	}
}
