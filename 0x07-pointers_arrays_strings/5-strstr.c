#include <stdlib.h>

/**
 * checkmatch - check if @small matches at @big
 *
 * @small: string to check for
 * @big: location to check at
 * Return: if match
 */
int checkmatch(char *big, char *small)
{
	for (; *small; small++)
		if (*big++ != *small)
			return (0);
	return (1);
}

/**
 * _strstr - search for substring in string
 *
 * @haystack: string to search in
 * @needle: string to search for
 * Return: pointer in @haystack, or NULL
 */
char *_strstr(char *haystack, char *needle)
{
	for (; *haystack; haystack++)
		if (checkmatch(haystack, needle))
			return (haystack);
	return (NULL);
}
