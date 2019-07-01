#include "holberton.h"

/**
 * puts2 - prints every other character
 *  starting at 0
 */
void puts2(char *str)
{
	while (*str)
	{
		_putchar(*str++);
		if (!*str++)
			break;
	}
	_putchar('\n');
}
