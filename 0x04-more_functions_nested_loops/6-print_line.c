#include "holberton.h"

/**
 * print_line - print underscores followed by \n
 *
 * @n: number of underscores to print
 */
void print_line(int n)
{
	while (n-- > 0)
		_putchar('_');
	_putchar('\n');
}
