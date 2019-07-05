/**
 * rev_string - reverse a string (in place)
 *
 * @s: string to reverse
 */
void rev_string(char *s)
{
	char temp, *end = s;

	while (*end)
		end++;
	end--;

	while (s < end)
	{
		temp = *s;
		*s = *end;
		*end = temp;
		s++;
		end--;
	}
}

/**
 * infinite_add - add numbers in decimal strings
 *
 * @n1: number 1
 * @n2: number 2
 * @r: sum output
 * @size_r: length of @r
 * Return: @r
 */
char *infinite_add(char *n1, char *n2,
									 char *r, int size_r)
{
	char *s1 = n1, *s2 = n2, *sr = r;
	char d1, d2, sum, carry = 0;

	/* move pointers to end of strings */
	while (*n1)
		n1++;
	while (*n2)
		n2++;

	while (n1 > s1 || n2 > s2 || carry)
	{
		if (--size_r < 1)
			return (0);

		d1 = n1 > s1 ? *--n1 - '0' : 0;
		d2 = n2 > s2 ? *--n2 - '0' : 0;

		sum = carry + d1 + d2;
		carry = sum / 10;
		sum %= 10;

		*r++ = '0' + sum;
	}

	*r = '\0';

	rev_string(sr);

	return (sr);
}
