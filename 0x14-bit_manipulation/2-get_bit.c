/**
 * get_bit - get value of bit at index
 * @n: number
 * @index: index
 * Return: 0 or 1, or -1 if index out of range
 */
int get_bit(unsigned long int n, unsigned int index)
{
	if (1UL << index == 0)
		return (-1);
	return (n >> index & 1);
}
