/**
 * _atoi - ascii to int (copy of atoi)
 *
 * @s: string
 * Return: number
 */
int _atoi(char *s)
{
	char sign = 1;
	int ret = 0;

	for (; *s; s++)
	{
		if (*s == '-')
			sign = -sign;
		else if (*s >= '0' && *s <= '9')
		{
			do {
				ret *= 10;
				ret += (*s++ - '0') * sign;
			} while (*s >= '0' && *s <= '9');
			return (ret);
		}
	}
	return (0);
}
