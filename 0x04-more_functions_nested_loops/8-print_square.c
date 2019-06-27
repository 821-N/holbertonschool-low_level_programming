#include "holberton.h"

/**
 * print_square - print square of '#'s
 *
 * @size: width and height of square
 */
void print_square(int size)
{
	int i, j;

	if (size <= 0)
		_putchar('\n');
	else
		for (j = 0; j < size; j++)
		{
			for (i = 0; i < size; i++)
				_putchar('#');
			_putchar('\n');
		}
}
