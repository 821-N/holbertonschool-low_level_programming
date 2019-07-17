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
 * argstostr - concat args into a new string, each followed by \n
 *
 * @ac - argc (must be > 0)
 * @av - argv
 * Return: pointer to string, or NULL
 */
char *argstostr(int ac, char **av)
{
	int i, length = 1;
	char *ret, *temp;

	if (ac <= 0 || !av)
		return (NULL);

	for (i = 0; i < ac; i++)
	{
		if (!av[i])
			return (NULL);
		length += 1 + strlen2(av[i]);
	}

	ret = malloc(length);
	if (!ret)
		return (NULL);

	temp = ret;
	for (i = 0; i < ac; i++)
	{
		temp = strcpy2(temp, av[i]);
		*temp++ = '\n';
	}
	*temp = '\0';

	return (ret);
}
