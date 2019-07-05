/**
 * _strncpy - Copy at most @n bytes from @src
 *  to @dest. Assumes @dest has enough space
 *
 * @src: source
 * @dest: destination
 * @n: max length of data to copy
 * Return: @dest
 */
char *_strncpy(char *dest, char *src, int n)
{
	char *temp = dest;

	while (n-- > 0)
	{
		*temp++ = *src;
		if (*src)
			src++;
	}
	return dest;
}


