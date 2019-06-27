#include "holberton.h"

/**
 * more_numbers - print numbers 0-14, ten times
 */
void more_numbers(void)
{
	char i, j;

	for (j = 0; j < 10; j++)
	{
		for (i = 0; i <= 14; i++)
		{
			if (i >= 10)
				/* assuming i < 20 */
				_putchar('1');
			_putchar('0' + i % 10);
		}
		_putchar('\n');
	}
}
