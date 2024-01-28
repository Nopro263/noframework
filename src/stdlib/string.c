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
    if(a_getType(s1) != TYPE_STR) return new_return_error(ERROR_NOT_A_STRING);
    if(a_getType(s2) != TYPE_STR) return new_return_error(ERROR_NOT_A_STRING);
    size_t new_size = a_getSize(s1) + a_getSize(s2);
    ptr_t new_string = a_alloc(new_size, TYPE_STR, caller);
    memcpy(a_getPtr(new_string), a_getPtr(s1), a_getSize(s1));
    memcpy(a_getPtr(new_string)+a_getSize(s1), a_getPtr(s2), a_getSize(s2));
    return new_return_value(new_string);
}

return_t _string_reverse(ptr_t s, func caller) {

}
