#ifndef C_INTERFACE_LIBRARY_H
#define C_INTERFACE_LIBRARY_H
#include "library_base.h"

LIB_EXTERN_C typedef struct Vector_int* Vector_int_Handle;
typedef int LIB_Bool;
LIB_ENUM(LIB_EResult,
	LIB_Success,
	LIB_Failed);

LIB_DECLARE_FUNC(Vector_int_Handle) Vector_int_Create();

LIB_DECLARE_FUNC(size_t) Vector_int_GetSize(Vector_int_Handle handle);

LIB_DECLARE_FUNC(LIB_EResult) Vector_int_GetData(Vector_int_Handle handle, size_t index, int** data);

LIB_DECLARE_FUNC(LIB_EResult) Vector_int_EmplaceBack(Vector_int_Handle handle, int* data);

LIB_DECLARE_FUNC(LIB_Bool) Vector_int_IsEmpty(Vector_int_Handle handle);

LIB_DECLARE_FUNC(void) Vector_int_Clear(Vector_int_Handle handle);

LIB_DECLARE_FUNC(void) Vector_int_Destroy(Vector_int_Handle handle);

#endif //C_INTERFACE_LIBRARY_H
