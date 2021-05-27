#include "../include/library.h"
#include <vector>
#include <cstdio>

#define FUNCTION_DEFINITION(ReturnType) LIB_EXTERN_C ReturnType LIB_CALL

extern "C" struct Vector_int
{
	std::vector<int> Data;
};

FUNCTION_DEFINITION(Vector_int_Handle) Vector_int_Create()
{
	Vector_int_Handle vector = (Vector_int_Handle)malloc(sizeof(Vector_int));
	if (vector)
	{
		new (&vector->Data) std::vector<int>();
	}

	return vector;
}

FUNCTION_DEFINITION(size_t) Vector_int_GetSize(Vector_int_Handle handle)
{
	return handle ? handle->Data.size() : 0;
}

FUNCTION_DEFINITION(LIB_EResult) Vector_int_EmplaceBack(Vector_int_Handle handle, int* data)
{
	if (!handle || !data) return LIB_EResult::LIB_Failed;

	try
	{
		handle->Data.emplace_back(*data);
	}
	catch (...)
	{
		return LIB_EResult::LIB_Failed;
	}

	return LIB_EResult::LIB_Success;
}

FUNCTION_DEFINITION(LIB_EResult) Vector_int_GetData(Vector_int_Handle handle, size_t index, int** data)
{
	if (!handle || !data) return LIB_EResult::LIB_Failed;

	auto& vector = handle->Data;

	if (index > vector.size()) return LIB_EResult::LIB_Failed;

	*data = vector.data() + index;

	return LIB_EResult::LIB_Success;
}

FUNCTION_DEFINITION(LIB_Bool) Vector_int_IsEmpty(Vector_int_Handle handle)
{
	return !handle || handle->Data.empty();
}

FUNCTION_DEFINITION(void) Vector_int_Clear(Vector_int_Handle handle)
{
	if (!handle) return;

	handle->Data.clear();
}

FUNCTION_DEFINITION(void) Vector_int_Destroy(Vector_int_Handle handle)
{
	if (!handle) return;

	handle->Data.~vector<int>();
	free(handle);
}
