/**
 * tr - in @s, replace all chars from @before
 *  with the corresponding char in @after.
 *
 * @s: string to translate
 * @before: chars to replace
 * @after: replacements, same length as @before
 */
void tr(char *s, char *before, char *after)
{
	char *b, *a;

	for (; *s; s++)
		for (b = before, a = after; *b; b++, a++)
			if (*s == *b)
			{
				*s = *a;
				break;
			}
}

/**
 * leet - replace A E O T L with 4 3 0 7 1
 *
 * @s: string
 * Return: @s
 */
char *leet(char *s)
{
	tr(s, "aAeEoOtTlL", "4433007711");
	return (s);
}
