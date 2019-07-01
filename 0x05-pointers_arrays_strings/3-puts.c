#include "holberton.h"

/**
 * _puts - prints a string + '\n'
 *
 * @str: string to print
 */
void _puts(char *str)
{
	for (; *str; str++)
		_putchar(*str);
	_putchar('\n');
}

