#include "holberton.h"

/**
 * print_last_digit - prints last digit of number
 *
 * @n: int
 * Return: last digit of @n (also printed(!))
 */
int print_last_digit(int n)
{
	n = n % 10;
	/* abs(n) % 10 */
	if (n < 0)
		n = -n;
	_putchar('0' + n);
	return (n);
}
