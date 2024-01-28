#include "allocator.h"

ptr_t a_alloc(size_t size, type_t type, func caller) {
    struct _I_ll_ pt;
    pt.data = malloc(size);
    pt.size = size;
    pt.uses = 1;
    pt.type = type;
    pt.caller = caller;
    ptr_t i = __a_lAdd(pt);
    return i;
}

void a_realloc(ptr_t p, size_t new_size) {
    struct _I_ll_* pt = __a_lGet(p);
    if(pt) {
        size_t old_size = pt->size;
        pt->size = new_size;
        pt->data = realloc(pt->data, pt->size);
        if(new_size > old_size) {
            memset(pt->data+old_size, 0, new_size-old_size);
        }
        return;
    } else {
        return;
    }
}

size_t a_getSize(ptr_t p) {
    struct _I_ll_* pt = __a_lGet(p);
    if(pt) {
        return pt->size;
    } else {
        return -1;
    }
}

void _a_setCaller(ptr_t p, func caller) {
    struct _I_ll_* pt = __a_lGet(p);
    if(pt) {
        pt->caller = caller;
    }
}

void* a_getPtr(ptr_t p) {
    struct _I_ll_* pt = __a_lGet(p);
    if(pt) {
        return pt->data;
    } else {
        return NULL;
    }
}
type_t a_getType(ptr_t p) {
    struct _I_ll_* pt = __a_lGet(p);
    if(pt) {
        return pt->type;
    } else {
        return TYPE_NONE;
    }
}

size_t a_getSingleSize(ptr_t p) {
    type_t type = a_getType(p);

    switch (type)
    {
    case TYPE_STR:
    case TYPE_OTHER:
        return sizeof(char);
    default:
        return a_getSize(p);
    }
}

return_t a_copySingleElement(ptr_t list, size_t i, void* target) {
    type_t type = a_getType(list);
    switch (type)
    {
        case TYPE_STR: {
            memcpy(target, a_getPtr(list)+i*a_getSingleSize(list), a_getSingleSize(list));
            return new_return_value(-1);
        }
        
        default:
            return new_return_error(ERROR_NOT_A_LIST);
    }
}
return_t a_isList(ptr_t p) {
    type_t type = a_getType(p);
    switch (type)
    {
        case TYPE_STR: case TYPE_OTHER: return new_return_value(-1);
        default: return new_return_error(ERROR_NOT_A_LIST);
    }
}

void a_acquire(ptr_t p) {
    struct _I_ll_* pt = __a_lGet(p);
    if(pt) {
        pt->uses++;
    } else {
        return;
    }
}

void a_free(ptr_t p) {
    struct _I_ll_* pt = __a_lGet(p);
    if(pt) {
        pt->uses--;
        if(!pt->uses) {
            __a_lRemove(p);
        }
    } else {
        return;
    }
}
void a_freeAll(func f) {
    struct _I_ll_* next = __a_l_first;
    while(next) {
        if(next->caller == f) {
            a_free(next->key);
        }
        next = next->next;
    }
}

return_t __I_printPtr(ptr_t p) {
    printf("%lu: ", p);
    switch (a_getType(p))
    {
        case TYPE_FLOAT:
            printf("%Lf", *(long double*)a_getPtr(p));
            break;
        case TYPE_NUMBER:
            printf("%lld", *(long long*)a_getPtr(p));
            break;
        case TYPE_STR: {
            char c;
            foreach(c, p) {
                printf("%c",c);
            }
            break;
        }
        case TYPE_NONE:
            puts("None");
            break;
        case TYPE_OTHER:
            char c;
            foreach(p, c) {
                printf("%x", c);
            }
            break;
        
        default:
            printf("UNKNOWN TYPE\n");
            break;
    }
    printf("\n");
}

void printPtr(ptr_t p) {
    __I_printPtr(p); // Just to use foreach
}

return_t new_return_value(ptr_t value) {
    return_t t;
    t.hasValue = true;
    t.value = value;
    return t;
}
return_t new_return_error(error_t error) {
    return_t t;
    t.hasValue = false;
    t.error = error;
    return t;
}