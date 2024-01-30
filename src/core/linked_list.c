#include "linked_list.h"

#include <stdio.h>

struct _I_ll_* __a_l_first = NULL;
size_t _I_ll_count = 0;


struct _I_ll_* __a_lGet(size_t i) {
    struct _I_ll_* next = __a_l_first;
    while(next && next->key != i) {
        next = next->next;
    }
    return next;
}
struct _I_ll_* __a_lGetLast(size_t* len) {
    struct _I_ll_* next = __a_l_first;
    
    while(next) {
        if(len) {
            (*len)++;
        }

        if(!next->next) {
            return next;
        }
        next = next->next;
        
    }
    return NULL;
}

size_t __a_lAdd(struct _I_ll_ p) {
    size_t len = 0;
    struct _I_ll_* last = __a_lGetLast(&len);
    if(!last) {
        __a_l_first = malloc(sizeof(struct _I_ll_));
        p.next = NULL;
        p.key = _I_ll_count++;
        p.prev = NULL;
        memcpy(__a_l_first, &p, sizeof(struct _I_ll_));
    } else {
        last->next = malloc(sizeof(struct _I_ll_));
        p.next = NULL;
        p.key = _I_ll_count++;
        p.prev = last;
        memcpy(last->next, &p, sizeof(struct _I_ll_));
    }
    return len;
}
void __a_lRemove(size_t i) {
    struct _I_ll_* current = __a_lGet(i);
    struct _I_ll_* prev = NULL;
    if(!current) {return;}
    if(current->prev) {
        prev = current->prev;
        prev->next = current->next;
        if(current->next) {
            current->next->prev = current->prev;
        }
        if(current->onFree) {
            ((_onptr_type*)current->onFree)(current);
        }
        if(current->data) {
            free(current->data);
        }
        free(current);
    } else {
        prev = __a_l_first;
        __a_l_first = __a_l_first->next;
        if(__a_l_first) {
            __a_l_first->prev = NULL;
        }
        if(prev->onFree) {
            ((_onptr_type*)prev->onFree)(prev);
        }
        if(prev->data) {
            free(prev->data);
        }
        free(prev);
    }
}