#include "../src/core/allocator.h"
#include "../src/stdlib/string.h"
#include "../src/stdlib/numbers.h"
#include "../src/other.h"

#include <stdio.h>

return_t nfmain() {
    ptr_t str = $(new_string_fromChars("Hello "));
    printPtr(str);

    ptr_t str2 = $(new_string_fromChars("World"));
    printPtr(str2);

    ptr_t str3 = $(string_append(str, str2));
    printPtr(str3);

    ptr_t v = $(new_number_int(3));
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
        printf("EROR: %d", t.error);
    }
    if(__a_l_first) {
        perror("Error: unfreed memory\n\n");
        struct _I_ll_* x = __a_l_first;
        printf("%p", x);
    }
}