#ifndef INCLUDE_OTHER
#define INCLUDE_OTHER

typedef const void* func;

#define $(A) (__global_return_temp = A).value; if(!__global_return_temp.hasValue) {endE(__global_return_temp.error);} else {_a_setCaller(__global_return_temp.value, __FUNCTION__);}
#define endV(A) a_freeAll(__FUNCTION__, A); return new_return_value(A)
#define endE(A) a_freeAll(__FUNCTION__, -1); return new_return_error(A)
#define end(A) a_freeAll(__FUNCTION__, -1); return A

//#define foreach(V, A) for(size_t i = 0; i < (a_getSize(A) / a_getSingleSize(A)) && ((memcpy(&V, (a_getPtr(A)+i*a_getSingleSize(A)), a_getSingleSize(A))) || true); i++)

#define foreach(V, A) $(a_isList(A)); for(size_t i = 0; i < (a_getSize(A) / a_getSingleSize(A)) && a_copySingleElement(A, i, &V).hasValue; i++)

__thread return_t __global_return_temp;

#define str(A) new_string_fromChars(A)
#define int(A) new_number_int(A)
#define float(A) new_number_float(A)

#endif