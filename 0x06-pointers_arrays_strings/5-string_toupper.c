/**
 * string_toupper - convert chars to uppercase
 *
 * @s: string
 * Return: @s
 */
char *string_toupper(char *s)
{
	char *temp = s;

	while (*temp)
	{
		if (*temp >= 'a' && *temp <= 'z')
			*temp = *temp - ('a' - 'A');
		temp++;
	}

	return (s);
}
