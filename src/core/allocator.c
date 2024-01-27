#include "allocator.h"

ptr_t a_alloc(size_t size, type_t type) {
    struct _I_ll_ pt;
    pt.data = malloc(size);
    pt.size = size;
    pt.uses = 1;
    pt.type = type;
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