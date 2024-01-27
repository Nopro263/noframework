#ifndef INCLUDE_OTHER
#define INCLUDE_OTHER

typedef const void* func;

#define $(A) A.value; if(!A.hasValue) {end(A);}
#define endV(A) a_acquire(A); a_freeAll(__FUNCTION__); return new_return_value(A)
#define endE(A) a_freeAll(__FUNCTION__); return new_return_error(A)
#define end(A) a_freeAll(__FUNCTION__); return A

//#define foreach(V, A) for(size_t i = 0; i < (a_getSize(A) / a_getSingleSize(A)) && ((memcpy(&V, (a_getPtr(A)+i*a_getSingleSize(A)), a_getSingleSize(A))) || true); i++)

#define foreach(V, A) $(a_isList(A)); for(size_t i = 0; i < (a_getSize(A) / a_getSingleSize(A)) && a_copySingleElement(A, i, &V).hasValue; i++)
#endif