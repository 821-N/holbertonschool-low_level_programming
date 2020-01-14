#include "hash_tables.h"

/**
 * key_index - return bucket index for a key
 * @key: key
 * @size: number of buckets
 * Return: index
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}
