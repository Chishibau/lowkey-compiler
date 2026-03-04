#include <stdlib.h>

#include "memory.h"

void* reallocate(void* pointer, size_t oldSize, size_t newSize) {
    // free memory if newSize is 0
    if (newSize == 0) {
        delete(pointer);
        return nullptr;
    }

    void* result = realloc(pointer, newSize);
    // check if there isn't enough memory for realloc
    if (result == nullptr) exit(1);

    return result;
}