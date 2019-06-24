#include <stdio.h>

/**
 *main-main
 *Return:0
 */
int main(void)
{
	int i;
	long a = 1, b = 2;

	for (i = 0; i < 50; i++)
	{
		if (i)
			printf(", ");
		printf("%ld", a);
		b += a;
		a = b - a;
	}
	putchar('\n');

	return (0);
}
