/**
 * is_prime_sub - prime test. Doesn't work on 1, 0, or -1
 *
 * @n: number to check
 * @div: divisor
 * Return: if @n is prime
 */
int is_prime_sub(int n, int div)
{
	if (div > n / 2 || div < n / -2)
		return (1);
	else if (n % div)
		return (is_prime_sub(n, div + 1));
	else
		return (0);
}

/**
 * is_prime_number - test if number is prime
 *
 * @n: number
 * Return: 1 if @n is prime, otherwise 0
 */
int is_prime_number(int n)
{
	if (n == 1 || n == -1)
		return (0);
	if (n == 0)
		return (1);
	return (is_prime_sub(n, 2));
}
