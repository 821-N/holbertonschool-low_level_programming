#include <stdio.h>

/**
 *main-main
 *Return:0
 */
int main(void)
{
	int i;
	long a = 1, b = 2, c;

	for (i = 0; i < 50; i++)
	{
		if (i)
			printf(", ");
		printf("%ld", a);
		c = b;
		b += a;
		a = c;
	}
	putchar('\n');

	return (0);
}
