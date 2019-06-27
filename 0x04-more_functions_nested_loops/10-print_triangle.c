#include "holberton.h"

/**
 * print_triangle - print triangle using #
 *   #
 *  ##
 * ###
 * @size: width and height of trangle
 */
void print_triangle(int size)
{
	int i, j;

	if (size <= 0)
		_putchar('\n');
	else
		for (j = size - 1; j >= 0; j--)
		{
			for (i = 0; i < j; i++)
				_putchar(' ');
			for (; i < size; i++)
				_putchar('#');
			_putchar('\n');
		}
}
