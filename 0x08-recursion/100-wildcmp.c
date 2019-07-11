#include <stdio.h>

/**
 * wildcmp - compare a string to a pattern with * wildcards
 *  pattern must match entire string
 *
 * @s: string to test
 * @pat: pattern
 * Return: if match
 */
int wildcmp(char *s, char *pat)
{
	/* printf("comparing %c with %c\n",*s,*pat); */
	if (*pat == '*')
	{
		if (!*s && pat[1])
			return (0);
		/* try ending the wildcard */
		if (wildcmp(s, pat + 1))
			return (1);
		else if (wildcmp(s + 1, pat))
			return (1);
		else
			return (0);
	}

	/* match fails */
	else if (*s != *pat)
		return (0);
	/* reached end of s and pat */
	if (!*s)
		return (1);
	/* next */
	return (wildcmp(s + 1, pat + 1));
}

