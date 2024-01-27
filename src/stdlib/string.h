#ifndef INCLUDE_STDLIB_STRING
#define INCLUDE_STDLIB_STRING

#include "../core/allocator.h"

return_t _new_string_fromChars(char* base, func);
#define new_string_fromChars(A) _new_string_fromChars(A, __FUNCTION__)

return_t _new_string_fromSizedChars(char* base, size_t size, func);
#define new_string_fromSizedChars(A, B) _new_string_fromChars(A, B, __FUNCTION__)

return_t _string_append(ptr_t s1, ptr_t s2, func);
#define string_append(A, B) _string_append(A, B, __FUNCTION__)

return_t _string_reverse(ptr_t s, func);
#define string_reverse(A) _string_reverse(A, __FUNCTION__)

#include "string.c"
#endif