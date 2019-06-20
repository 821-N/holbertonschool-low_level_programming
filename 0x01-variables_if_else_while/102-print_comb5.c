#include <stdio.h>

/**
 *main--
 *Return:0
 */
int main(void)
{
	int i, j;

	for (i = 0; i < 100; i++)
	{
		for (j = i + 1; j < 100; j++)
		{
			if (i != 0 || j != 1)
			{
				putchar(',');
				putchar(' ');
			}
			putchar('0' + i / 10);
			putchar('0' + i % 10);
			putchar(' ');
			putchar('0' + j / 10);
			putchar('0' + j % 10);
		}
	}
	putchar('\n');

	return (0);
}
