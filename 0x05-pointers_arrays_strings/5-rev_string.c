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
