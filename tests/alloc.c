#include "../src/core/allocator.h"
#include "../src/stdlib/string.h"
#include "../src/stdlib/numbers.h"
#include "../src/other.h"

#include <stdio.h>

return_t nfmain() {
    return_t t;
    t = new_string_fromChars("Hello World");
    ptr_t str = $(t);

    char c;
    foreach(c, str) {
        printf("%c", c);
    }

    t = new_number_int(3);
    ptr_t v = $(t);
    printPtr(v);
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
            //a_free(t.value);
            printf("\n\n");
        }
    } else {
        printf("EROR: %d", t.error);
    }
    if(__a_l_first) {
        perror("Error: unfreed memory\n\n");
        asm("int3");
    }
}