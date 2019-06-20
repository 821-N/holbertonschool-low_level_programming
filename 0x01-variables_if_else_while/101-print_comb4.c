#include <stdio.h>

/**
 *main--
 *Return:0
 */
int main(void)
{
	int i, d1, d2, d3;

	for (i = 0; i < 1000; i++)
	{
		d1 = i / 100;
		d2 = i / 10 % 10;
		d3 = i % 10;
		if (d1 < d2 && d2 < d3)
		{
			if (i > 12)
			{
				putchar(',');
				putchar(' ');
			}
			putchar('0' + d1);
			putchar('0' + d2);
			putchar('0' + d3);
		}
	}
	putchar('\n');

	return (0);
}
