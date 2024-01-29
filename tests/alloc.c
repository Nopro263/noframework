#include "../src/core/allocator.h"
#include "../src/stdlib/string.h"
#include "../src/stdlib/numbers.h"
#include "../src/other.h"

#include <stdio.h>

return_t nfmain() {
    ptr_t str = $(str("Hello "));
    printPtr(str);

    ptr_t v = $(int(3));

    ptr_t str2 = $(str("World"));
    printPtr(str2);

    ptr_t str3 = $(string_append(str, str2));
    printPtr(str3);

    //printf("%p", __FUNCTION__);

    endV(v);
}

int main() {
    return_t t;
    t = nfmain();
    if(t.hasValue) {
        if(t.value == -1) {
            printf("\n\nENDED without value\n");
        } else {
            printf("\n\nENDED with value: ");
            __I_printPtr(t.value);
            a_free(t.value);
            printf("\n\n");
        }
    } else {
        printf("ERROR: ");
        printError(t.error);
    }
    if(__a_l_first) {
        perror("Error: unfreed memory\n\n");
        struct _I_ll_* x = __a_l_first;
        printf("%p", x);
    }
}