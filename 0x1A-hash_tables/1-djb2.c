/**
 * hash_djb2 - calculate djb2 hash of string
 * @str: string (can be NULL)
 * Return: hash
 */
unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long hash = 5381;
	int c;

	if (str)
		while ((c = *str++))
			hash = hash * 33 + c;
	return (hash);
}
