#include "hash_tables.h"

/**
 * bucket_add - add an item to a hash bucket
 * @head: address of head pointer
 * @key: key string
 * @value: value string
 * Return: pointer to new node, or NULL if allocation failed
 */
static hash_node_t *bucket_add(hash_node_t **head, char *key, char *value)
{
	hash_node_t *new = malloc(sizeof(*new));

	if (!new)
		return (NULL);
	new->key = key;
	new->value = value;
	new->next = *head;
	*head = new;

	return (new);
}

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
 * hash_table_set - insert a value
 * @ht: hash table
 * @key: key (can't be an empty string)
 * @value: value
 * Return: 1 - success, 0 - failure
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t *find;
	char *value2;

	/* check if any of the inputs are NULL, or key is an empty string */
	if (!ht || !key || !value || key[0] == '\0')
		return (0);
	value2 = strdup(value);
	if (!value2)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	find = bucket_find(ht->array[index], (char *)key);
	if (find)
		find->value = value2;
	else
	{
		find = bucket_add(&(ht->array[index]), (char *)key, value2);
		if (find == NULL)
		{
			free(value2);
			return (0);
		}
	}
	return (1);
}
