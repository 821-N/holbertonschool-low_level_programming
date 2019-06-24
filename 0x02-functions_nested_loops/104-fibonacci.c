#include <stdio.h>

/**
 * print_dec11 - print a large number stored as
 *  as two 11-digit doubles.
 *
 * @low: low 11 digits
 * @high: high 11 digits
 */
void print_dec11(double low, double high)
{
	if (high)
		printf("%.0f%0.0f", high, low);
	else
		printf("%.0f", low);
}

/**
 *main-main
 *Return:0
 */
int main(void)
{
	int i;
	double low_a = 1, low_b = 2, low_c;
	double high_a = 0, high_b = 0, high_c;

	for (i = 0; i < 98; i++)
	{
		if (i)
			printf(", ");
		print_dec11(low_a, high_a);
		/* temp = b */
		low_c = low_b;
		high_c = high_b;
		/* b += a */
		low_b += low_a;
		high_b += high_a;
		while (low_b >= 1e11)
		{
			low_b -= 1e11;
			high_b++;
		}
		/* a = temp */
		low_a = low_c;
		high_a = high_c;
	}
	putchar('\n');

	return (0);
}
