#include "cmd.h"

return_t _cmd_input(func caller) {
    ptr_t p = -1;
    ptr_t temp;
    char c;

    while ((c = getchar()) != '\n')
    {
        if(p == -1) {
            p = $(_new_string_fromSizedChars(&c, 1, caller));
        } else {
            temp = $(_new_string_fromSizedChars(&c, 1, caller))
            string_appendIP(p, temp);
            a_free(temp);
        }
    }
    endV(p);
}