/**
 * get_endianness - check endianness
 * Return: 1 = LE, 0 = BE
 */
int get_endianness(void)
{
	int x = 1;

	return (*(char *)&x);
}
