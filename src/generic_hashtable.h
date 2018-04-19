//
// Created by manparvesh on 19/4/18.
//

#ifndef HASHTABLE_IN_C_GENERIC_HASHTABLE_H
#define HASHTABLE_IN_C_GENERIC_HASHTABLE_H

#define INSERT_PASTER(x, y) insert_ ## x ## _ ## y
#define SEARCH_KEY_PASTER(x, y) search_key_ ## x ## _ ## y
#define DELETE_KEY_PASTER(x, y) delete_key_ ## x ## _ ## y

#define SEARCH_KEY(T, V) SEARCH_KEY_PASTER(T, V)
#define DELETE_KEY(T, V) DELETE_KEY_PASTER(T, V)
#define INSERT(T, V) INSERT_PASTER(T, V)

void SEARCH_KEY (KEY_TYPE, VALUE_NAME)(KEY_TYPE *array, KEY_TYPE key) {

}

void INSERT (KEY_TYPE, VALUE_NAME)(KEY_TYPE *array, KEY_TYPE key, VALUE_TYPE value) {

}

void DELETE_KEY (KEY_TYPE, VALUE_NAME)(KEY_TYPE *array, KEY_TYPE key) {

}

#endif //HASHTABLE_IN_C_GENERIC_HASHTABLE_H
#undef HASHTABLE_IN_C_GENERIC_HASHTABLE_H
