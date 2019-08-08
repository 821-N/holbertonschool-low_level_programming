/**
 * binary_to_uint - convert binary string to number
 * @b: binary string
 * Return: value, or 0 if error
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int ret = 0;

	if (!b)
		return (0);

	for (; *b; b++)
	{
		ret <<= 1;
		if (*b == '1')
			ret |= 1;
		else if (*b != '0')
			return (0);
	}
	return (ret);
}
