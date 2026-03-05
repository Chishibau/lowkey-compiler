#pragma once

#include "common.h"

// helper macro to determine new capacity of array
#define GROW_CAPACITY(capacity) \
    ((capacity) < 8 ? 8 : (capacity) * 2)

// helper macro to increase size of array
#define GROW_ARRAY(type, pointer, oldCount, newCount) \
    (type*)reallocate(pointer, sizeof(type) * (oldCount), sizeof(type) * (newCount))

// helper macro to free allocated memory of array
#define FREE_ARRAY(type, pointer, oldCount) \
    (type*)reallocate(pointer, sizeof(type) * (oldCount), 0)

// helper fn to free allocated memory of array
void* reallocate(void* pointer, size_t oldSize, size_t newSize);