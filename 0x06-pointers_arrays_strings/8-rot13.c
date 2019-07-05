#include <stdio.h>

/**
 * rot13 - encode a string using rot13
 *
 * @s: string to encode
 * Return: @s
 */
char *rot13(char *s)
{
	char c, *ret = s;

	for (; (c = *s); s++)
		if ((c >= 'A' && c <= 'Z') ||
				(c >= 'a' && c <= 'z'))
			/* ASCII */
			*s = (((c & ~(1 << 5)) - 'A' + 13)
				% 26 + 'A') | (c & 1 << 5);
	return (ret);
}
