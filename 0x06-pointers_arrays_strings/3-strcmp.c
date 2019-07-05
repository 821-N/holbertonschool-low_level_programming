/**
 * _strcmp - Compares strings
 *
 * @s1: string 2
 * @s2: string 1
 * Return: @s1<@s2: -1, @s1==@s2: 0, @s1>@s2: 1
 */
int _strcmp(char *s1, char *s2)
{
	do {
		if (*s1 < *s2)
			return (-1);
		else if (*s1 > *s2)
			return (1);
		s2++;
	} while (*s1++);
	return (0);
}
