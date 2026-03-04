#include <stdlib.h>

#include "chunk.h"
#include "memory.h"

Chunk::Chunk() {
    this->count = 0;
    this->capacity =0;
    this->code = nullptr;
}

void Chunk::reset() {
    this->count = 0;
    this->capacity =0;
    this->code = nullptr;
}

void Chunk::write(uint8_t byte) {
    if (this->capacity < this->count + 1) {
        int oldCapacity = this->capacity;
        this->capacity = GROW_CAPACITY(oldCapacity);
        this->code = GROW_ARRAY(uint8_t, this->code, oldCapacity, this->capacity);
    }

    this->code[this->count] = byte;
    this->count++;
}

void Chunk::free() {
    FREE_ARRAY(uint8_t, this->code, this->capacity);
    this->reset();
}


int Chunk::getCount() {
    return this->count;
}

int Chunk::getCapacity() {
    return this->capacity;
}

uint8_t* Chunk::getCode() {
    return this->code;
}