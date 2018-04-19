//
// Created by manparvesh on 19/4/18.
//

#ifndef HASHTABLE_IN_C_HASHTABLE_H
#define HASHTABLE_IN_C_HASHTABLE_H

/**
 * integer keys, different kinds of values
 * */
#define KEY_TYPE int
#define VALUE_TYPE int
#define VALUE_NAME int
#include "generic_hashtable.h"
#undef KEY_TYPE
#undef VALUE_TYPE
#undef VALUE_NAME

#define KEY_TYPE int
#define VALUE_TYPE float
#define VALUE_NAME float
#include "generic_hashtable.h"
#undef KEY_TYPE
#undef VALUE_TYPE
#undef VALUE_NAME

#define KEY_TYPE int
#define VALUE_TYPE double
#define VALUE_NAME double
#include "generic_hashtable.h"
#undef KEY_TYPE
#undef VALUE_TYPE
#undef VALUE_NAME

#define KEY_TYPE int
#define VALUE_TYPE char*
#define VALUE_NAME string
#include "generic_hashtable.h"
#undef KEY_TYPE
#undef VALUE_TYPE
#undef VALUE_NAME

/**
 * string keys, different kinds of values
 * */

#define KEY_TYPE char*
#define VALUE_TYPE int
#define VALUE_NAME int
#include "generic_hashtable.h"
#undef KEY_TYPE
#undef VALUE_TYPE
#undef VALUE_NAME

#define KEY_TYPE char*
#define VALUE_TYPE float
#define VALUE_NAME float
#include "generic_hashtable.h"
#undef KEY_TYPE
#undef VALUE_TYPE
#undef VALUE_NAME

#define KEY_TYPE char*
#define VALUE_TYPE double
#define VALUE_NAME double
#include "generic_hashtable.h"
#undef KEY_TYPE
#undef VALUE_TYPE
#undef VALUE_NAME

#define KEY_TYPE char*
#define VALUE_TYPE char*
#define VALUE_NAME string
#include "generic_hashtable.h"
#undef KEY_TYPE
#undef VALUE_TYPE
#undef VALUE_NAME

#endif //HASHTABLE_IN_C_HASHTABLE_H
