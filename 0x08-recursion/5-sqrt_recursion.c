/**
 * find_sqrt - recursive loop to find square root
 *
 * @n: number to find square root of
 * @root: root to test
 * Return: square root of @n, or -1
 */
int find_sqrt(int n, int root)
{
	int square = root * root;

	if (square < n)
		return (find_sqrt(n, root + 1));
	else if (square > n)
		return (-1);
	else
		return (root);
}

/**
 * _sqrt_recursion - calculate square root of perfect squares
 *
 * @n: number
 * Return: square root of @n, or -1 if @n is not a square
 */
int _sqrt_recursion(int n)
{
	return (find_sqrt(n, 0));
}
