#include <stdarg.h>
#include <stdio.h>

/**
 * print_numbers - print a list of numbers with
 *  a separator
 *
 * @separator: separator (NULL = none)
 * @n: args
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list valist;
	unsigned int i;

	va_start(valist, n);
	for (i = 0; i < n; i++)
	{
		if (i && separator)
			printf("%s", separator);
		printf("%d", va_arg(valist, int));
	}
	printf("\n");
}
