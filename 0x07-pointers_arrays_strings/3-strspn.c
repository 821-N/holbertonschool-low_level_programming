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
 * _strspn - get length of prefix containing
 *  only chars from @accept
 *
 * @s: string
 * @accept: allowed characters
 * Return: length
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int ret;

	for (ret = 0; _strchr(accept, *s++); ret++)
		;
	return (ret);
}
