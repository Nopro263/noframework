#ifndef INCLUDE_NUMBERS
#define INCLUDE_NUMBERS

#include "../core/allocator.h"

return_t _new_number_int(long long v, func);
#define new_number_int(A) _new_number_int(A, __FUNCTION__)

return_t _new_number_float(long double v, func);
#define new_number_float(A) _new_number_float(A, __FUNCTION__)

#include "numbers.c"
#endif