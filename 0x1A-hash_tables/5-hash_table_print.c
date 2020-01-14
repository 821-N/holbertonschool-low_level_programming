#include "hash_tables.h"

/**
 * hash_table_print - print a hash table as {'key': 'value', ...}
 * @ht: hash table (can be NULL)
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *bucket;
	int printed = 0;

	if (!ht)
		return;
	printf("{");
	for (i = 0; i < ht->size; i++)
	{
		bucket = ht->array[i];
		while (bucket)
		{
			if (printed)
				printf(", ");
			printf("'%s': '%s'", bucket->key, bucket->value);
			printed = 1;
			bucket = bucket->next;
		}
	}
	printf("}\n");
}
