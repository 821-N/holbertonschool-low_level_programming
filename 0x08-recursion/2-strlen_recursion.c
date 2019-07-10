/**
 * _strlen_recursion - recursive strlen
 *
 * @s: string to find length of
 * Return: length of @s
 */
int _strlen_recursion(char *s)
{
	if (*s)
		return (1 + _strlen_recursion(s + 1));
	return (0);
}
