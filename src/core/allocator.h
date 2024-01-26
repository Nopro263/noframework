#ifndef INCLUDE_CORE_ALLOCATOR
#define INCLUDE_CORE_ALLOCATOR

#include <stdlib.h>

typedef size_t ptr_t;
typedef enum {
    TYPE_STR,
    TYPE_NUMBER,
    TYPE_FLOAT,

    TYPE_NONE,
    TYPE_OTHER,
} type_t;

#include "linked_list.h"

ptr_t a_alloc(size_t size, type_t type);
void a_realloc(ptr_t p, size_t newsize);
void a_free(ptr_t p);

#include "allocator.c"
#endif