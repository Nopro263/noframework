#include "linked_list.h"

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
        memcpy(__a_l_first, &p, sizeof(struct _I_ll_));
    } else {
        last->next = malloc(sizeof(struct _I_ll_));
        p.next = NULL;
        p.key = _I_ll_count++;
        memcpy(last->next, &p, sizeof(struct _I_ll_));
    }
    return len;
}
void __a_lRemove(size_t i) {
    struct _I_ll_* current = __a_lGet(i);
    struct _I_ll_* prev = NULL;
    if(!current) {return;}
    if(i) {
        prev = __a_lGet(i-1);
        prev->next = current->next;
        free(current);
    } else {
        prev = __a_l_first;
        __a_l_first = __a_l_first->next;
        free(prev);
    }
}