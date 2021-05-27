//
// Created by bryanwong on 27/05/2021.
//
#include <library.h>

int main()
{
	int array[] = { 1,2,3,4,5,6,7};
	Vector_int_Handle vector = Vector_int_Create();
	assert(vector);
	assert(!Vector_int_GetSize(vector));
	assert(Vector_int_IsEmpty(vector));
	for (int i = 0; i < 7; ++i)
	{
		Vector_int_EmplaceBack(vector, array + i);
	}

	for (int i = 0; i < 7; ++i)
	{
		int* value = NULL;
		Vector_int_GetData(vector, i, &value);
		assert(value && array[i] == *value);
	}

	Vector_int_Destroy(vector);

	return 0;
}
