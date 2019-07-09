#include <stdlib.h>

/**
 * _strchr - search for char in string
 *
 * @s: string
 * @c: character
 * Return: pointer in @s, or NULL
 */
char *_strchr(char *s, char c)
{
	for (; *s; s++)
		if (*s == c)
			return (s);
	return (NULL);
}

/**
 * _strpbrk - search @s for any char in @accept
 *
 * @s: string to search in
 * @accept: string of chars to search for
 * Return: pointer in @s, or NULL
 */
char *_strpbrk(char *s, char *accept)
{
	for (; *s; s++)
		if (_strchr(accept, *s))
			return (s);
	return (NULL);
}
