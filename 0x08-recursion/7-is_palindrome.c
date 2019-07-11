/**
 * is_palindrome_sub - check if string is palindrome
 *
 * @s: string (not need to be nul-terminated)
 * @len: length of @s
 * Return: whether @s is a palindrome
 */
int is_palindrome_sub(char *s, int len)
{
	if (len < 2)
		return (1);
	else if (s[0] != s[len - 1])
		return (0);
	else
		return (is_palindrome_sub(s + 1, len - 2));
}

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

/**
 * is_palindrome - check if string is palindrome
 *
 * @s: string
 * Return: whether @s is a palindrome
 */
int is_palindrome(char *s)
{
	return (is_palindrome_sub(s, _strlen_recursion(s)));
}
