/**
 * cap_string - capitalizes all words in @in
 *
 * @in: string to capitalize
 * Return: @in
 */
char *cap_string(char *in)
{
	char c, *s;

	if (*in >= 'a' && *in <= 'z')
		*in -= 'a' - 'A';

	for (s = in + 1; *s; s++)
		if (*s >= 'a' && *s <= 'z')
		{
			c = s[-1];
			if (c == ' ' || c == '\t' || c == '\n' ||
					c == ',' || c == ';' || c == '.' ||
					c == '!' || c == '?' || c == '(' ||
					c == ')' || c == '{' || c == '}')
				*s -= 'a' - 'A';
		}

	return (in);
}
