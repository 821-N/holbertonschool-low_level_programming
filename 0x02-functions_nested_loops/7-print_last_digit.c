#include "holberton.h"

/**
 * print_last_digit - prints last digit of number
 *
 * @n: int
 * Return: last digit of @n (also printed(!))
 */
int print_last_digit(int n)
{
	/* abs(n) % 10 */
	n = (n >= 0 ? n : -n) % 10;
	_putchar('0' + n);
	return (n);
}
