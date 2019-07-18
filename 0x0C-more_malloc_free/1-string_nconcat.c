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
 * strncpy2 - copy n chars from src, to dest.
 *
 * @dest: destination
 * @src: Source. can be NULL if @n is 0.
 * @n: Number of chars to copy.
 */
void strncpy2(char *dest, char *src, unsigned int n)
{

	while (n-- > 0)
		*dest++ = *src++;
}

/**
 * string_nconcat - create a new string containing @s1 and
 *  at most @n chars from @s2
 *
 * @s1: first string
 * @s2: second string
 * @n: number of chars from @s2
 * Return: pointer to new string, or NULL
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	int len1 = strlen2(s1), len2 = strlen2(s2);
	char *new;

	if (n < len2)
		len2 = n;

	new = malloc(len1 + len2 + 1);
	if (!new)
		return (NULL);

	strncpy2(new, s1, len1);
	strncpy2(new + len1, s2, len2);
	new[len1 + len2] = '\0';
	return (new);
}
