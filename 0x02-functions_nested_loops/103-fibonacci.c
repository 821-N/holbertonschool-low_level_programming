#include <stdio.h>

/**
 * sum_even_fibonacci - calculates sum of even
 *  fibonacci numbers, from 2 to @max
 *
 * @max: maximum value of fibonacci number
 * Return: sum
 *
 * Note: every 3rd fibonacci number is even...
 *  But I didn't use this, since mod 2 is simpler
 */
long sum_even_fibonacci(long max)
{
	long a = 1, b = 2, sum = 0;

	while (a <= max)
	{
		if (a % 2 == 0)
			sum += a;
		b += a;
		/* the old value of b is (b - a) */
		a = b - a;
	}

	return (sum);
}

/**
 *main-main
 *Return:0
 */
int main(void)
{
	printf("%ld\n", sum_even_fibonacci(4000000));

	return (0);
}
