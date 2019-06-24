#include <stdio.h>

/**
 * sum_multiples - calculate sum of numbers from
 *  0 to @range-1 that are multiples of @fac1 or
 *  @fac2.
 *
 * @range: range of numbers to check
 * @fac1: (will be faster if @fac1 is smaller
 * @fac2: than @fac2)
 * Return: sum
 */
int sum_multiples(int range, int fac1, int fac2)
{
	int sum = 0, i;

	/* Get sum of multiples of fac1 */
	for (i = 0; i < range; i += fac1)
		sum += i;
	/* Add multiples of fac2 */
	for (i = 0; i < range; i += fac2)
		/* Make sure not also multiple of fac1 */
		if (i % fac1)
			sum += i;

	return (sum);
}

/**
 *main-main
 *Return: 0
 */
int main(void)
{
	printf("%d\n", sum_multiples(1024, 3, 5));
	return (0);
}
