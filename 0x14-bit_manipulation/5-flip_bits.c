/**
 * flip_bits - return the number of bits that are different
 * @n: number
 * @m: number
 * Return: amount of different bits
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int dif = 0;

	while (n || m)
	{
		dif += (m ^ n) & 1;
		m >>= 1;
		n >>= 1;
	}
	return (dif);
}
