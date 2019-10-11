#include "hash_tables.h"

/**
 * shash_table_create - create an ordered hash table
 * @size: number of buckets
 * Return: hash table
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *new;
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
	new->shead = NULL;
	new->stail = NULL;

	return (new);
}

/**
 * bucket_search - search for a key in a bucket
 * @bucket: head of linked list
 * @key: key string
 * Return: item, or NULL if not found
 */
static shash_node_t *bucket_search(shash_node_t *bucket, const char *key)
{
	while (bucket)
		if (strcmp(bucket->key, key))
			bucket = bucket->next;
		else
			return (bucket);
	return (NULL);
}

/**
 * sorted_insert - insert item into alphabetically sorted linked list
 * @shead: address of head ptr
 * @stail: address of tail ptr
 * @item: item to insert
 */
static void sorted_insert(shash_node_t **shead, shash_node_t **stail, shash_node_t *item)
{
	shash_node_t *curr;

	if (!*shead)
	{
		item->sprev = NULL;
		item->snext = NULL;
		*shead = item;
		*stail = item;
		return;
	}
	curr = *shead;
	while (curr)
	{
		if (strcmp(curr->key, item->key) > 0) /* w */
		{
			/* [curr->prev] -> <- [item] -> <- [curr] */
			if (curr->sprev)
				curr->sprev->snext = item;
			item->sprev = curr->sprev;
			item->snext = curr;
			curr->sprev = item;

			if (curr == *shead)
				*shead = item;
			return;
		}
		curr = curr->snext;
	}
	(*stail)->snext = item;
	item->sprev = *stail;
	*stail = item;
}

/**
 * bucket_add - add an item to a hash bucket
 * @head: address of head pointer
 * @key: key string
 * @value: value string
 * Return: pointer to new node, or NULL if allocation failed
 */
static shash_node_t *bucket_add(shash_node_t **head, char *key, char *value)
{
	shash_node_t *new = malloc(sizeof(*new));

	if (!new)
		return (NULL);
	new->key = key;
	new->value = value;
	new->next = *head;
	*head = new;

	return (new);
}

/**
 * shash_table_set - add or replace item in sorted hash table
 * (does check for errors)
 * @ht: hash table
 * @key: key string
 * @value: value
 * Return: 1-success, 0-failed
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	shash_node_t *found;
	char *value_copy, *key_copy;

	if (!ht || !key || !value)
		return (0);

	value_copy = strdup(value);
	if (!value_copy)
		return (0);
	index = key_index((const unsigned char *)key, ht->size);
	found = bucket_search(ht->array[index], key);
	if (found)
	{
		free(found->value);
		found->value = value_copy;
	}
	else
	{
		key_copy = strdup(key);
		if (!key_copy)
		{
			free(value_copy);
			return (0);
		}
		found = bucket_add(&(ht->array[index]), key_copy, value_copy);
		if (!found)
		{
			free(value_copy);
			free(key_copy);
			return (0);
		}
		sorted_insert(&(ht->shead), &(ht->stail), found);
	}
	return (1);
}

/**
 * shash_table_get - get item from hash table
 * @ht: hash table
 * @key: key
 * Return: value, or NULL if not found
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index;
	shash_node_t *found;

	if (!ht || !key)
		return (NULL);
	index = key_index((const unsigned char *)key, ht->size);
	found = bucket_search(ht->array[index], key);
	if (found)
		return (found->value);
	return (NULL);
}

/**
 * shash_table_print - print items in alphabetical order by key
 * @ht: hash table
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *curr;
	int printed = 0;

	if (!ht)
		return;
	printf("{");
	curr = ht->shead;
	while (curr)
	{
		if (printed)
			printf(", ");
		printf("'%s': '%s'", curr->key, curr->value);
		curr = curr->snext;
		printed = 1;
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - print items in REVERSE alphabetical order by key
 * @ht: hash table
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *curr;
	int printed = 0;

	if (!ht)
		return;
	printf("{");
	curr = ht->stail;
	while (curr)
	{
		if (printed)
			printf(", ");
		printf("'%s': '%s'", curr->key, curr->value);
		curr = curr->sprev;
		printed = 1;
	}
	printf("}\n");
}

/**
 * shash_table_delete - free hash table
 * @ht: hash table
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *curr, *next;

	if (!ht)
		return;
	curr = ht->shead;
	while (curr)
	{
		next = curr->snext;
		free(curr->key);
		free(curr->value);
		free(curr);
		curr = next;
	}
	free(ht->array);
	free(ht);
}
