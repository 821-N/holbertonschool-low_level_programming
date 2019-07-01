/**
 * _strcpy - strcpy
 *
 * @dest: destination
 * @src: source
 * Return: @dest
 */
char *_strcpy(char *dest, char *src)
{
	char *ret = dest;

	while ((*dest++ = *src++)) /* = not == ! */
		;
	return (ret);
}

