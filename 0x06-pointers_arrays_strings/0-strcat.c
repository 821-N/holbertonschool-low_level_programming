/**
 * _strcat - append @src to the end of @dest.
 *  assumes @dest has enough empty space
 *
 * @dest: destination
 * @src: source
 * Return: @dest
 */
char *_strcat(char *dest, char *src)
{
	char *temp = dest;

	/* Find the end of dest */
	while (*temp)
		temp++;
	/* Copy from src */
	do
		/* space required because betty is broken */
		* temp++ = *src++;
	while (*src);

	return (dest);
}


