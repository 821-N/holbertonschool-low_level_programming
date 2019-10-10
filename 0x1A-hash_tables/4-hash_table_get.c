#include "hash_tables.h"

/**
 * bucket_find - look for key in bucket
 * (does not check for NULLs)
 * @bucket: head of linked list
 * @key: key string
 * Return: pointer to node, or NULL if not found
 */
static hash_node_t *bucket_find(hash_node_t *bucket, char *key)
{
	while (bucket)
		if (strcmp(bucket->key, key))
			bucket = bucket->next;
		else
			return (bucket);
	return (NULL);
}

/**
 * hash_table_get - get value from hash table
 * @ht: hash table
 * @key: key
 * Return: value string, or NULL if couldn't be found
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	hash_node_t *item;
	unsigned long int index;

	if (!ht || !key || key[0] == '\0')
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);
	item = bucket_find(ht->array[index], (char *)key);
	if (item)
		return (item->value);
	return (NULL);
}
