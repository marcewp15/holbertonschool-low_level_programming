#include "hash_tables.h"
/**
 * hash_table_get - retrieves a value associated with a key
 * @ht: the hash table
 * @key: the key
 *
 * Return: the value associated with the element,
 * or NULL if key couldn’t be found
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned int index;
	hash_node_t *new_node;

	if (ht == NULL || key == NULL || *key == '\0')
	{
		return (NULL);
	}

	index = key_index((const unsigned char *)key, ht->size);

	while (ht->array[index] != NULL)
	{
		new_node = ht->array[index];

		if (strcmp(ht->array[index]->key, key) == 0)
		{
			return (new_node->value);
		}
		new_node = new_node->next;
	}
	return (NULL);
}