#include <stdio.h>

/**
 *main--
 *Return:0
 */
int main(void)
{
	int i, j;

	for (j = 0; j < 10; j++)
		for (i = 0; i < 10; i++)
		{
			if (i > j)
			{
				if (j > 0 || i > 1)
				{
					putchar(',');
					putchar(' ');
				}
				putchar('0' + j);
				putchar('0' + i);
			}
		}
	putchar('\n');

	return (0);
}
