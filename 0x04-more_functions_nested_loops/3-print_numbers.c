#include "holberton.h"

/**
 * print_numbers - print 0123456789\n
 */
void print_numbers(void)
{
	char i;

	for (i = '0'; i <= '9'; i++)
		_putchar(i);
	_putchar('\n');
}
