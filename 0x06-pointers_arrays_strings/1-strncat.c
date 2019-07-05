/**
 * _strncat - Append at most @n chars of @src to
 *  the end of @dest. Assumes @dest has enough
 *  empty space
 *
 * @dest: destination
 * @src: source
 * @n: maximum bytes to copy
 * Return: @dest
 */
char *_strncat(char *dest, char *src, int n)
{
	char *temp = dest;

	/* Find the end of dest */
	while (*temp)
		temp++;
	/* Copy from src */
	while (n--)
	{
		*temp++ = *src;
		if (!(*src++))
			break;
	}

	return (dest);
}


