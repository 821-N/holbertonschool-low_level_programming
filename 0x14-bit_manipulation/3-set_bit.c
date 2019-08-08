/**
 * set_bit - set a bit
 * @n: pointer to number to set bit in
 * @index: position
 * Return: 1 (success) or -1 (failure)
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (!n || 1UL << index == 0)
		return (-1);
	*n |= 1UL << index;
	return (1);
}
