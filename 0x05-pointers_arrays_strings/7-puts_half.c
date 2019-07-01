#include "holberton.h"

/**
 * puts_half - prints the second half of a string
 *  (rounded down)
 *
 * @str: string to print
 */
void puts_half(char *str)
{
	char *end = str;

	while (*end)
		end++;
	/* add half the length to find the middle */
	str += (end - str + 1) / 2;
	while (*str)
		_putchar(*str++);

	_putchar('\n');
}
