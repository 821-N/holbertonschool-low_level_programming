/**
 * factorial - calculates the factorial of a number
 *
 * @n: number
 * Return: factorial of @n, or -1 if @n is less than 0
 */
int factorial(int n)
{
	if (n < 0)
		return (-1);
	else if (n <= 1)
		return (1);
	else
		return (n * factorial(n - 1));
}
