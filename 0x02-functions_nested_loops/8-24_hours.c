#include "holberton.h"

/**
 * print_2_digits - print 2 digit number
 *
 * @n: number to print
 */
void print_2_digits(char n)
{
	_putchar('0' + n / 10);
	_putchar('0' + n % 10);
}

/**
 * jack_bauer - print times from 00:00 to 23:59
 */
void jack_bauer(void)
{
	char hour, minute;

	for (hour = 0; hour < 24; hour++)
		for (minute = 0; minute < 60; minute++)
		{
			print_2_digits(hour);
			_putchar(':');
			print_2_digits(minute);
			_putchar('\n');
		}
}
