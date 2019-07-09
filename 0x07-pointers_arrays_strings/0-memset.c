/**
 * _memset - fill memory with byte
 *
 * @s: location
 * @b: value to fill with
 * @n: number of bytes to fill
 * Return: @s
 */
char *_memset(char *s, char b, unsigned int n)
{
	char *ret = s;

	while (n-- > 0)
		*s++ = b;

	return (ret);
}
