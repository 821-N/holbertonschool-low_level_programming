#include "holberton.h"

/**
 * puts2 - prints every other character
 *  in @str starting at 0
 *
 * @str: string
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
