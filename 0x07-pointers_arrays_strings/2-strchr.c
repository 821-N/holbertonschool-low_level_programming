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
	do
		if (*s == c)
			return (s);
	while (*s++);

	return (NULL);
}
