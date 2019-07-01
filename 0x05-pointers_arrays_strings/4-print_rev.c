#include "holberton.h"

/**
 * print_rev - print a string backwards, + '\n'
 *
 * @s: string to print
 */
void print_rev(char *s)
{
	char *temp = s;

	/* Move temp to end of string */
	while (*temp)
		temp++;
	/* Print chars backwards until at start */
	while (temp > s)
		_putchar(*--temp);

	_putchar('\n');
}
