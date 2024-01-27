#include "numbers.h"

return_t _new_number_int(long long v, func c) {
    ptr_t p = a_alloc(sizeof(long long), TYPE_NUMBER, c);
    memcpy(a_getPtr(p), &v, sizeof(long long));
    return new_return_value(p);
}

return_t _new_number_float(long double v, func c) {
    ptr_t p = a_alloc(sizeof(long double), TYPE_FLOAT, c);
    memcpy(a_getPtr(p), &v, sizeof(long double));
    return new_return_value(p);
}