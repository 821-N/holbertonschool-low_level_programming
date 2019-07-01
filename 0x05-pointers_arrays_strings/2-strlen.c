/**
 * _strlen - get length of nul-terminated string
 *
 * @s: string
 * Return: length of @s
 */
int _strlen(char *s)
{
	int length = 0;

	while (*s++)
		length++;
	return (length);
}
