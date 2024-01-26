#include "../src/core/allocator.h"

#include <stdio.h>

int main() {
    ptr_t p1 = a_alloc(11, TYPE_STR);
    ptr_t p2 = a_alloc(10, TYPE_STR);

    printf("%p\n", a_getPtr(p1));
    printf("%p\n", a_getPtr(p2));

    memcpy(a_getPtr(p1), "Hello World", 11);
    memcpy(a_getPtr(p2), "Hallo Welt", 10);

    printf("Ptr1: %p\n", a_getPtr(p1));
    printf("Ptr1: %c\n", ((char*)a_getPtr(p1))[0]);

    a_free(p1);
    a_free(p2);

    printf("%p", a_getPtr(p1));
}