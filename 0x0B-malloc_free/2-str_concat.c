#include <stdlib.h>

/**
 * strlen2 - get length of string. NULL treated as length 0
 *
 * @s: string
 * Return: length of @s
 */
int strlen2(char *s)
{
	int length;

	if (!s)
		return (0);
	for (length = 0; s[length]; length++)
		;
	return (length);
}

/**
 * strcpy2 - copy a string, not including nul
 *
 * @dest: destination
 * @source: source
 * Return: pointer to end of data in @dest
 */
char *strcpy2(char *dest, char *source)
{
	if (!source)
		return (dest);
	while (*source)
		*dest++ = *source++;
	return (dest);
}

/**
 * str_concat - create a new string containing @s1 and @s2
 *
 * @s1: string 1 (NULL is treated as an empty string)
 * @s2: string 2
 * Return: pointer to a new string, or NULL
 */
char *str_concat(char *s1, char *s2)
{
	int length = 1 + strlen2(s1) + strlen2(s2);
	char *new = malloc(length);
	char *temp;

	if (!new)
		return (NULL);
	temp = strcpy2(new, s1);
	temp = strcpy2(temp, s2);
	*temp = '\0';
	return (new);
}
