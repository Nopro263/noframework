#ifndef INCLUDE_CORE_LINKEDLIST
#define INCLUDE_CORE_LINKEDLIST

#include <stdlib.h>
#include <string.h>

struct _I_ll_
{
    void* data;
    size_t size;
    size_t uses;
    size_t key;
    struct _I_ll_* next;
};

struct _I_ll_* _I_getElement(size_t key);
size_t _I_addElement(struct _I_ll_ e);
void _I_removeElement(size_t key);

#include "linked_list.c"
#endif