#ifndef INCLUDE_CORE_ALLOCATOR
#define INCLUDE_CORE_ALLOCATOR

#include <stdlib.h>
#include <stdbool.h>
#include "error.h"

typedef size_t ptr_t;
typedef enum {
    TYPE_STR,
    TYPE_NUMBER,
    TYPE_FLOAT,

    TYPE_NONE,
    TYPE_OTHER,
} type_t;

typedef enum {
    ERROR_NOT_A_STRING = 0,
    ERROR_NOT_A_LIST = 1,
} error_t;

typedef struct {
    bool hasValue;
    ptr_t value;
    error_t error;
} return_t;

#include "linked_list.h"

ptr_t a_alloc(size_t size, type_t type, func caller);
void a_realloc(ptr_t p, size_t newsize);
void a_free(ptr_t p);

return_t new_return_value(ptr_t value);
return_t new_return_error(error_t error);

#include "allocator.c"
#endif