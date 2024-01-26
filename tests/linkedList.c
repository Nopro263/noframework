#include "../src/core/linked_list.h"

#include <stdio.h>

int main() {
    struct _I_ll_ p;
    p.data = "test";

    __a_lAdd(p);
    p = *__a_lGetLast(NULL);
    printf("%s", p.data);
    __a_lRemove(0);
    printf("%p", __a_lGetLast(NULL));
}