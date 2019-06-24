#include "holberton.h"

/**
 * print_sign - print the sign of @n (+, 0, -)
 *
 * @n: int
 * Return: the sign of @n (also printed(!))
 */
int print_sign(int n)
{
	int sign = (n > 0) - (n < 0);

	_putchar("-0+"[sign + 1]);
	return (sign);
}
