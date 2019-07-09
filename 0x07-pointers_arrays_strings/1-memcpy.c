/**
 * _memcpy - memcpy
 *
 * @dest: destination
 * @src: source
 * @n: number of bytes
 * Return: @dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	char *ret = dest;

	while (n-- > 0)
		*dest++ = *src++;

	return (ret);
}
