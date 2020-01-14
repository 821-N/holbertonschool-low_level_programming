#include "hash_tables.h"

/**
 * hash_table_delete - free hash table
 * @ht: table to free
 */
void hash_table_delete(hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *bucket, *next;

	if (!ht)
		return;
	for (i = 0; i < ht->size; i++)
	{
		bucket = ht->array[i];
		while (bucket)
		{
			next = bucket->next;
			free(bucket->key);
			free(bucket->value);
			free(bucket);
			bucket = next;
		}
	}
	free(ht->array);
	free(ht);
	/* free(omiwa) */
}
