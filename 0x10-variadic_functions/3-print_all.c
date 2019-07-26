#include <stdarg.h>
#include <stdio.h>

/**
 * comma - print comma if condition is true
 *
 * @needed: condition
 */
void comma(int needed)
{
	if (needed)
		printf(", ");
}

/**
 * print_all - print list of values of any type
 *
 * @format: list of types
 */
void print_all(const char * const format, ...)
{
	int i = 0, last = 0;
	va_list valist;
	char *str;

	va_start(valist, format);

	while (format[i])
	{
		switch (format[i])
		{
		case 'c':
			comma(last);
			printf("%c", va_arg(valist, int));
			last = 1;
			break;
		case 'i':
			comma(last);
			printf("%d", va_arg(valist, int));
			last = 1;
			break;
		case 'f':
			comma(last);
			printf("%f", va_arg(valist, double));
			last = 1;
			break;
		case 's':
			comma(last);
			str = va_arg(valist, char *);
			if (!str)
				str = "nil";
			printf("%s", str);
			last = 1;
		}
		i++;
	}
	va_end(valist);
	printf("\n");
}
