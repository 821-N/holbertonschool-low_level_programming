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

void strncpy2(char *dest, char *src, unsigned int n)
{
	while(n-- > 0)
		*dest++ = *src++;
}

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
	new[len1+len2] = '\0';
	return (new);
}
