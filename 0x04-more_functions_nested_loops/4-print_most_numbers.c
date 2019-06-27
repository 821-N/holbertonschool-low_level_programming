#include "holberton.h"

/**
 * print_most_numbers - print 01356789\n (no 2,4)
 */
void print_most_numbers(void)
{
	char c;

	for (c = '0'; c <= '9'; c++)
		if (c != '2' && c != '4')
			_putchar(c);
	_putchar('\n');
}
