#include <math.h>
#include <stdio.h>

/**
 * largest_prime_factor - returns the largest
 *  prime factor of @n, or 1 if n is prime
 * @n: number to check
 * Return: largest prime factor of @n
 */
long largest_prime_factor(long n)
{
	long div = 2, best = 1;

	while (div <= n)
	{
		/* when a factor is found, divide n and keep track of it. */
		/* div WILL be prime, since if it wasn't, one of */
		/*  its factors would've been found eariler. */
		if (n % div == 0)
		{
			if (div > best)
				best = div;
			n /= div;
			div = 2;
		}
		else
		{
			/* only check odd numbers (and 2) */
			div = (div + 1) | 1;
		}
	}
	return (best);
}

/**
 *main-main
 *Return:0
 */
int main(void)
{
	printf("%ld\n", largest_prime_factor(612852475143));
	return (0);
}
