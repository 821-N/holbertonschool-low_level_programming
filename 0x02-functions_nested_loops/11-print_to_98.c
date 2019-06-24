#include <stdio.h>

/**
 * print_to_98 - print numbers from @n to 98
 *
 * @n: (can be greater than 98)
 */
void print_to_98(int n)
{
	char direction = (n > 98) ? -1 : 1;

	for (; n != 98; n += direction)
		printf("%d, ", n);
	printf("98\n");
}
