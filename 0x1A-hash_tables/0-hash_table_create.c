#include "hash_tables.h"

/**
 * hash_table_create - create a new hash table
 * @size: number of buckets
 * Return: pointer to hash table (or NULL if failed)
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *new;
	size_t i;


	/* Allocate */
	if (size <= 0)
		return (NULL);
	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->array = malloc(size * sizeof(*(new->array)));
	if (!new->array)
	{
		free(new);
		return (NULL);
	}
	/* Initialize */
	new->size = size;
	for (i = 0; i < size; i++)
		new->array[i] = NULL;

	return (new);
}
