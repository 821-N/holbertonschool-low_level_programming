/**
 * reverse_array - reverses an integer array
 *
 * @a: array
 * @n: length
 */
void reverse_array(int *a, int n)
{
	int temp, *end = a + n - 1;

	while (a < end)
	{
		temp = *a;
		*a++ = *end;
		*end-- = temp;
	}
}
