#include <stdio.h>

/**
 *main--
 *Return:0
 */
int main(void)
{
	int i;

	for (i = 0; i < 100; i++)
	{
		if (i)
		{
			putchar(',');
			putchar(' ');
		}
		putchar('0' + i / 10);
		putchar('0' + i % 10);
	}
	putchar('\n');

	return (0);
}
