#ifndef HASHTABLE_IN_C_SIMPLE_H
#define HASHTABLE_IN_C_SIMPLE_H

#include <stdlib.h>
#include <string.h>
#include <math.h>

static const int HT_PRIME_1 = 151;
static const int HT_PRIME_2 = 163;

typedef struct
{
    char *key;
    char *value;
} ht_item;

typedef struct
{
    int size;
    int count;
    ht_item **items;
} ht_hash_table;

ht_hash_table *ht_new();
void ht_delete_hashtable(ht_hash_table *ht);

// search in hashtable
char *ht_search(ht_hash_table *hashtable, const char *key);
// insert key:value in hashtable
int ht_insert(ht_hash_table *hashtable, const char *key, const char *value);
// delete key from hashtable
int ht_delete(ht_hash_table *hashtable, const char *key);

#endif //HASHTABLE_IN_C_SIMPLE_H
