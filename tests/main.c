#include "hashtable-simple.h"

int main()
{
    ht_hash_table *hashtable = ht_new();
    ht_delete_hashtable(hashtable);
    return 0;
}