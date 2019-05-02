#include "hashtable-simple.h"

static ht_item HT_DELETED_ITEM = {NULL, NULL};

static ht_item *ht_new_item(const char *key, const char *value)
{
    ht_item *item = malloc(sizeof(ht_item));
    item->key = strdup(key);
    item->value = strdup(value);
    return item;
}

ht_hash_table *ht_new()
{
    ht_hash_table *new_hashtable = malloc(sizeof(ht_hash_table));
    new_hashtable->size = 53;
    new_hashtable->count = 0;
    new_hashtable->items = calloc((size_t)new_hashtable->size, sizeof(ht_item *));
    return new_hashtable;
}

static void ht_delete_item(ht_item *item)
{
    free(item->key);
    free(item->value);
    free(item);
}

void ht_delete_hashtable(ht_hash_table *ht)
{
    for (int i = 0; i < ht->size; i++)
    {
        ht_item *item = ht->items[i];
        if (item != NULL)
        {
            ht_delete_item(item);
        }
    }
    free(ht->items);
    free(ht);
}

static int ht_hash(const char *s, const int a, const int num_brackets)
{
    long hash = 0;
    const int length_s = strlen(s);
    for (int i = 0; i < length_s; i++)
    {
        hash += (long)pow(a, length_s - (i + 1)) * s[i];
        hash = hash % num_brackets;
    }
    return (int)hash;
}

static int ht_get_hash(const char *s, const int num_buckets, const int attempt)
{
    const int hash_a = ht_hash(s, HT_PRIME_1, num_buckets);
    const int hash_b = ht_hash(s, HT_PRIME_2, num_buckets);
    return (hash_a + (attempt * (hash_b + 1))) % num_buckets;
}

// search in hashtable
char *ht_search(ht_hash_table *hashtable, const char *key)
{
    int index = ht_get_hash(key, hashtable->size, 0);
    ht_item *item = hashtable->items[index];
    int i = 1;
    while (item != NULL)
    {
        if (item != &HT_DELETED_ITEM && strcmp(item->key, key) == 0)
        {
            return item->value;
        }
        index = ht_get_hash(key, hashtable->size, i);
        item = hashtable->items[index];
        i++;
    }

    return NULL;
}

// insert key:value in hashtable
int ht_insert(ht_hash_table *hashtable, const char *key, const char *value)
{
    ht_item *item = ht_new_item(key, value);
    int index = ht_get_hash(item->key, hashtable->size, 0);
    ht_item *current_item = hashtable->items[index];
    int i = 1;
    while (current_item != NULL && current_item != &HT_DELETED_ITEM)
    {
        if (strcmp(current_item->key, key) == 0)
        {
            ht_delete_item(current_item);
            hashtable->items[index] = item;
            return -1;
        }
        index = ht_get_hash(item->key, hashtable->size, i);
        current_item = hashtable->items[index];
        i++;
    }

    hashtable->items[index] = item;
    hashtable->count++;

    return 0;
}

// delete key from hashtable
int ht_delete(ht_hash_table *hashtable, const char *key)
{
    int index = ht_get_hash(key, hashtable->size, 0);
    ht_item *item = hashtable->items[index];
    int i = 1;
    while (item != NULL)
    {
        if (item != &HT_DELETED_ITEM)
        {
            if (strcmp(item->key, key) == 0)
            {
                ht_delete_item(item);
                hashtable->items[index] = &HT_DELETED_ITEM;
            }
        }
        index = ht_get_hash(key, hashtable->size, i);
        item = hashtable->items[index];
        i++;
    }
    hashtable->count--;
    return 0;
}
