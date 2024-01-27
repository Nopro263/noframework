#include "string.h"

return_t _new_string_fromChars(char* base, func caller) {
    if(!base) return new_return_error(ERROR_NOT_A_STRING);

    return _new_string_fromSizedChars(base, strlen(base), caller);
}

return_t _new_string_fromSizedChars(char* base, size_t size, func caller) {
    ptr_t p = a_alloc(size, TYPE_STR, caller);
    memcpy(a_getPtr(p), base, size);
    return new_return_value(p);
}

return_t _string_append(ptr_t s1, ptr_t s2, func caller) {

}

return_t _string_reverse(ptr_t s, func caller) {

}
