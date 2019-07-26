#include <stdarg.h>

/**
 * sum_them_all - calculate sum of all arguments
 *
 * @n: args
 * Return: sum of args
 */
int sum_them_all(const unsigned int n, ...)
{
	va_list valist;
	unsigned int i;
	int sum = 0;

	va_start(valist, n);
	for (i = 0; i < n; i++)
		sum += va_arg(valist, int);

	va_end(valist);
	return (sum);
}
